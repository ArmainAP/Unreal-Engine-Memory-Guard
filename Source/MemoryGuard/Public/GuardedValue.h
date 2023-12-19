// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Logging.h"
#include "Misc/AES.h"
#include "ThirdParty/picosha2.h"

template <typename T>
struct FGuardedValue
{
private:
    FString Value;
    FString Signature;

public:
	FGuardedValue()
	{
		SetValue(T());
	}
	
	FGuardedValue(const T& NewValue)
	{
		SetValue(NewValue);
	}
	
	T GetValue() const
	{
		T Result{};

		TArray<uint8> DecodedData; 
		if (!FBase64::Decode(Value, DecodedData))
		{
			UE_LOG(MemoryGuardLog, Error, TEXT("Guarded value failed decode!"));
			return Result;
		}

		FAES::DecryptData(DecodedData.GetData(), DecodedData.Num(), reinterpret_cast<const uint8*>(TCHAR_TO_ANSI(*Signature)), FAES::FAESKey::KeySize);
		const FString DecodedSignature = HashData(DecodedData);
		if(Signature != DecodedSignature)
		{
			UE_LOG(MemoryGuardLog, Error, TEXT("Guarded value signature mismatch!"));
			return Result;
		}

		// Remove padding
		if (!UnpadData(DecodedData))
		{
			UE_LOG(MemoryGuardLog, Error, TEXT("Guarded value has invalid padding!"));
			return Result;
		}

		// Ensure there's enough data left to populate Result.
		if(DecodedData.Num() < sizeof(T)) 
		{
			UE_LOG(MemoryGuardLog, Error, TEXT("Decrypted size mismatch!"));
			return Result;
		}

		FMemory::Memcpy(&Result, DecodedData.GetData(), sizeof(T));
		return Result;
	}

	void SetValue(const T& NewValue)
	{
		const uint8* BytePtr = reinterpret_cast<const uint8*>(&NewValue);
		TArray DataArray(BytePtr, sizeof(T));
		PadData(DataArray);
		Signature = HashData(DataArray);
		FAES::EncryptData(DataArray.GetData(), DataArray.Num(), reinterpret_cast<const uint8*>(TCHAR_TO_ANSI(*Signature)), FAES::FAESKey::KeySize);
		Value = FBase64::Encode(DataArray);
	}

private:
    static FString HashData(const TArray<uint8>& Data)
    {
        const auto ArrayView = MakeArrayView(Data.GetData(), Data.Num());
        return UTF8_TO_TCHAR(picosha2::hash256_hex_string(ArrayView.begin(), ArrayView.end()).c_str());
    }

	static void PadData(TArray<uint8>& Data, uint32 BlockSize = FAES::AESBlockSize)
    {
    	// Calculate the padding needed to make DataArray.Num() a multiple of BlockSize.
    	const uint32 PaddingSize = BlockSize - (Data.Num() % BlockSize);
    
    	// Using PKCS#7 padding scheme.
    	const uint8 PadValue = PaddingSize == 0 ? BlockSize : PaddingSize;
    	for(uint32 i = 0; i < PadValue; i++)
    	{
    		Data.Add(PadValue);
    	}
    }

	static bool UnpadData(TArray<uint8>& Data, uint32 BlockSize = FAES::AESBlockSize)
    {
    	// Ensure there's data to unpad.
    	if (Data.Num() == 0)
    	{
    		return false;
    	}
    
    	// Retrieve the padding size from the last byte of the Data array.
    	const uint8 PaddingSize = Data.Last();
    
    	// Validate the padding size.
    	if (PaddingSize == 0 || PaddingSize > BlockSize)
    	{
    		return false;
    	}
    
    	// Validate the padding bytes.
    	for (uint32 i = 0; i < PaddingSize; i++)
    	{
    		if (Data[Data.Num() - 1 - i] != PaddingSize)
    		{
    			return false;
    		}
    	}
    
    	// Remove the padding.
    	Data.RemoveAt(Data.Num() - PaddingSize, PaddingSize, true);
	    return true;
    }

};
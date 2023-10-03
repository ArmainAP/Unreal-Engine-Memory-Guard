// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
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
        if (FBase64::Decode(Value, DecodedData))
        {
            const FString DecodedSignature = HashData(DecodedData);
            if(Signature == DecodedSignature)
            {
                FAES::DecryptData(DecodedData.GetData(), DecodedData.Num(), reinterpret_cast<const uint8*>(TCHAR_TO_ANSI(*Signature)), FAES::FAESKey::KeySize);
                FMemory::Memcpy(&Result, DecodedData.GetData(), sizeof(T));
            }
        }
        
        return Result;
    }

    void SetValue(const T& NewValue)
    {
        const uint8* BytePtr = reinterpret_cast<const uint8*>(&NewValue);
        TArray DataArray(BytePtr, sizeof(T));
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
};
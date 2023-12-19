// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataTypes/GuardedBool.h"
#include "DataTypes/GuardedByte.h"
#include "DataTypes/GuardedFloat.h"
#include "DataTypes/GuardedInteger.h"
#include "DataTypes/GuardedInteger64.h"
#include "DataTypes/GuardedName.h"
#include "DataTypes/GuardedString.h"
#include "DataTypes/GuardedText.h"
#include "DataTypes/GuardedVector.h"
#include "DataTypes/GuardedRotator.h"
#include "DataTypes/GuardedTransform.h"
#include "GuardedValueHelpers.generated.h"

/**
 * 
 */
UCLASS()
class MEMORYGUARD_API UGuardedValueHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Guarded Bool Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static bool GetGuardedBool(const FGuardedBool& GuardedBool)
	{
		return GuardedBool.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedBool(UPARAM(ref) FGuardedBool& GuardedBool, const bool NewValue)
	{
		GuardedBool.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedBool GuardBool(const bool Value)
	{
		return FGuardedBool(Value);
	}

	// Guarded Byte Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static uint8 GetGuardedByte(const FGuardedByte& GuardedByte)
	{
		return GuardedByte.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedByte(UPARAM(ref) FGuardedByte& GuardedByte, const uint8 NewValue)
	{
		GuardedByte.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedByte GuardByte(const uint8 Value)
	{
		return FGuardedByte(Value);
	}
	
	// Guarded Float Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static float GetGuardedFloat(const FGuardedFloat& GuardedFloat)
	{
		return GuardedFloat.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedFloat(UPARAM(ref) FGuardedFloat& GuardedFloat, const float NewValue)
	{
		GuardedFloat.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedFloat GuardFloat(const float Value)
	{
		return FGuardedFloat(Value);
	}

	// Guarded Integer Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static int32 GetGuardedInteger(const FGuardedInteger& GuardedInteger)
	{
		return GuardedInteger.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedInteger(UPARAM(ref) FGuardedInteger& GuardedInteger, const int32 NewValue)
	{
		GuardedInteger.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedInteger GuardInteger(const int32 Value)
	{
		return FGuardedInteger(Value);
	}

	// Guarded Integer64 Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static int64 GetGuardedInteger64(const FGuardedInteger64& GuardedInteger64)
	{
		return GuardedInteger64.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedInteger64(UPARAM(ref) FGuardedInteger64& GuardedInteger64, const int64 NewValue)
	{
		GuardedInteger64.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedInteger64 GuardInteger64(const int64 Value)
	{
		return FGuardedInteger64(Value);
	}

	// Guarded Name Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FName GetGuardedName(const FGuardedName& GuardedName)
	{
		return GuardedName.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedName(UPARAM(ref) FGuardedName& GuardedName, const FName NewValue)
	{
		GuardedName.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedName GuardName(const FName Value)
	{
		return FGuardedName(Value);
	}

	// Guarded String Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FString GetGuardedString(const FGuardedString& GuardedString)
	{
		return GuardedString.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedString(UPARAM(ref) FGuardedString& GuardedString, const FString NewValue)
	{
		GuardedString.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedString GuardString(const FString Value)
	{
		return FGuardedString(Value);
	}

	// Guarded Text Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FText GetGuardedText(const FGuardedText& GuardedText)
	{
		return GuardedText.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedText(UPARAM(ref) FGuardedText& GuardedText, const FText NewValue)
	{
		GuardedText.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedText GuardText(const FText Value)
	{
		return FGuardedText(Value);
	}

	// Guarded Vector Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FVector GetGuardedVector(const FGuardedVector& GuardedVector)
	{
		return GuardedVector.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedVector(UPARAM(ref) FGuardedVector& GuardedVector, const FVector NewValue)
	{
		GuardedVector.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedVector GuardVector(const FVector Value)
	{
		return FGuardedVector(Value);
	}

	// Guarded Rotator Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FRotator GetGuardedRotator(const FGuardedRotator& GuardedRotator)
	{
		return GuardedRotator.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedRotator(UPARAM(ref) FGuardedRotator& GuardedRotator, const FRotator NewValue)
	{
		GuardedRotator.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedRotator GuardRotator(const FRotator Value)
	{
		return FGuardedRotator(Value);
	}

	// Guarded Transform Setters and Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FTransform GetGuardedTransform(const FGuardedTransform& GuardedTransform)
	{
		return GuardedTransform.Get();
	}

	UFUNCTION(BlueprintCallable, Category=MemoryGuard)
	static void SetGuardedTransform(UPARAM(ref) FGuardedTransform& GuardedTransform, const FTransform NewValue)
	{
		GuardedTransform.Set(NewValue);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category=MemoryGuard)
	static FGuardedTransform GuardTransform(const FTransform Value)
	{
		return FGuardedTransform(Value);
	}
};

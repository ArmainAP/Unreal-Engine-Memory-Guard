// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GuardedValue.h"
#include "BlueprintGuardedValue.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MEMORYGUARD_API UBlueprintGuardedValue : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Gets the value of the specified GuardedValue. */
	UFUNCTION(BlueprintCallable, CustomThunk, meta = (CustomStructureParam = "OutValue", AutoCreateRefTerm = "OutValue"), Category=MemoryGuard)
	void GetGuardedValue(UPARAM(DisplayName="Value") int32& OutValue);
	DECLARE_FUNCTION(execGetGuardedValue);

	/** Adds (new) or sets (existing) the value of the specified GuardedValue. */
	UFUNCTION(BlueprintCallable, CustomThunk, meta = (CustomStructureParam = "Value", AutoCreateRefTerm = "Value"), Category=MemoryGuard)
	void SetGuardedValue(const int32& Value);
	DECLARE_FUNCTION(execSetGuardedValue);
	
protected:
	FGuardedValue<TArray<uint8>> GuardedValue;
};

// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedString.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedString
{
    GENERATED_BODY()

private:
    FGuardedValue<FString> Value;
    
public:
    // Constructors
    FGuardedString()
    {
        Value.SetValue("");
    }

    FGuardedString(const FString& InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedString(const FGuardedString& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    FString Get() const
    {
        return Value.GetValue();
    }

    void Set(const FString& InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedString& Other) const
    {
        return Value.GetValue() == Other.Value.GetValue();
    }

    FORCEINLINE bool operator==(const FString& Other) const
    {
        return Value.GetValue() == Other;
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedString& Other) const
    {
        return Value.GetValue() != Other.Value.GetValue();
    }

    FORCEINLINE bool operator!=(const FString& Other) const
    {
        return Value.GetValue() != Other;
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedString
    FORCEINLINE FGuardedString& operator=(const FGuardedString& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Assignment with FString
    FORCEINLINE FGuardedString& operator=(const FString& Other)
    {
        Value.SetValue(Other);
        return *this;
    }

    /////////////////////
    // Other operators //
    /////////////////////

    FORCEINLINE FArchive& operator<<(FArchive& Ar)
    {
        FString StringValue = Value.GetValue();
        Ar << StringValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(StringValue);
        }
        return Ar;
    }
};
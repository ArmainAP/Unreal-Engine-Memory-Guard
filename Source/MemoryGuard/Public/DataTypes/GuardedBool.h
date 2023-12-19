// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedBool.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedBool
{
    GENERATED_BODY()

private:
    FGuardedValue<bool> Value;
    
public:
    // Constructors
    FGuardedBool()
    {
        Value.SetValue(false);
    }

    FGuardedBool(const bool InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedBool(const FGuardedBool& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    bool Get() const
    {
        return Value.GetValue();
    }

    void Set(const bool InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedBool& Other) const
    {
        return Value.GetValue() == Other.Value.GetValue();
    }

    FORCEINLINE bool operator==(bool Other) const
    {
        return Value.GetValue() == Other;
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedBool& Other) const
    {
        return Value.GetValue() != Other.Value.GetValue();
    }

    FORCEINLINE bool operator!=(bool Other) const
    {
        return Value.GetValue() != Other;
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedBool
    FORCEINLINE FGuardedBool& operator=(const FGuardedBool& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Assignment with bool
    FORCEINLINE FGuardedBool& operator=(bool Other)
    {
        Value.SetValue(Other);
        return *this;
    }

    /////////////////////
    // Other operators //
    /////////////////////

    FORCEINLINE FArchive& operator<<(FArchive& Ar)
    {
        bool BoolValue = Value.GetValue();
        Ar << BoolValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(BoolValue);
        }
        return Ar;
    }
};
// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedRotator.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedRotator
{
    GENERATED_BODY()

private:
    FGuardedValue<FRotator> Value;
    
public:
    // Constructors
    FGuardedRotator()
    {
        Value.SetValue(FRotator::ZeroRotator);
    }

    FGuardedRotator(const FRotator& InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedRotator(const FGuardedRotator& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    FRotator Get() const
    {
        return Value.GetValue();
    }

    void Set(const FRotator& InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Arithmetic operators //
    //////////////////////////

    // Addition
    FORCEINLINE FGuardedRotator operator+(const FGuardedRotator& Other) const
    {
        return FGuardedRotator(Value.GetValue() + Other.Value.GetValue());
    }

    // Subtraction
    FORCEINLINE FGuardedRotator operator-(const FGuardedRotator& Other) const
    {
        return FGuardedRotator(Value.GetValue() - Other.Value.GetValue());
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedRotator& Other) const
    {
        return Value.GetValue() == Other.Value.GetValue();
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedRotator& Other) const
    {
        return Value.GetValue() != Other.Value.GetValue();
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedRotator
    FORCEINLINE FGuardedRotator& operator=(const FGuardedRotator& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Addition assignment with FGuardedRotator
    FORCEINLINE FGuardedRotator& operator+=(const FGuardedRotator& Other)
    {
        Value.SetValue(Value.GetValue() + Other.Value.GetValue());
        return *this;
    }

    // Subtraction assignment with FGuardedRotator
    FORCEINLINE FGuardedRotator& operator-=(const FGuardedRotator& Other)
    {
        Value.SetValue(Value.GetValue() - Other.Value.GetValue());
        return *this;
    }

    /////////////////////
    // Other operators //
    /////////////////////

    FORCEINLINE FArchive& operator<<(FArchive& Ar)
    {
        FRotator RotatorValue = Value.GetValue();
        Ar << RotatorValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(RotatorValue);
        }
        return Ar;
    }
};
#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedVector.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedVector
{
    GENERATED_BODY()

private:
    FGuardedValue<FVector> Value;
    
public:
    // Constructors
    FGuardedVector()
    {
        Value.SetValue(FVector::ZeroVector);
    }

    FGuardedVector(const FVector& InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedVector(const FGuardedVector& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    FVector Get() const
    {
        return Value.GetValue();
    }

    void Set(const FVector& InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Arithmetic operators //
    //////////////////////////

    // Addition
    FORCEINLINE FGuardedVector operator+(const FGuardedVector& Other) const
    {
        return FGuardedVector(Value.GetValue() + Other.Value.GetValue());
    }

    // Subtraction
    FORCEINLINE FGuardedVector operator-(const FGuardedVector& Other) const
    {
        return FGuardedVector(Value.GetValue() - Other.Value.GetValue());
    }

    // Multiplication
    FORCEINLINE FGuardedVector operator*(const FGuardedVector& Other) const
    {
        return FGuardedVector(Value.GetValue() * Other.Value.GetValue());
    }

    // Division
    FORCEINLINE FGuardedVector operator/(const FGuardedVector& Other) const
    {
        return FGuardedVector(Value.GetValue() / Other.Value.GetValue());
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedVector
    FORCEINLINE FGuardedVector& operator=(const FGuardedVector& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Addition assignment with FGuardedVector
    FORCEINLINE FGuardedVector& operator+=(const FGuardedVector& Other)
    {
        Value.SetValue(Value.GetValue() + Other.Value.GetValue());
        return *this;
    }

    // Subtraction assignment with FGuardedVector
    FORCEINLINE FGuardedVector& operator-=(const FGuardedVector& Other)
    {
        Value.SetValue(Value.GetValue() - Other.Value.GetValue());
        return *this;
    }

    // Multiplication assignment with FGuardedVector
    FORCEINLINE FGuardedVector& operator*=(const FGuardedVector& Other)
    {
        Value.SetValue(Value.GetValue() * Other.Value.GetValue());
        return *this;
    }

    // Division assignment with FGuardedVector
    FORCEINLINE FGuardedVector& operator/=(const FGuardedVector& Other)
    {
        if (Other.Value.GetValue() != FVector::ZeroVector)
        {
            Value.SetValue(Value.GetValue() / Other.Value.GetValue());
        }
        return *this;
    }
};
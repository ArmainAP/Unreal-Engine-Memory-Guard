// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedInteger64.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedInteger64
{
    GENERATED_BODY()

private:
    FGuardedValue<int64> Value;
    
public:
    // Constructors
    FGuardedInteger64()
    {
        Value.SetValue(0);
    }

    FGuardedInteger64(const int64 InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedInteger64(const FGuardedInteger64& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    int64 Get() const
    {
        return Value.GetValue();
    }

    void Set(const int64 InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Arithmetic operators //
    //////////////////////////

    // Addition
    FORCEINLINE FGuardedInteger64 operator+(const FGuardedInteger64& Other) const
    {
        return FGuardedInteger64(Value.GetValue() + Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger64 operator+(int64 Other) const
    {
        return FGuardedInteger64(Value.GetValue() + Other);
    }

    // Subtraction
    FORCEINLINE FGuardedInteger64 operator-(const FGuardedInteger64& Other) const
    {
        return FGuardedInteger64(Value.GetValue() - Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger64 operator-(int64 Other) const
    {
        return FGuardedInteger64(Value.GetValue() - Other);
    }

    // Multiplication
    FORCEINLINE FGuardedInteger64 operator*(const FGuardedInteger64& Other) const
    {
        return FGuardedInteger64(Value.GetValue() * Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger64 operator*(int64 Other) const
    {
        return FGuardedInteger64(Value.GetValue() * Other);
    }

    // Division
    FORCEINLINE FGuardedInteger64 operator/(const FGuardedInteger64& Other) const
    {
        return FGuardedInteger64(Value.GetValue() / Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger64 operator/(int64 Other) const
    {
        return FGuardedInteger64(Value.GetValue() / Other);
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedInteger64& Other) const
    {
        return Value.GetValue() == Other.Value.GetValue();
    }

    FORCEINLINE bool operator==(int64 Other) const
    {
        return Value.GetValue() == Other;
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedInteger64& Other) const
    {
        return Value.GetValue() != Other.Value.GetValue();
    }

    FORCEINLINE bool operator!=(int64 Other) const
    {
        return Value.GetValue() != Other;
    }

    // Less than
    FORCEINLINE bool operator<(const FGuardedInteger64& Other) const
    {
        return Value.GetValue() < Other.Value.GetValue();
    }

    FORCEINLINE bool operator<(int64 Other) const
    {
        return Value.GetValue() < Other;
    }

    // Less than or equal to
    FORCEINLINE bool operator<=(const FGuardedInteger64& Other) const
    {
        return Value.GetValue() <= Other.Value.GetValue();
    }

    FORCEINLINE bool operator<=(int64 Other) const
    {
        return Value.GetValue() <= Other;
    }

    // Greater than
    FORCEINLINE bool operator>(const FGuardedInteger64& Other) const
    {
        return Value.GetValue() > Other.Value.GetValue();
    }

    FORCEINLINE bool operator>(int64 Other) const
    {
        return Value.GetValue() > Other;
    }

    // Greater than or equal to
    FORCEINLINE bool operator>=(const FGuardedInteger64& Other) const
    {
        return Value.GetValue() >= Other.Value.GetValue();
    }

    FORCEINLINE bool operator>=(int64 Other) const
    {
        return Value.GetValue() >= Other;
    }

    ///////////////////////////////////////
    // Increment and decrement operators //
    ///////////////////////////////////////

    // Pre-increment
    FORCEINLINE FGuardedInteger64& operator++()
    {
        Value.SetValue(Value.GetValue() + 1);
        return *this;
    }

    // Post-increment
    FORCEINLINE FGuardedInteger64 operator++(int)
    {
        FGuardedInteger64 Temp = *this;
        Value.SetValue(Value.GetValue() + 1);
        return Temp;
    }

    // Pre-decrement
    FORCEINLINE FGuardedInteger64& operator--()
    {
        Value.SetValue(Value.GetValue() - 1);
        return *this;
    }

    // Post-decrement
    FORCEINLINE FGuardedInteger64 operator--(int)
    {
        FGuardedInteger64 Temp = *this;
        Value.SetValue(Value.GetValue() - 1);
        return Temp;
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedInteger64
    FORCEINLINE FGuardedInteger64& operator=(const FGuardedInteger64& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Assignment with int64
    FORCEINLINE FGuardedInteger64& operator=(int64 Other)
    {
        Value.SetValue(Other);
        return *this;
    }

    // Addition assignment with FGuardedInteger64
    FORCEINLINE FGuardedInteger64& operator+=(const FGuardedInteger64& Other)
    {
        Value.SetValue(Value.GetValue() + Other.Value.GetValue());
        return *this;
    }

    // Addition assignment with int64
    FORCEINLINE FGuardedInteger64& operator+=(int64 Other)
    {
        Value.SetValue(Value.GetValue() + Other);
        return *this;
    }

    // Subtraction assignment with FGuardedInteger64
    FORCEINLINE FGuardedInteger64& operator-=(const FGuardedInteger64& Other)
    {
        Value.SetValue(Value.GetValue() - Other.Value.GetValue());
        return *this;
    }

    // Subtraction assignment with int64
    FORCEINLINE FGuardedInteger64& operator-=(int64 Other)
    {
        Value.SetValue(Value.GetValue() - Other);
        return *this;
    }

    // Multiplication assignment with FGuardedInteger64
    FORCEINLINE FGuardedInteger64& operator*=(const FGuardedInteger64& Other)
    {
        Value.SetValue(Value.GetValue() * Other.Value.GetValue());
        return *this;
    }

    // Multiplication assignment with int64
    FORCEINLINE FGuardedInteger64& operator*=(int64 Other)
    {
        Value.SetValue(Value.GetValue() * Other);
        return *this;
    }

    // Division assignment with FGuardedInteger64
    FORCEINLINE FGuardedInteger64& operator/=(const FGuardedInteger64& Other)
    {
        if (Other.Value.GetValue() != 0)
        {
            Value.SetValue(Value.GetValue() / Other.Value.GetValue());
        }
        return *this;
    }

    // Division assignment with int64
    FORCEINLINE FGuardedInteger64& operator/=(int64 Other)
    {
        if (Other != 0)
        {
            Value.SetValue(Value.GetValue() / Other);
        }
        return *this;
    }

    /////////////////////
    // Other operators //
    /////////////////////

    FORCEINLINE FArchive& operator<<(FArchive& Ar)
    {
        int64 IntValue = Value.GetValue();
        Ar << IntValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(IntValue);
        }
        return Ar;
    }
};
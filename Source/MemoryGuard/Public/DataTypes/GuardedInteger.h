// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedInteger.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedInteger
{
    GENERATED_BODY()

private:
    FGuardedValue<int32> Value;
    
public:
    // Constructors
    FGuardedInteger()
    {
        Value.SetValue(0);
    }

    FGuardedInteger(const int32 InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedInteger(const FGuardedInteger& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    int32 Get() const
    {
        return Value.GetValue();
    }

    void Set(const int32 InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Arithmetic operators //
    //////////////////////////

    // Addition
    FORCEINLINE FGuardedInteger operator+(const FGuardedInteger& Other) const
    {
        return FGuardedInteger(Value.GetValue() + Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger operator+(int32 Other) const
    {
        return FGuardedInteger(Value.GetValue() + Other);
    }

    // Subtraction
    FORCEINLINE FGuardedInteger operator-(const FGuardedInteger& Other) const
    {
        return FGuardedInteger(Value.GetValue() - Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger operator-(int32 Other) const
    {
        return FGuardedInteger(Value.GetValue() - Other);
    }

    // Multiplication
    FORCEINLINE FGuardedInteger operator*(const FGuardedInteger& Other) const
    {
        return FGuardedInteger(Value.GetValue() * Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger operator*(int32 Other) const
    {
        return FGuardedInteger(Value.GetValue() * Other);
    }

    // Division
    FORCEINLINE FGuardedInteger operator/(const FGuardedInteger& Other) const
    {
        return FGuardedInteger(Value.GetValue() / Other.Value.GetValue());
    }

    FORCEINLINE FGuardedInteger operator/(int32 Other) const
    {
        return FGuardedInteger(Value.GetValue() / Other);
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedInteger& Other) const
    {
        return Value.GetValue() == Other.Value.GetValue();
    }

    FORCEINLINE bool operator==(int32 Other) const
    {
        return Value.GetValue() == Other;
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedInteger& Other) const
    {
        return Value.GetValue() != Other.Value.GetValue();
    }

    FORCEINLINE bool operator!=(int32 Other) const
    {
        return Value.GetValue() != Other;
    }

    // Less than
    FORCEINLINE bool operator<(const FGuardedInteger& Other) const
    {
        return Value.GetValue() < Other.Value.GetValue();
    }

    FORCEINLINE bool operator<(int32 Other) const
    {
        return Value.GetValue() < Other;
    }

    // Less than or equal to
    FORCEINLINE bool operator<=(const FGuardedInteger& Other) const
    {
        return Value.GetValue() <= Other.Value.GetValue();
    }

    FORCEINLINE bool operator<=(int32 Other) const
    {
        return Value.GetValue() <= Other;
    }

    // Greater than
    FORCEINLINE bool operator>(const FGuardedInteger& Other) const
    {
        return Value.GetValue() > Other.Value.GetValue();
    }

    FORCEINLINE bool operator>(int32 Other) const
    {
        return Value.GetValue() > Other;
    }

    // Greater than or equal to
    FORCEINLINE bool operator>=(const FGuardedInteger& Other) const
    {
        return Value.GetValue() >= Other.Value.GetValue();
    }

    FORCEINLINE bool operator>=(int32 Other) const
    {
        return Value.GetValue() >= Other;
    }

    ///////////////////////////////////////
    // Increment and decrement operators //
    ///////////////////////////////////////

    // Pre-increment
    FORCEINLINE FGuardedInteger& operator++()
    {
        Value.SetValue(Value.GetValue() + 1);
        return *this;
    }

    // Post-increment
    FORCEINLINE FGuardedInteger operator++(int)
    {
        FGuardedInteger Temp = *this;
        Value.SetValue(Value.GetValue() + 1);
        return Temp;
    }

    // Pre-decrement
    FORCEINLINE FGuardedInteger& operator--()
    {
        Value.SetValue(Value.GetValue() - 1);
        return *this;
    }

    // Post-decrement
    FORCEINLINE FGuardedInteger operator--(int)
    {
        FGuardedInteger Temp = *this;
        Value.SetValue(Value.GetValue() - 1);
        return Temp;
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedInteger
    FORCEINLINE FGuardedInteger& operator=(const FGuardedInteger& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Assignment with int32
    FORCEINLINE FGuardedInteger& operator=(int32 Other)
    {
        Value.SetValue(Other);
        return *this;
    }

    // Addition assignment with FGuardedInteger
    FORCEINLINE FGuardedInteger& operator+=(const FGuardedInteger& Other)
    {
        Value.SetValue(Value.GetValue() + Other.Value.GetValue());
        return *this;
    }

    // Addition assignment with int32
    FORCEINLINE FGuardedInteger& operator+=(int32 Other)
    {
        Value.SetValue(Value.GetValue() + Other);
        return *this;
    }

    // Subtraction assignment with FGuardedInteger
    FORCEINLINE FGuardedInteger& operator-=(const FGuardedInteger& Other)
    {
        Value.SetValue(Value.GetValue() - Other.Value.GetValue());
        return *this;
    }

    // Subtraction assignment with int32
    FORCEINLINE FGuardedInteger& operator-=(int32 Other)
    {
        Value.SetValue(Value.GetValue() - Other);
        return *this;
    }

    // Multiplication assignment with FGuardedInteger
    FORCEINLINE FGuardedInteger& operator*=(const FGuardedInteger& Other)
    {
        Value.SetValue(Value.GetValue() * Other.Value.GetValue());
        return *this;
    }

    // Multiplication assignment with int32
    FORCEINLINE FGuardedInteger& operator*=(int32 Other)
    {
        Value.SetValue(Value.GetValue() * Other);
        return *this;
    }

    // Division assignment with FGuardedInteger
    FORCEINLINE FGuardedInteger& operator/=(const FGuardedInteger& Other)
    {
        if (Other.Value.GetValue() != 0)
        {
            Value.SetValue(Value.GetValue() / Other.Value.GetValue());
        }
        return *this;
    }

    // Division assignment with int32
    FORCEINLINE FGuardedInteger& operator/=(int32 Other)
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
        int32 IntegerValue = Value.GetValue();
        Ar << IntegerValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(IntegerValue);
        }
        return Ar;
    }
};
// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedByte.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedByte
{
    GENERATED_BODY()

private:
    FGuardedValue<uint8> Value;
    
public:
    // Constructors
    FGuardedByte()
    {
        Value.SetValue(0);
    }

    FGuardedByte(const uint8 InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedByte(const FGuardedByte& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    uint8 Get() const
    {
        return Value.GetValue();
    }

    void Set(const uint8 InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Arithmetic operators //
    //////////////////////////

    // Addition
    FORCEINLINE FGuardedByte operator+(const FGuardedByte& Other) const
    {
        return FGuardedByte(Value.GetValue() + Other.Value.GetValue());
    }

    FORCEINLINE FGuardedByte operator+(uint8 Other) const
    {
        return FGuardedByte(Value.GetValue() + Other);
    }

    // Subtraction
    FORCEINLINE FGuardedByte operator-(const FGuardedByte& Other) const
    {
        return FGuardedByte(Value.GetValue() - Other.Value.GetValue());
    }

    FORCEINLINE FGuardedByte operator-(uint8 Other) const
    {
        return FGuardedByte(Value.GetValue() - Other);
    }

    // Multiplication
    FORCEINLINE FGuardedByte operator*(const FGuardedByte& Other) const
    {
        return FGuardedByte(Value.GetValue() * Other.Value.GetValue());
    }

    FORCEINLINE FGuardedByte operator*(uint8 Other) const
    {
        return FGuardedByte(Value.GetValue() * Other);
    }

    // Division
    FORCEINLINE FGuardedByte operator/(const FGuardedByte& Other) const
    {
        return FGuardedByte(Value.GetValue() / Other.Value.GetValue());
    }

    FORCEINLINE FGuardedByte operator/(uint8 Other) const
    {
        return FGuardedByte(Value.GetValue() / Other);
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedByte& Other) const
    {
        return Value.GetValue() == Other.Value.GetValue();
    }

    FORCEINLINE bool operator==(uint8 Other) const
    {
        return Value.GetValue() == Other;
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedByte& Other) const
    {
        return Value.GetValue() != Other.Value.GetValue();
    }

    FORCEINLINE bool operator!=(uint8 Other) const
    {
        return Value.GetValue() != Other;
    }

    // Less than
    FORCEINLINE bool operator<(const FGuardedByte& Other) const
    {
        return Value.GetValue() < Other.Value.GetValue();
    }

    FORCEINLINE bool operator<(uint8 Other) const
    {
        return Value.GetValue() < Other;
    }

    // Less than or equal to
    FORCEINLINE bool operator<=(const FGuardedByte& Other) const
    {
        return Value.GetValue() <= Other.Value.GetValue();
    }

    FORCEINLINE bool operator<=(uint8 Other) const
    {
        return Value.GetValue() <= Other;
    }

    // Greater than
    FORCEINLINE bool operator>(const FGuardedByte& Other) const
    {
        return Value.GetValue() > Other.Value.GetValue();
    }

    FORCEINLINE bool operator>(uint8 Other) const
    {
        return Value.GetValue() > Other;
    }

    // Greater than or equal to
    FORCEINLINE bool operator>=(const FGuardedByte& Other) const
    {
        return Value.GetValue() >= Other.Value.GetValue();
    }

    FORCEINLINE bool operator>=(uint8 Other) const
    {
        return Value.GetValue() >= Other;
    }

    ///////////////////////////////////////
    // Increment and decrement operators //
    ///////////////////////////////////////

    // Pre-increment
    FORCEINLINE FGuardedByte& operator++()
    {
        Value.SetValue(Value.GetValue() + 1);
        return *this;
    }

    // Post-increment
    FORCEINLINE FGuardedByte operator++(int)
    {
        FGuardedByte Temp = *this;
        Value.SetValue(Value.GetValue() + 1);
        return Temp;
    }

    // Pre-decrement
    FORCEINLINE FGuardedByte& operator--()
    {
        Value.SetValue(Value.GetValue() - 1);
        return *this;
    }

    // Post-decrement
    FORCEINLINE FGuardedByte operator--(int)
    {
        FGuardedByte Temp = *this;
        Value.SetValue(Value.GetValue() - 1);
        return Temp;
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedByte
    FORCEINLINE FGuardedByte& operator=(const FGuardedByte& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Assignment with uint8
    FORCEINLINE FGuardedByte& operator=(uint8 Other)
    {
        Value.SetValue(Other);
        return *this;
    }

    // Addition assignment with FGuardedByte
    FORCEINLINE FGuardedByte& operator+=(const FGuardedByte& Other)
    {
        Value.SetValue(Value.GetValue() + Other.Value.GetValue());
        return *this;
    }

    // Addition assignment with uint8
    FORCEINLINE FGuardedByte& operator+=(uint8 Other)
    {
        Value.SetValue(Value.GetValue() + Other);
        return *this;
    }

    // Subtraction assignment with FGuardedByte
    FORCEINLINE FGuardedByte& operator-=(const FGuardedByte& Other)
    {
        Value.SetValue(Value.GetValue() - Other.Value.GetValue());
        return *this;
    }

    // Subtraction assignment with uint8
    FORCEINLINE FGuardedByte& operator-=(uint8 Other)
    {
        Value.SetValue(Value.GetValue() - Other);
        return *this;
    }

    // Multiplication assignment with FGuardedByte
    FORCEINLINE FGuardedByte& operator*=(const FGuardedByte& Other)
    {
        Value.SetValue(Value.GetValue() * Other.Value.GetValue());
        return *this;
    }

    // Multiplication assignment with uint8
    FORCEINLINE FGuardedByte& operator*=(uint8 Other)
    {
        Value.SetValue(Value.GetValue() * Other);
        return *this;
    }

    // Division assignment with FGuardedByte
    FORCEINLINE FGuardedByte& operator/=(const FGuardedByte& Other)
    {
        if (Other.Value.GetValue() != 0)
        {
            Value.SetValue(Value.GetValue() / Other.Value.GetValue());
        }
        return *this;
    }

    // Division assignment with uint8
    FORCEINLINE FGuardedByte& operator/=(uint8 Other)
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
        uint8 ByteValue = Value.GetValue();
        Ar << ByteValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(ByteValue);
        }
        return Ar;
    }
};
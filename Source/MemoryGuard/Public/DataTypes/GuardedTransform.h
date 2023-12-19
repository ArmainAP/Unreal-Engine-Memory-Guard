// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedTransform.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedTransform
{
    GENERATED_BODY()

private:
    FGuardedValue<FTransform> Value;
    
public:
    // Constructors
    FGuardedTransform()
    {
        Value.SetValue(FTransform::Identity);
    }

    FGuardedTransform(const FTransform& InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedTransform(const FGuardedTransform& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    FTransform Get() const
    {
        return Value.GetValue();
    }

    void Set(const FTransform& InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Arithmetic operators //
    //////////////////////////

    // Multiplication
    FORCEINLINE FGuardedTransform operator*(const FGuardedTransform& Other) const
    {
        return FGuardedTransform(Value.GetValue() * Other.Value.GetValue());
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedTransform
    FORCEINLINE FGuardedTransform& operator=(const FGuardedTransform& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Multiplication assignment with FGuardedTransform
    FORCEINLINE FGuardedTransform& operator*=(const FGuardedTransform& Other)
    {
        Value.SetValue(Value.GetValue() * Other.Value.GetValue());
        return *this;
    }

    /////////////////////
    // Other operators //
    /////////////////////

    FORCEINLINE FArchive& operator<<(FArchive& Ar)
    {
        FTransform TransformValue = Value.GetValue();
        Ar << TransformValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(TransformValue);
        }
        return Ar;
    }
};
// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedText.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedText
{
    GENERATED_BODY()

private:
    FGuardedValue<FText> Value;
    
public:
    // Constructors
    FGuardedText()
    {
        Value.SetValue(FText::GetEmpty());
    }

    FGuardedText(const FText& InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedText(const FGuardedText& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    FText Get() const
    {
        return Value.GetValue();
    }

    void Set(const FText& InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedText& Other) const
    {
        return Value.GetValue().EqualTo(Other.Value.GetValue());
    }

    FORCEINLINE bool operator==(const FText& Other) const
    {
        return Value.GetValue().EqualTo(Other);
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedText& Other) const
    {
        return !Value.GetValue().EqualTo(Other.Value.GetValue());
    }

    FORCEINLINE bool operator!=(const FText& Other) const
    {
        return !Value.GetValue().EqualTo(Other);
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedText
    FORCEINLINE FGuardedText& operator=(const FGuardedText& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Assignment with FText
    FORCEINLINE FGuardedText& operator=(const FText& Other)
    {
        Value.SetValue(Other);
        return *this;
    }

    /////////////////////
    // Other operators //
    /////////////////////

    FORCEINLINE FArchive& operator<<(FArchive& Ar)
    {
        FText TextValue = Value.GetValue();
        Ar << TextValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(TextValue);
        }
        return Ar;
    }
};
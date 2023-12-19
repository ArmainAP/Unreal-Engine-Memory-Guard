// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedName.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedName
{
    GENERATED_BODY()

private:
    FGuardedValue<FName> Value;
    
public:
    // Constructors
    FGuardedName()
    {
        Value.SetValue(FName(""));
    }

    FGuardedName(const FName InValue)
    {
        Value.SetValue(InValue);
    }

    FGuardedName(const FGuardedName& Other)
    {
        Value.SetValue(Other.Value.GetValue());
    }

    // Getters and Setters
    FName Get() const
    {
        return Value.GetValue();
    }

    void Set(const FName InValue)
    {
        Value.SetValue(InValue);
    }

    //////////////////////////
    // Comparison operators //
    //////////////////////////

    // Equality
    FORCEINLINE bool operator==(const FGuardedName& Other) const
    {
        return Value.GetValue() == Other.Value.GetValue();
    }

    FORCEINLINE bool operator==(FName Other) const
    {
        return Value.GetValue() == Other;
    }

    // Inequality
    FORCEINLINE bool operator!=(const FGuardedName& Other) const
    {
        return Value.GetValue() != Other.Value.GetValue();
    }

    FORCEINLINE bool operator!=(FName Other) const
    {
        return Value.GetValue() != Other;
    }

    //////////////////////////
    // Assignment operators //
    //////////////////////////

    // Assignment with FGuardedName
    FORCEINLINE FGuardedName& operator=(const FGuardedName& Other)
    {
        if (this != &Other)
        {
            Value.SetValue(Other.Value.GetValue());
        }
        return *this;
    }

    // Assignment with FName
    FORCEINLINE FGuardedName& operator=(FName Other)
    {
        Value.SetValue(Other);
        return *this;
    }

    /////////////////////
    // Other operators //
    /////////////////////

    FORCEINLINE FArchive& operator<<(FArchive& Ar)
    {
        FName NameValue = Value.GetValue();
        Ar << NameValue;
        if (Ar.IsLoading())
        {
            Value.SetValue(NameValue);
        }
        return Ar;
    }
};
// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MemoryGuard/Public/GuardedValue.h"
#include "GuardedFloat.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedFloat
{
	GENERATED_BODY()

private:
	FGuardedValue<float> Value;
	
public:
	// Constructors
	FGuardedFloat()
	{
		Value.SetValue(0.0f);
	}

	FGuardedFloat(const float InValue)
	{
		Value.SetValue(InValue);
	}

	FGuardedFloat(const FGuardedFloat& Other)
	{
		Value.SetValue(Other.Value.GetValue());
	}

	// Getters and Setters
	float Get() const
	{
		return Value.GetValue();
	}

	void Set(const float InValue)
	{
		Value.SetValue(InValue);
	}

	//////////////////////////
	// Arithmetic operators //
	//////////////////////////

	// Addition
	FORCEINLINE FGuardedFloat operator+(const FGuardedFloat& Other) const
	{
		return FGuardedFloat(Value.GetValue() + Other.Value.GetValue());
	}

	FORCEINLINE FGuardedFloat operator+(float Other) const
	{
		return FGuardedFloat(Value.GetValue() + Other);
	}

	// Subtraction
	FORCEINLINE FGuardedFloat operator-(const FGuardedFloat& Other) const
	{
		return FGuardedFloat(Value.GetValue() - Other.Value.GetValue());
	}

	FORCEINLINE FGuardedFloat operator-(float Other) const
	{
		return FGuardedFloat(Value.GetValue() - Other);
	}

	// Multiplication
	FORCEINLINE FGuardedFloat operator*(const FGuardedFloat& Other) const
	{
		return FGuardedFloat(Value.GetValue() * Other.Value.GetValue());
	}

	FORCEINLINE FGuardedFloat operator*(float Other) const
	{
		return FGuardedFloat(Value.GetValue() * Other);
	}

	// Division
	FORCEINLINE FGuardedFloat operator/(const FGuardedFloat& Other) const
	{
		return FGuardedFloat(Value.GetValue() / Other.Value.GetValue());
	}

	FORCEINLINE FGuardedFloat operator/(float Other) const
	{
		return FGuardedFloat(Value.GetValue() / Other);
	}

	//////////////////////////
	// Comparison operators //
	//////////////////////////

	// Equality
	FORCEINLINE bool operator==(const FGuardedFloat& Other) const
	{
		return Value.GetValue() == Other.Value.GetValue();
	}

	FORCEINLINE bool operator==(float Other) const
	{
		return Value.GetValue() == Other;
	}

	// Inequality
	FORCEINLINE bool operator!=(const FGuardedFloat& Other) const
	{
		return Value.GetValue() != Other.Value.GetValue();
	}

	FORCEINLINE bool operator!=(float Other) const
	{
		return Value.GetValue() != Other;
	}

	// Less than
	FORCEINLINE bool operator<(const FGuardedFloat& Other) const
	{
		return Value.GetValue() < Other.Value.GetValue();
	}

	FORCEINLINE bool operator<(float Other) const
	{
		return Value.GetValue() < Other;
	}

	// Less than or equal to
	FORCEINLINE bool operator<=(const FGuardedFloat& Other) const
	{
		return Value.GetValue() <= Other.Value.GetValue();
	}

	FORCEINLINE bool operator<=(float Other) const
	{
		return Value.GetValue() <= Other;
	}

	// Greater than
	FORCEINLINE bool operator>(const FGuardedFloat& Other) const
	{
		return Value.GetValue() > Other.Value.GetValue();
	}

	FORCEINLINE bool operator>(float Other) const
	{
		return Value.GetValue() > Other;
	}

	// Greater than or equal to
	FORCEINLINE bool operator>=(const FGuardedFloat& Other) const
	{
		return Value.GetValue() >= Other.Value.GetValue();
	}

	FORCEINLINE bool operator>=(float Other) const
	{
		return Value.GetValue() >= Other;
	}

	///////////////////////////////////////
	// Increment and decrement operators //
	///////////////////////////////////////

	// Pre-increment
	FORCEINLINE FGuardedFloat& operator++()
	{
		Value.SetValue(Value.GetValue() + 1);
		return *this;
	}

	// Post-increment
	FORCEINLINE FGuardedFloat operator++(int)
	{
		FGuardedFloat Temp = *this;
		Value.SetValue(Value.GetValue() + 1);
		return Temp;
	}

	// Pre-decrement
	FORCEINLINE FGuardedFloat& operator--()
	{
		Value.SetValue(Value.GetValue() - 1);
		return *this;
	}

	// Post-decrement
	FORCEINLINE FGuardedFloat operator--(int)
	{
		FGuardedFloat Temp = *this;
		Value.SetValue(Value.GetValue() - 1);
		return Temp;
	}

	//////////////////////////
	// Assignment operators //
	//////////////////////////

	// Assignment with FGuardedFloat
	FORCEINLINE FGuardedFloat& operator=(const FGuardedFloat& Other)
	{
		if (this != &Other)
		{
			Value.SetValue(Other.Value.GetValue());
		}
		return *this;
	}

	// Assignment with float
	FORCEINLINE FGuardedFloat& operator=(float Other)
	{
		Value.SetValue(Other);
		return *this;
	}

	// Addition assignment with FGuardedFloat
	FORCEINLINE FGuardedFloat& operator+=(const FGuardedFloat& Other)
	{
		Value.SetValue(Value.GetValue() + Other.Value.GetValue());
		return *this;
	}

	// Addition assignment with float
	FORCEINLINE FGuardedFloat& operator+=(float Other)
	{
		Value.SetValue(Value.GetValue() + Other);
		return *this;
	}

	// Subtraction assignment with FGuardedFloat
	FORCEINLINE FGuardedFloat& operator-=(const FGuardedFloat& Other)
	{
		Value.SetValue(Value.GetValue() - Other.Value.GetValue());
		return *this;
	}

	// Subtraction assignment with float
	FORCEINLINE FGuardedFloat& operator-=(float Other)
	{
		Value.SetValue(Value.GetValue() - Other);
		return *this;
	}

	// Multiplication assignment with FGuardedFloat
	FORCEINLINE FGuardedFloat& operator*=(const FGuardedFloat& Other)
	{
		Value.SetValue(Value.GetValue() * Other.Value.GetValue());
		return *this;
	}

	// Multiplication assignment with float
	FORCEINLINE FGuardedFloat& operator*=(float Other)
	{
		Value.SetValue(Value.GetValue() * Other);
		return *this;
	}

	// Division assignment with FGuardedFloat
	FORCEINLINE FGuardedFloat& operator/=(const FGuardedFloat& Other)
	{
		if (Other.Value.GetValue() != 0)
		{
			Value.SetValue(Value.GetValue() / Other.Value.GetValue());
		}
		return *this;
	}

	// Division assignment with float
	FORCEINLINE FGuardedFloat& operator/=(float Other)
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
		float FloatValue = Value.GetValue();
		Ar << FloatValue;
		if (Ar.IsLoading())
		{
			Value.SetValue(FloatValue);
		}
		return Ar;
	}
};
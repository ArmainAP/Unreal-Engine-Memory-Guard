#pragma once

#include "CoreMinimal.h"
#include "GuardedValue.h"
#include "GuardedFloat.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct MEMORYGUARD_API FGuardedFloat
{
	GENERATED_BODY()

private:
	FGuardedValue<float> Value;

public:
	FGuardedFloat()
	{
		Value.SetValue(0.0f);
	}

	FGuardedFloat(const float InValue)
	{
		Value.SetValue(InValue);
	}

	float Get() const
	{
		return Value.GetValue();
	}
	
	FORCEINLINE FGuardedFloat& operator=(const FGuardedFloat& Other)
	{
		Value = Other.Value;
		return *this;
	}

	FORCEINLINE FGuardedFloat& operator=(const float& InValue)
	{
		Value.SetValue(InValue);
		return *this;
	}

	FORCEINLINE FGuardedFloat& operator+=(const FGuardedFloat& Other)
	{
		const float NewFloat = Value.GetValue() + Other.Value.GetValue();
		Value.SetValue(NewFloat);
		return *this;
	}

	FORCEINLINE FGuardedFloat& operator-=(const FGuardedFloat& Other)
	{
		const float NewFloat = Value.GetValue() - Other.Value.GetValue();
		Value.SetValue(NewFloat);
		return *this;
	}
	
	FORCEINLINE FGuardedFloat& operator+=(const float& InValue)
	{
		const float NewFloat = Value.GetValue() + InValue;
		Value.SetValue(NewFloat);
		return *this;
	}

	FORCEINLINE FGuardedFloat& operator-=(const float& InValue)
	{
		const float NewFloat = Value.GetValue() - InValue;
		Value.SetValue(NewFloat);
		return *this;
	}

	FORCEINLINE FGuardedFloat operator++(int)
	{
		FGuardedFloat Temp = *this;
		++*this;
		return Temp;
	}
	
	FORCEINLINE FGuardedFloat operator--(int)
	{
		FGuardedFloat Temp = *this;
		--*this;
		return Temp;
	}
	
	FORCEINLINE FGuardedFloat& operator++()
	{
		float NewFloat = Value.GetValue();
		NewFloat++;
		Value.SetValue(NewFloat);
		return *this;
	}
	
	FORCEINLINE FGuardedFloat& operator--()
	{
		float NewFloat = Value.GetValue();
		NewFloat--;
		Value.SetValue(NewFloat);
		return *this;
	}

	FORCEINLINE FArchive& operator<<(FArchive& Ar)
	{
		float FloatValue = Get();
		Ar << FloatValue;
		if (Ar.IsLoading())
		{
			Value.SetValue(FloatValue);
		}
		return Ar;
	}
};
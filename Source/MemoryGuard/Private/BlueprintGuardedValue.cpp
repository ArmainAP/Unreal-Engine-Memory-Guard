// Copyright to Kat Code Labs, SRL. All Rights Reserved.

#include "BlueprintGuardedValue.h"

#define LOCTEXT_NAMESPACE "UBlueprintGuardedValue"

DEFINE_FUNCTION(UBlueprintGuardedValue::execGetGuardedValue)
{
	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* ValueProp = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (!ValueProp || !ValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("GetGuardedValue_MissingOutputProperty", "Failed to resolve the output parameter for GetGuardedValue.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	const int32 SizeOfData = ValueProp->GetSize();
	TArray<uint8> ByteArray = P_THIS->GuardedValue.GetValue();
	if (ByteArray.Num() == SizeOfData)  // Ensure sizes match
	{
		FMemory::Memcpy(ValuePtr, ByteArray.GetData(), SizeOfData);  // Copy the data back
	}
	else
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("GetGuardedValue_OutputPropertMismatch", "Size mismatch of the output parameter for GetGuardedValue.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}
}

DEFINE_FUNCTION(UBlueprintGuardedValue::execSetGuardedValue)
{
	Stack.StepCompiledIn<FProperty>(nullptr);
	const FProperty* SourceProperty = Stack.MostRecentProperty;
	const void* SourceValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (!SourceProperty || !SourceValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("SetGuardedValue_MissingInputProperty", "Failed to resolve the input parameter for SetGuardedValue.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	TArray<uint8> ByteArray;
	const int32 SizeOfData = SourceProperty->GetSize();
	ByteArray.SetNumUninitialized(SizeOfData);
	FMemory::Memcpy(ByteArray.GetData(), SourceValuePtr, SizeOfData);
	P_THIS->GuardedValue.SetValue(ByteArray);
}

#undef LOCTEXT_NAMESPACE
#pragma once

#include "CoreMinimal.h"
#include "CharacterState.generated.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8 {
	Idle		UMETA(DisplayName="Idle"),
	Sprinting	UMETA(DisplayName="Sprinting"),
	Notes		UMETA(DisplayName="Notes"),
};
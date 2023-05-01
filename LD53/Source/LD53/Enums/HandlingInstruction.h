#pragma once

#include "CoreMinimal.h"
#include "HandlingInstruction.generated.h"

UENUM(BlueprintType)
enum class EHandlingInstruction : uint8 {
	ThisSideUp		UMETA(DisplayName="This Side Up"),
	Unstable		UMETA(DisplayName="Unstable"),
	NoFloor			UMETA(DisplayName="No Floor"),
	NoStacking		UMETA(DisplayName="No Stacking"),
	AntiGravity		UMETA(DisplayName="Anti-gravity"),
	MaintainVision	UMETA(DisplayName="Maintain Vision"),
};
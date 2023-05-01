// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GrabInterface.generated.h"

UINTERFACE(BlueprintType)
class UGrabInterface : public UInterface
{
	GENERATED_BODY()
};

class LD53_API IGrabInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grab")
	void HighlightGrab(AActor* Source);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grab")
	bool Grab(AActor* Source, UPhysicsHandleComponent* Handle, FHitResult Hit);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grab")
	bool CancelGrab(AActor* Source, UPhysicsHandleComponent* Handle);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Grab")
	bool Throw(AActor* Source, UPhysicsHandleComponent* Handle, FVector Direction, float Strength);

	
};

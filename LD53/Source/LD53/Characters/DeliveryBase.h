// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/HandlingInstruction.h"
#include "GameFramework/Character.h"
#include "Interactions/GrabInterface.h"
#include "Interactions/InteractionInterface.h"
#include "DeliveryBase.generated.h"

UCLASS(Abstract)
class LD53_API ADeliveryBase : public ACharacter, public IGrabInterface 
{
	GENERATED_BODY()


	
public:
	ADeliveryBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual bool CancelGrab_Implementation(AActor* Source, UPhysicsHandleComponent* Handle) override;
	virtual bool Grab_Implementation(AActor* Source, UPhysicsHandleComponent* Handle, FHitResult Hit) override;
	virtual void HighlightGrab_Implementation(AActor* Source) override;
	virtual bool Throw_Implementation(AActor* Source, UPhysicsHandleComponent* Handle, FVector Direction, float Strength) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EHandlingInstruction> Instructions;

	
};

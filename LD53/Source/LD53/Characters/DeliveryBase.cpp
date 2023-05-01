// Fill out your copyright notice in the Description page of Project Settings.


#include "DeliveryBase.h"

ADeliveryBase::ADeliveryBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADeliveryBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADeliveryBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeliveryBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ADeliveryBase::CancelGrab_Implementation(AActor* Source, UPhysicsHandleComponent* Handle)
{
	return IGrabInterface::CancelGrab_Implementation(Source, Handle);
}

bool ADeliveryBase::Grab_Implementation(AActor* Source, UPhysicsHandleComponent* Handle, FHitResult Hit)
{
	return IGrabInterface::Grab_Implementation(Source, Handle, Hit);
}

void ADeliveryBase::HighlightGrab_Implementation(AActor* Source)
{
	IGrabInterface::HighlightGrab_Implementation(Source);
}

bool ADeliveryBase::Throw_Implementation(AActor* Source, UPhysicsHandleComponent* Handle, FVector Direction, float Strength)
{
	return IGrabInterface::Throw_Implementation(Source, Handle, Direction, Strength);
}

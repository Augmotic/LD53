// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/GameInstance/GlobalSubsystem.h"

void UGlobalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UGlobalSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UGlobalSubsystem::StartGameTimer()
{
	GetWorld()->GetTimerManager().SetTimer(GameTimer, this, &UGlobalSubsystem::GameTimerElapsed, 1.0f, true);
}

void UGlobalSubsystem::StopGameTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(GameTimer);
}

void UGlobalSubsystem::GameTimerElapsed()
{
	TimeTick();
}

void UGlobalSubsystem::TimeTick()
{
	IncrementTime(FTimespan(0,0,1));
	GameTicks++;
	TimeChangedDelegate.Broadcast();
}

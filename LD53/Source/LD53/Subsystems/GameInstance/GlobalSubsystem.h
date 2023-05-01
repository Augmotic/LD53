// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GlobalSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class LD53_API UGlobalSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTimeChangedDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameOverDelegate);
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	// Time
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FDateTime Time;

public:
	// Time
	FTimerHandle GameTimer;
	UFUNCTION(BlueprintCallable)
	void SetTime(FDateTime Value) { Time = Value; }
	UFUNCTION(BlueprintCallable)
	void StartGameTimer();
	UFUNCTION(BlueprintCallable)
	void StopGameTimer();
	UFUNCTION(BlueprintCallable)
	void IncrementTime(FTimespan Amount) { Time += Amount; }
	UFUNCTION(BlueprintCallable)
	void TimeTick();
	
	FDateTime GetTime() const { return Time; }

	UFUNCTION(BlueprintCallable)
	void GameOver() { GameOverDelegate.Broadcast(); }
	
	void GameTimerElapsed();
	UPROPERTY(BlueprintAssignable)
	FTimeChangedDelegate TimeChangedDelegate;
	UPROPERTY(BlueprintAssignable)
	FGameOverDelegate GameOverDelegate;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GameTicks = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DeliveryCount = 0;
	
};

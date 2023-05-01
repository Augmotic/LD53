// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/MaterialBillboardComponent.h"
#include "InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LD53_API UInteractionComponent : public USceneComponent, public IInteractionInterface
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionDelegate, AActor*, Source);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCancelInteractionDelegate, AActor*, Source);

	UPROPERTY(EditDefaultsOnly, NoClear, BlueprintReadOnly, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> Collider;

	UPROPERTY(EditDefaultsOnly, NoClear, BlueprintReadOnly, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialBillboardComponent> Icon;
	
public:	
	UInteractionComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool Enabled;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UMaterialInstanceDynamic> IconMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FLinearColor PassiveColor = FLinearColor(0.5f,0.5f,0.5f,1.0f);
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FLinearColor HighlightColor = FLinearColor(4,4,4,1);
	
public:	
	virtual void ShowInteraction_Implementation() override;
	virtual UInteractionComponent* HighlightInteraction_Implementation(AActor* Source) override;
	virtual bool Interact_Implementation(AActor* Source, UInteractionComponent*& Component) override;
	virtual bool CancelInteraction_Implementation(AActor* Source) override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool GetEnabled() const { return Enabled; }
	UFUNCTION(BlueprintCallable)
	void SetEnabled(bool Value) { Enabled = Value; }


	UFUNCTION(BlueprintCallable)
	void Initialize();
	
	UPROPERTY(BlueprintAssignable)
	FInteractionDelegate InteractionDelegate;
	UPROPERTY(BlueprintAssignable)
	FCancelInteractionDelegate CancelInteractionDelegate;

protected:
	FTimerHandle HighlightTimer;
	void CancelHighlight();

	FTimerHandle ShowTimer;
	void CancelShow();


};

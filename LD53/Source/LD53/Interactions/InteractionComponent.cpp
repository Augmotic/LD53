// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/InteractionComponent.h"

#include "Components/MaterialBillboardComponent.h"
#include "Kismet/KismetMaterialLibrary.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(this);

	Icon = CreateDefaultSubobject<UMaterialBillboardComponent>(TEXT("Icon"));
	Icon->SetupAttachment(this);
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	Initialize();

	Icon->SetVisibility(false);
	IconMaterial->SetVectorParameterValue("Tint", PassiveColor);

	
}

void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


void UInteractionComponent::Initialize()
{
	if (Icon->GetMaterial(0))
	{
		IconMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(GetWorld(), Icon->GetMaterial(0));
		Icon->SetMaterial(0, IconMaterial);
	}
}


void UInteractionComponent::ShowInteraction_Implementation()
{
	Icon->SetVisibility(true);
	GetWorld()->GetTimerManager().SetTimer(ShowTimer, this, &UInteractionComponent::CancelShow, 0.1f);
}

UInteractionComponent* UInteractionComponent::HighlightInteraction_Implementation(AActor* Source)
{
	if (!Enabled) return this;
	
	IconMaterial->SetVectorParameterValue("Tint", HighlightColor);
	GetWorld()->GetTimerManager().SetTimer(HighlightTimer, this, &UInteractionComponent::CancelHighlight, 0.1f);
	
	return this;
}

bool UInteractionComponent::Interact_Implementation(AActor* Source, UInteractionComponent*& Component)
{
	if (!Enabled) return false;
	
	InteractionDelegate.Broadcast(Source);
	Component = this;
	return true;
}

bool UInteractionComponent::CancelInteraction_Implementation(AActor* Source)
{
	CancelInteractionDelegate.Broadcast(Source);
	return false;
}

void UInteractionComponent::CancelHighlight()
{
	IconMaterial->SetVectorParameterValue("Tint", PassiveColor);
}

void UInteractionComponent::CancelShow()
{
	Icon->SetVisibility(false);
}


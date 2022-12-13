// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Actor = GetAcceptableActor();

	if (Actor != nullptr)
	{
		Mover->SetShouldMove(true);
	}
	else
	{
		Mover->SetShouldMove(false);
	}
}

// Find the actor that have the tag.
AActor* UTriggerComponent::GetAcceptableActor() const
{

	TArray<AActor*> Actors;

	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptableActorTag)) {
			return Actor;
		}
	}

	return nullptr;
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
	Mover = NewMover;
}

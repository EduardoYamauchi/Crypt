#include "Mover.h"
#include "Math/UnrealMathUtility.h"

UMover::UMover()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMover::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ShouldMove) {
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = OriginalLocation + MoveOffSet;
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		GetOwner()->SetActorLocation(NewLocation);
	}
}

void UMover::SetShouldMove(bool NewShouldMove)
{
	ShouldMove = NewShouldMove;
}


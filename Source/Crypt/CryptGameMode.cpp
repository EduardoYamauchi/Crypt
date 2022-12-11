// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptGameMode.h"
#include "CryptCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACryptGameMode::ACryptGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

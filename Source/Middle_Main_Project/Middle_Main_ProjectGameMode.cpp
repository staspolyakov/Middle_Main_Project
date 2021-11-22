// Copyright Epic Games, Inc. All Rights Reserved.

#include "Middle_Main_ProjectGameMode.h"
#include "Middle_Main_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMiddle_Main_ProjectGameMode::AMiddle_Main_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "dokkaebi_batGameMode.h"
#include "dokkaebi_batCharacter.h"
#include "UObject/ConstructorHelpers.h"

Adokkaebi_batGameMode::Adokkaebi_batGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

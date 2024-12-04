// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	if(NumberOfPlayers == 2)
	{
		GEngine->AddOnScreenDebugMessage(-1,15,FColor::Green, FString::Printf(TEXT("Yes")));
		UWorld* World = GetWorld();
		if(World)
		{
			bUseSeamlessTravel = false;
			World->ServerTravel(FString("/Game/World1?listen"));
		}
	} else {
		GEngine->AddOnScreenDebugMessage(-1,15,FColor::Red, FString::Printf(TEXT("No")));
	}
}

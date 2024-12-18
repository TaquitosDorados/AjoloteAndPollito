// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	PlayersConnected.Add(NewPlayer);
	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	if(NumberOfPlayers == 2)
	{
		GameReady();
	}
}

void ALobbyGameMode::StartGame()
{
	UWorld* World = GetWorld();
	if(World)
	{
		bUseSeamlessTravel = false;
		LoadingScreen();
		World->ServerTravel(FString("/Game/Maps/World1?listen"));
	}
}


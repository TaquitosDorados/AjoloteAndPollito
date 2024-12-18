// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AJOLOTEANDPOLLITO_API ALobbyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameReady();
	UFUNCTION(BlueprintCallable)
	void StartGame();
	UFUNCTION(BlueprintImplementableEvent)
	void LoadingScreen();

	UPROPERTY(BlueprintReadWrite)
	TArray<APlayerController*> PlayersConnected;
};

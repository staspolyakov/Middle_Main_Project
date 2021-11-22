// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GI_MainC.generated.h"

/**
 * 
 */
UCLASS()
class MIDDLE_MAIN_PROJECT_API UGI_MainC : public UGameInstance
{
	GENERATED_BODY()

	UGI_MainC();

	public:
		UPROPERTY(BlueprintReadOnly)
		int CurrentPlayerCount;


	UFUNCTION(BlueprintCallable)
	bool SetCurrentPlayerCount(int playerCount);

	UPROPERTY(Transient);
	AActor* LastPlayer;
	
};

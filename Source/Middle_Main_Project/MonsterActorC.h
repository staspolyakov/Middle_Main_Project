// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MonsterInterface.h"
#include "GameFramework/Actor.h"
#include "MonsterActorC.generated.h"

UCLASS()
class MIDDLE_MAIN_PROJECT_API AMonsterActorC : public AActor, public IMonsterInterface
{
	GENERATED_BODY()
	
public:	
	AMonsterActorC();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetHealth(int32 newHealth) override;
	
	
};

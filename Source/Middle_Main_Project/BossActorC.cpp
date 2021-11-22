// Fill out your copyright notice in the Description page of Project Settings.


#include "BossActorC.h"

ABossActorC::ABossActorC()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABossActorC::BeginPlay()
{
	Super::BeginPlay();
	auto* OtherMonster = Cast<IMonsterInterface>(GetOwner());
	OtherMonster->SetHealth(50);
}

void ABossActorC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABossActorC::SetHealth(int32 newHealth)
{
	Health=newHealth;
}

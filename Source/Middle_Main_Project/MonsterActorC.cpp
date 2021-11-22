

#include "MonsterActorC.h"

AMonsterActorC::AMonsterActorC()
{
	PrimaryActorTick.bCanEverTick = true;
	Health=100;
}

void AMonsterActorC::BeginPlay()
{
	Super::BeginPlay();
}

void AMonsterActorC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMonsterActorC::SetHealth(int32 newHealth)
{
	Health=newHealth;
}










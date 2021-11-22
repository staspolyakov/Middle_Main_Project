#pragma once

#include "CoreMinimal.h"
#include "MonsterInterface.h"
#include "GameFramework/Actor.h"
#include "BossActorC.generated.h"

UCLASS()
class MIDDLE_MAIN_PROJECT_API ABossActorC : public AActor, public IMonsterInterface
{
	GENERATED_BODY()
	
public:	
	ABossActorC();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetHealth(int32 NewHealth) override;
};

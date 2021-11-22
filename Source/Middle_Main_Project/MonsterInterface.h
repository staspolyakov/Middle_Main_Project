#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterInterface.generated.h"


UINTERFACE(MinimalAPI, Blueprintable)
class UMonsterInterface : public UInterface
{
	GENERATED_BODY()
	
};

class IMonsterInterface
{
	GENERATED_BODY()

public:
	virtual void SetHealth(int32 NewHealth)=0;
	int32 Health;

	
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void SetHealthByBP(int32 newHealth);
	

};




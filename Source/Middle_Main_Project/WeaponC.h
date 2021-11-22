
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponC.generated.h"

UCLASS()
class MIDDLE_MAIN_PROJECT_API AWeaponC : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeaponC();

	void Fire();

	UPROPERTY(BlueprintReadOnly);
	UStaticMeshComponent* Mesh;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};

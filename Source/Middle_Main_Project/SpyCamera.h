// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Engine/SpotLight.h"
#include "SpyCamera.generated.h"

class UBoxComponent;


UCLASS()
class MIDDLE_MAIN_PROJECT_API ASpyCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	ASpyCamera();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
	ASpotLight* DetectingLight;
	
	
protected:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere)
	float SpotTime;

	UPROPERTY(EditAnywhere)
	float UnSpotTime;

	UFUNCTION()
	void BoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void BoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	
	void SpotPlayer();
	void UnSpotPlayer();

	

	bool bIsSomethingSpotted;
	bool bAlert;

	FTimerHandle SpottingTimer;
	FTimerHandle UnSpottingTimer;
	
};

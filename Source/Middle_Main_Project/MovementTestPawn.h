// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "MovementTestPawn.generated.h"

UCLASS()
class MIDDLE_MAIN_PROJECT_API AMovementTestPawn : public APawn
{
	GENERATED_BODY()

public:
	AMovementTestPawn();

	void IsSpotted();
	void IsUnSpotted();

protected:
	UPROPERTY(Transient)
	AActor* ViewActor;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* UnSpottedMaterial;
	
	UPROPERTY(EditAnywhere)
	UMaterialInterface* SpottedMaterial;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(Transient)
	AActor* CurrentViewTarget;

	bool bIsViewByCamera;
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Val);
	void MoveRight(float Val);
	void CameraBlendComplete();

	
	virtual UPawnMovementComponent* GetMovementComponent() const override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere)
	UPawnMovementComponent* MovementComp;

	
};

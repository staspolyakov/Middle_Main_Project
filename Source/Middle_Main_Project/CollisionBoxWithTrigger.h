// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionBoxWithTrigger.generated.h"

UCLASS()
class MIDDLE_MAIN_PROJECT_API ACollisionBoxWithTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollisionBoxWithTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* BoxCollision;

	UFUNCTION(BlueprintCallable)
	void OnComponentHitFunc(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );

	UFUNCTION(BlueprintImplementableEvent)
	void OnHitMulticastEvent();

	UFUNCTION(BlueprintCallable)
	void Move();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitMulticast);
	FOnHitMulticast OnHitMulticast;

	DECLARE_DYNAMIC_DELEGATE(FOnHitDynamic);
	FOnHitDynamic OnHitDynamic;	
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponC.h"

// Sets default values
AWeaponC::AWeaponC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

}

void AWeaponC::Fire()
{
	float range=1000.0f;
	FVector SocketLocation = Mesh->GetSocketLocation(FName("Muzzle"));
	FVector Start(FVector::ZeroVector);
	FVector End(FVector::ZeroVector);

	End = SocketLocation+GetActorForwardVector()*range;
	//Mesh->getForvardVector;
	
	FHitResult HitResult(ForceInit);
	if(GetWorld()->LineTraceSingleByChannel(HitResult,SocketLocation,End,ECC_Pawn))
	{
		
	}
}

// Called when the game starts or when spawned
void AWeaponC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


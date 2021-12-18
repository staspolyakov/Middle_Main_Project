#include "MovementTestPawn.h"

#include "Engine/CollisionProfile.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"

AMovementTestPawn::AMovementTestPawn()
{
	SphereComp=CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetSphereRadius(50.f);
	SphereComp->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	SetRootComponent(SphereComp);

	MovementComp=CreateDefaultSubobject<UPawnMovementComponent,UFloatingPawnMovement>(TEXT("MovementComp"));
	MovementComp->SetUpdatedComponent(SphereComp);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetupAttachment(SphereComp);

}

UPawnMovementComponent* AMovementTestPawn::GetMovementComponent() const
{
	return MovementComp;
}


void AMovementTestPawn::BeginPlay()
{
	Super::BeginPlay();
	auto CM = UGameplayStatics::GetPlayerCameraManager(this, 0);
	CM->OnBlendComplete().AddUObject(this, &AMovementTestPawn::CameraBlendComplete);
	ViewActor = CM->GetViewTarget();

	
	StaticMeshComp->SetMaterial(0,UnSpottedMaterial);
}

void AMovementTestPawn::CameraBlendComplete()
{
	ViewActor=GetController()->GetViewTarget();
}



void AMovementTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMovementTestPawn::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AMovementTestPawn::MoveRight);
}

void AMovementTestPawn::MoveForward(float Val)
{
	if (Val != 0)
	{
		AddMovementInput(ViewActor->GetActorForwardVector(),Val);
	}
}

void AMovementTestPawn::MoveRight(float Val)
{
	if (Val != 0)
	{
		AddMovementInput(ViewActor->GetActorRightVector(),Val);
	}
}

void AMovementTestPawn::IsSpotted()
{
	StaticMeshComp->SetMaterial(0,SpottedMaterial);
}

void AMovementTestPawn::IsUnSpotted()
{
	StaticMeshComp->SetMaterial(0,UnSpottedMaterial);
}



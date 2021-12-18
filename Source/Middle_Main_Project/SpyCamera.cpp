// Fill out your copyright notice in the Description page of Project Settings.


#include "SpyCamera.h"

#include "MovementTestPawn.h"
#include "Components/BoxComponent.h"

ASpyCamera::ASpyCamera()
{
	BoxComp=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(500.f));
	BoxComp->SetCollisionObjectType(ECC_WorldStatic);
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComp->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	BoxComp->SetupAttachment(GetRootComponent());

	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ASpyCamera::BeginPlay()
{
	Super::BeginPlay();
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ASpyCamera::BoxBeginOverlap);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &ASpyCamera::BoxEndOverlap);
	DetectingLight->SetEnabled(false);
}

void ASpyCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bAlert)
	{
		DetectingLight->bEnabled;
		FVector a = GetWorld()->GetFirstPlayerController()->GetPawn()->GetTransform().GetLocation();
		a.Z+=450;
		FHitResult* OutSweepHitResult = nullptr;
		DetectingLight->SetActorLocation(a,false,OutSweepHitResult,ETeleportType::TeleportPhysics);
	}
	
}

void ASpyCamera::BoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	FViewTargetTransitionParams TransitionParams;
	TransitionParams.BlendTime=1.0f;
	TransitionParams.bLockOutgoing=true;
	PC->SetViewTarget(this,TransitionParams);
	if (!bIsSomethingSpotted) GetWorldTimerManager().SetTimer(SpottingTimer,this,&ThisClass::SpotPlayer,1.f,false,2);
	if (bIsSomethingSpotted)GetWorldTimerManager().ClearTimer(UnSpottingTimer);
	bAlert=true;
	DetectingLight->SetEnabled(true);
}

void ASpyCamera::BoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	FViewTargetTransitionParams TransitionParams;
	TransitionParams.BlendTime=1.0f;
	TransitionParams.bLockOutgoing=true;
	PC->SetViewTarget(PC->GetPawn(),TransitionParams);

	if (bIsSomethingSpotted) GetWorldTimerManager().SetTimer(UnSpottingTimer, this,&ThisClass::UnSpotPlayer,1.f,false,4);
	if (GetWorldTimerManager().TimerExists(SpottingTimer)) GetWorldTimerManager().ClearTimer(SpottingTimer);
	bAlert=false;
	DetectingLight->SetEnabled(false);
}


void ASpyCamera::SpotPlayer()
{
	bIsSomethingSpotted=true;
	GEngine->AddOnScreenDebugMessage(-1,2.f, FColor::Red, "Spotted");
	auto PlayerPawn = Cast<AMovementTestPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerPawn) PlayerPawn->IsSpotted();
}

void ASpyCamera::UnSpotPlayer()
{
	bIsSomethingSpotted=false;
	GEngine->AddOnScreenDebugMessage(-1,2.f, FColor::Green, "UnSpotted");
	auto PlayerPawn = Cast<AMovementTestPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerPawn) PlayerPawn->IsUnSpotted();
}


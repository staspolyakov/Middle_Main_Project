

#include "CollisionBoxWithTrigger.h"

ACollisionBoxWithTrigger::ACollisionBoxWithTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision=CreateDefaultSubobject<UStaticMeshComponent>("BoxCollision");
	BoxCollision->SetupAttachment(GetRootComponent());
}

void ACollisionBoxWithTrigger::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHitFunc);
	OnHitMulticast.AddDynamic(this, &ThisClass::OnHitMulticastEvent);
	OnHitDynamic.BindUFunction(this, "Move");
	OnHitMulticast.Add(OnHitDynamic);
	
}

void ACollisionBoxWithTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollisionBoxWithTrigger::OnComponentHitFunc(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{	
	if (OnHitMulticast.IsBound()) OnHitMulticast.Broadcast();
}

void ACollisionBoxWithTrigger::Move()
{
	FVector offset(100,0,0);
	BoxCollision->AddWorldOffset(offset);
}





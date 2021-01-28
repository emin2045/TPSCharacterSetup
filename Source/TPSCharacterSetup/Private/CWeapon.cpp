// Fill out your copyright notice in the Description page of Project Settings.


#include "CWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACWeapon::ACWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

}

// Called when the game starts or when spawned
void ACWeapon::BeginPlay()
{
	Super::BeginPlay();

}

void ACWeapon::Fire()
{
	AActor* WeaponUser = GetOwner();

	if (WeaponUser)
	{
		FHitResult HitResult;
		FVector EyesLocation;
		FRotator EyesRotation;
		WeaponUser->GetActorEyesViewPoint(EyesLocation, EyesRotation); // EyesLocation and EyesRotation have been set.

		FVector HitDirection = EyesRotation.Vector();
		FVector TraceEnd = EyesLocation + (EyesRotation.Vector() * 4000);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(WeaponUser);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, EyesLocation, TraceEnd, ECC_Visibility, QueryParams))	// return bool (LineTraceFunction)
		{
			AActor* ShootedActor = HitResult.GetActor();
			UGameplayStatics::ApplyPointDamage(ShootedActor, 20.f, HitDirection, HitResult, WeaponUser->GetInstigatorController(), this, DamageType);

		}

		DrawDebugLine(GetWorld(), EyesLocation, TraceEnd, FColor::Blue, false, 3, 0, 1);

	}
}

// Called every frame
void ACWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


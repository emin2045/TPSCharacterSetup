// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CWeapon.generated.h"

class USkeletalMeshComponet;

UCLASS()
class TPSCHARACTERSETUP_API ACWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Weapon")
	USkeletalMeshComponent* MeshComp;

	UFUNCTION(BlueprintCallable)
	void Fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

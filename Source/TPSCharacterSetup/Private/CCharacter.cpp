// Fill out your copyright notice in the Description page of Project Settings.


#include "CCharacter.h"

// Sets default values
ACCharacter::ACCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void ACCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

// Called every frame
void ACCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ACCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Up", this,&ACCharacter::AddControllerPitchInput);	// Bu fonksiyon Pawn class ýndan geliyor.
	PlayerInputComponent->BindAxis("Turn", this, &ACCharacter::AddControllerYawInput);// Bu fonksiyon Pawn class ýndan geliyor.
	
}


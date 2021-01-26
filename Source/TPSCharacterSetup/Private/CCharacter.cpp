// Fill out your copyright notice in the Description page of Project Settings.


#include "CCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACCharacter::ACCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
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

void ACCharacter::StartCrouch()
{
	Crouch();
}

void ACCharacter::EndCrouch()
{
	UnCrouch();
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

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ACCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ACCharacter::EndCrouch);
	
}


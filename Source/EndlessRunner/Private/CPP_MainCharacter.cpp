// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_MainCharacter.h"

// Sets default values
ACPP_MainCharacter::ACPP_MainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Add the pointer to the UInputMappingContext to the Engine's Subsystem for the LocalPlayer to use
	const APlayerController* PlayerController = Cast<APlayerController>(GetController());

	// Get the local player subsystem, clear the existing mappings, and add our own mapping
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem> (PlayerController -> GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	// Bind all Input Actions here
	PEI->BindAction(InputActions->InputMoveSideways, ETriggerEvent::Triggered, this, &ACPP_MainCharacter::MoveSideways);
}

void ACPP_MainCharacter::MoveSideways(const FInputActionValue& Value)
{
	if (Controller == nullptr) return;
	
	const float MoveValue = Value.Get<float>();
	const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);

	// Right/Left direction
	if (MoveValue != 0.f)
	{
		// Get right vector
		const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);
		
		AddMovementInput(Direction, MoveValue * MovementSpeed);
	}
}


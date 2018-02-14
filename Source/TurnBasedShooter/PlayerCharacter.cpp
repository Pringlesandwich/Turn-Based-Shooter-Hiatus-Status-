// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
//#include "Camera/CameraComponent.h"
//#include "Components/CapsuleComponent.h"
//#include "Components/InputComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;








}


// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}


// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind Axis created in the project settings to a function
	//Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	//Camera Controls
	InputComponent->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);
	//Jump
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::OnStopJump);
	//Dodge
	InputComponent->BindAction("Dodge", IE_Pressed, this, &APlayerCharacter::Dodge);


	//TEMPORARY REMOVAL!
	//firing projectile
	//InputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::OnFire);
	//InputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::OnReleaseFire);
	//zoom
	//InputComponent->BindAction("Aim", IE_Pressed, this, &APlayerCharacter::StartAiming);
	//InputComponent->BindAction("Aim", IE_Released, this, &APlayerCharacter::StopAiming);

}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	




}


//Getters and Setters



void APlayerCharacter::MoveForward(float Value)
{
	float MoveSpeed = Value;


	if ((Controller != NULL) && (Value != 0.0f))
	{

		FRotator Rotation = Controller->GetControlRotation(); //Rotation is eqaul to character forward in map

															  // zero pitch if walking or falling (does this allow for swimming?)
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}

		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X); // create a X axis Vector with a direction relative to the character rotation
		AddMovementInput(Direction, Value); // add movement in direction

	}

}


void APlayerCharacter::MoveRight(float Value)
{

	if ((Controller != NULL) && (Value != 0.0f))
	{

		const FRotator Rotation = Controller->GetControlRotation(); //Rotation is eqaul to character forward in map
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y); // create a Y axis Vector with a direction relative to the character rotation

		AddMovementInput(Direction, Value); // add movement in direction

	}

}


//Jump function, basic and need heavy modification???
void APlayerCharacter::OnStartJump()
{
	bPressedJump = true;
}


void APlayerCharacter::OnStopJump()
{
	bPressedJump = false;
}


//Dodge move, prototype...
void APlayerCharacter::Dodge()
{


	//Get player input as float - x and y with a value -1.0 to 1.0

	//if both are greater than 0 (might have to add deadzone for controller)

	//set player velocity to zero (HOW?)

	// get world rotation of player and convert to vector

	//create a vector from player input

	//rotate input vector around player rotation

	// add impulse through delta vector times 1000 in x and y
	









	//THIS Code Works well but makes the character feel slightly floaty and not resposive enough for someone
	// who is ment to be extremely agile and able to dodge bullets. 
/*
	FRotator Rotation = Controller->GetControlRotation(); //Rotation is eqaul to character forward in map

	if (GetCharacterMovement()->IsMovingOnGround()) // check to see if payer is on the ground, removing this could allow for air dodge!!!!!
	{

		FVector PlayerVelocity = GetCapsuleComponent()->GetPhysicsLinearVelocity(); // check to see what direction player is moving

		
		//
		

		
		GetCharacterMovement()->AddImpulse(FVector(-PlayerVelocity.X, -PlayerVelocity.Y, 0), true); // TODO - replace this with a function that instantly stops the PlayerCharacter
		//https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/GameFramework/UCharacterMovementComponent/index.html
		//https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/GameFramework/UCharacterMovementComponent/ApplyVelocityBraking/index.html
		//https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/GameFramework/UCharacterMovementComponent/CalcVelocity/index.html



		FRotator Rotation = Controller->GetControlRotation();
		FVector XDirection = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X); // create a X axis Vector with a direction relative to the character rotation
		FVector YDirection = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y); // create a Y axis Vector with a direction relative to the character rotation
		
		UE_LOG(LogTemp, Warning, TEXT("X Direction is: %s"), *XDirection.ToString());

		UE_LOG(LogTemp, Warning, TEXT("Y Direction is: %s"), *YDirection.ToString());



		GetCharacterMovement()->AddImpulse(FVector(0, 0, ZDodgeAmount), true); //Launch player into air slightly when changing gravity


		



		GetCharacterMovement()->AddImpulse
		(
			FVector
			(
				PlayerVelocity.X,
				PlayerVelocity.Y, 
				0
			), 
			true
		);

	}



	*/

	

}



//TODO this code is taken from https://wiki.unrealengine.com/First_Person_Shooter_C%2B%2B_Tutorial , I will need to edit this heavily, maybe tie this in with a firing animation

void APlayerCharacter::OnFire()
{

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fire!"));
	}

	//get gun 0 maybe through blueprint initialisation
	//tell gun to fire

}




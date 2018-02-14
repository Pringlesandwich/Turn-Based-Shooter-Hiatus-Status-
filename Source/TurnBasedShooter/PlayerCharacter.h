// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine.h" // TODO - see difference between Engine and CoreMinimal
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"



UCLASS()
class TURNBASEDSHOOTER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;





public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	





public:


	//List of custom input based actions
	UFUNCTION()
	void MoveForward(float Val);

	UFUNCTION()
	void MoveRight(float Val);

	UFUNCTION()
	void OnStartJump();

	UFUNCTION()
	void OnStopJump();

	UFUNCTION()
	void Dodge();



	//handles firing
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void OnFire();



	//Amount player moves up during dodge, edited in blueprints
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Dodge)
	float ZDodgeAmount = 2000;

	//Amount player moves sideways during dodge, edited in blueprints
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Dodge)
	float XYDodgeAmount = 4000;

};

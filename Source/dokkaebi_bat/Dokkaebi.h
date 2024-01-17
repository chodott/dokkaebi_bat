// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "Dokkaebi.generated.h"

UCLASS()
class DOKKAEBI_BAT_API ADokkaebi : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADokkaebi();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Movement
	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	void Jump() override;
	void NormalAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	float GetSpeed();

public:

	//Component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArmComponent;

	//Input
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* LookAction;
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* AttackAction;
};

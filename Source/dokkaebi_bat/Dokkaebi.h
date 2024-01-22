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

	//status
	void IncreaseMp(float DeltaTime);
	inline void ReduceMp(float Amount) { if (Mp >= Amount) Mp -= Amount; };


	float GetSpeed();
	bool GetIsFalling();

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
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* RideAction;

	//status
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Hp{ 100.f };
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Mp{ 100.f };
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MpSpeed{ 10.f };



	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float RidingSpeed{600.f};
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bJumping{ false };
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float RidingDuration{ 3.f };
	float RidingRuntime{ 0.f };
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bRiding{ false };
};

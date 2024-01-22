// Fill out your copyright notice in the Description page of Project Settings.


#include "Dokkaebi.h"
#include "DokkaebiController.h"
#include "DokkaebiAnim.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ADokkaebi::ADokkaebi()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));

	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void ADokkaebi::BeginPlay()
{
	Super::BeginPlay();

	if (ADokkaebiController* DkbController = Cast<ADokkaebiController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = Cast<UEnhancedInputLocalPlayerSubsystem>(GetController()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}

	}
	
}

// Called every frame
void ADokkaebi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRiding)
	{
		FVector ForwardVector = GetActorForwardVector();
		AddActorWorldOffset(ForwardVector * DeltaTime * RidingSpeed);
		RidingRuntime += DeltaTime;

		if (RidingRuntime > RidingDuration)
		{
			bRiding = false;
			RidingRuntime = 0.f;
			GetCharacterMovement()->GravityScale = 9.8f;
		}

	}

	else IncreaseMp(DeltaTime);

}

// Called to bind functionality to input
void ADokkaebi::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ADokkaebi::Jump);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADokkaebi::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADokkaebi::Look);
	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ADokkaebi::NormalAttack);
}

void ADokkaebi::IncreaseMp(float DeltaTime)
{
	if (Mp <= 100.f) Mp += DeltaTime * MpSpeed;
	else Mp = 100.f;
}

void ADokkaebi::Move(const FInputActionValue& value)
{
	FVector2D MoveVec = value.Get<FVector2D>();
	FRotator Rotation = Controller->GetControlRotation();
	FRotator Yaw(0.f, Rotation.Yaw, 0.f);
	FVector ForwardVec = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardVec, MoveVec.Y);
	const FVector RightVec = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightVec, MoveVec.X);
}

void ADokkaebi::Jump()
{
	Super::Jump();

	if (bJumping)
	{
		bRiding = true;
		UCharacterMovementComponent* Movement = GetCharacterMovement();
		Movement->GravityScale = 0.f;
		Movement->Velocity = FVector::Zero();
		ReduceMp(10.f);
	}
	bJumping = true;
}

void ADokkaebi::NormalAttack()
{
	UDokkaebiAnim* DokkaebiAnim = Cast<UDokkaebiAnim>(GetMesh()->GetAnimInstance());

	if (DokkaebiAnim)
	{
		DokkaebiAnim->Attack();
	}
}

float ADokkaebi::GetSpeed()
{
	return GetVelocity().Length();
}

bool ADokkaebi::GetIsFalling()
{
	return GetCharacterMovement()->IsFalling();
}

void ADokkaebi::Look(const FInputActionValue& value)
{
	FVector2D LookVec = value.Get<FVector2D>();
	AddControllerYawInput(LookVec.X);
	AddControllerPitchInput(LookVec.Y);
}


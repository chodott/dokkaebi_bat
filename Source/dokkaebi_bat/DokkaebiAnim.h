// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DokkaebiAnim.generated.h"

/**
 * 
 */
UCLASS()
class DOKKAEBI_BAT_API UDokkaebiAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
		UDokkaebiAnim();

		virtual void NativeUpdateAnimation(float DeltaSeconds) override;

		void Attack();

public:

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UAnimMontage* BattleMontage;


		UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Speed;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Direction;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bJumping;
	
};

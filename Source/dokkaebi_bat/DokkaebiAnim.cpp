

// Fill out your copyright notice in the Description page of Project Settings.


#include "DokkaebiAnim.h"
#include "Dokkaebi.h"

UDokkaebiAnim::UDokkaebiAnim()
{

}

void UDokkaebiAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ADokkaebi* Dokkaebi = Cast<ADokkaebi>(TryGetPawnOwner());

	if(Dokkaebi)
	{ 
	Speed = Dokkaebi->GetSpeed();
	Direction = CalculateDirection(Dokkaebi->GetVelocity(), Dokkaebi->GetActorRotation());
	}
}

void UDokkaebiAnim::Attack()
{
	Montage_Play(BattleMontage, 1.0f);
	//Montage_JumpToSection();
}


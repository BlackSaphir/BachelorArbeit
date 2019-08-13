// Fill out your copyright notice in the Description page of Project Settings.


#include "BA_Pawn.h"

// Sets default values
ABA_Pawn::ABA_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABA_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABA_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABA_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


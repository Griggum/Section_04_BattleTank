// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s possessed by %s"), *ControlledTank->GetName(), *this->GetName())
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller not finding player"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s found by %s"), *PlayerTank->GetName(), *this->GetName())
	}
}

ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}



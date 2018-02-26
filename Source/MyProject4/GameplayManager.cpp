// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayManager.h"
#include "Engine.h"


// Sets default values
AGameplayManager::AGameplayManager()
{
	score = 0;
	lives = 5;
	level = 0;
	GameState = EGameStateEnum::GE_NotStarted;
}

// Called when the game starts or when spawned
void AGameplayManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandler, this, &AGameplayManager::GenerateRandomSequence, 1.0f, false, 5.0f);
}

void AGameplayManager::GenerateRandomSequence()
{
	EBlockEnum NewBlock;
		if (GameState == EGameStateEnum::GE_NotStarted) {
			for (int i = 0; i < 4; i++) {
				NewBlock = static_cast<EBlockEnum>(FMath::RandRange(0, 4));
				SoundsSequence.Add(NewBlock);
			}
			GameState = EGameStateEnum::GE_Started;
		}
		else {
			NewBlock = static_cast<EBlockEnum>(FMath::RandRange(0, 4));
			SoundsSequence.Add(NewBlock);
		}
}


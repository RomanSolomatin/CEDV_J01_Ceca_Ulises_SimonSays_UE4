#pragma once


#include "Engine.h"
#include "Record.generated.h"


USTRUCT()
struct MYPROJECT4_API FRecord
{
	GENERATED_BODY()


	UPROPERTY()
		FString PlayerName;
	UPROPERTY()
		int16 Score;

	FString GetPlayerName()
	{
		return PlayerName;
	}

	int16 GetScore() 
	{
		return Score;
	}

	FRecord(FString PlayerName, int16 Score, int8 Level)
	{
		this->PlayerName = PlayerName;
		this->Score = Score;
	}

	FRecord()
	{
		this->PlayerName = "";
		this->Score = 0;
	}

	FORCEINLINE bool operator<(const FRecord &Other) const
	{
		return Score > Other.Score;
	}
};
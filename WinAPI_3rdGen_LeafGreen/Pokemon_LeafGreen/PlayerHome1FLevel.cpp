#include "PlayerHome1FLevel.h"
#include "Player.h"
#include "PlayerHome1FGround.h"
#include "PlayerHomeDoor.h"
#include "PlayerHome1FStairs.h"
#include "WestFieldLevel.h"
#include "PlayerHome2FLevel.h"
#include "global.h"

UPlayerHome1FLevel::UPlayerHome1FLevel()
{
}

UPlayerHome1FLevel::~UPlayerHome1FLevel()
{
}

void UPlayerHome1FLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	Ground = SpawnActor<PlayerHome1FGround>();
	Door = SpawnActor<APlayerHomeDoor>();
	Stairs = SpawnActor<APlayerHome1FStairs>();

	Door->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (144 + (FTileScale)) * FScaleMultiple });
	Stairs->SetActorLocation({ (176 + FTileScale + (FTileScale / 2)) * FScaleMultiple , (32 + (FTileScale / 2)) * FScaleMultiple });
}

void UPlayerHome1FLevel::Tick(float _DeltaTime)
{
}

void UPlayerHome1FLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	if (nullptr != _PrevLevel)
	{
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
		if (UEngineString::ToUpper("WestFieldLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Up);
			GetPlayer()->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
		}
		else if (UEngineString::ToUpper("PlayerHome2FLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Left);
			GetPlayer()->SetActorLocation({ (160 + (FTileScale / 2)) * FScaleMultiple , (32) * FScaleMultiple });
		}

		if (UEngineString::ToUpper("WestFieldLevel") != Field->GetName())
		{
			ChangeBGM("Pallet_Town.mp3");
		}
		else if (UEngineString::ToUpper("PlayerHome2FLevel") != Field->GetName())
		{
			//ChangeBGM("Pallet_Town.mp3");
		}
	}
}

void UPlayerHome1FLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{

	}
}
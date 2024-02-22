#include "PlayerHome1FLevel.h"
#include "Player.h"
#include "PlayerHome1FGround.h"
#include "PlayerHomeDoor.h"
#include "WestFieldLevel.h"
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

	Door->SetActorLocation({ (64 + FTileScale) * FScaleMultiple , (144 + (FTileScale)) * FScaleMultiple });

	Player->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
}

void UPlayerHome1FLevel::Tick(float _DeltaTime)
{
}

void UPlayerHome1FLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	Ground->SetActive(true);
	Door->SetActive(true);
	if (nullptr != _PrevLevel)
	{
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
		if (UEngineString::ToUpper("WestFieldLevel") == Field->GetName())
		{
			GetPlayer()->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
			GetPlayer()->SetCharacterDir(EDirState::Up);
		}
	}
}

void UPlayerHome1FLevel::LevelEnd(ULevel* _NextLevel)
{
	Ground->SetActive(false);
	Door->SetActive(false);
	if (nullptr != _NextLevel)
	{
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_NextLevel);
		if (UEngineString::ToUpper("WestFieldLevel") == Field->GetName())
		{
			GetPlayer()->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
			GetPlayer()->SetCharacterDir(EDirState::Down);
		}
	}
}
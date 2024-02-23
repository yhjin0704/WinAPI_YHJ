#include "WestFieldLevel.h"
#include "Player.h"
#include "WestFieldGround.h"
#include "PlayerHomeDoorOut.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>
#include "global.h"

UWestFieldLevel::UWestFieldLevel()
{
}

UWestFieldLevel::~UWestFieldLevel()
{
}

void UWestFieldLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	Ground = SpawnActor<AWestFieldGround>();
	Door = SpawnActor<APlayerHomeDoorOut>();

	Door->SetActorLocation({ (1136 + FTileScale) * FScaleMultiple , (2016 - FTileScale) * FScaleMultiple });

	Player->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
}

void UWestFieldLevel::Tick(float _DeltaTime)
{
}

void UWestFieldLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();

	BGMPlayer = UEngineSound::SoundPlay("Pallet_Town.mp3");
	BGMPlayer.Loop();

	if (nullptr != _PrevLevel)
	{
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
		if (UEngineString::ToUpper("PlayerHome1FLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Down);
			GetPlayer()->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
		}
	}
}

void UWestFieldLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_NextLevel);
		if (UEngineString::ToUpper("PlayerHome1FLevel") == Field->GetName())
		{
			GetPlayer()->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
			GetPlayer()->SetCharacterDir(EDirState::Up);
		}
	}
}
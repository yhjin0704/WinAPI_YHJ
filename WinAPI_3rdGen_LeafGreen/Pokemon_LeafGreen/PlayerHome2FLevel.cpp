#include "PlayerHome2FLevel.h"
#include "Player.h"
#include "PlayerHome2FGround.h"
#include "PlayerHome2FStairs.h"
#include "PlayerHome1FLevel.h"
#include "global.h"

UPlayerHome2FLevel::UPlayerHome2FLevel()
{
}

UPlayerHome2FLevel::~UPlayerHome2FLevel()
{
}

void UPlayerHome2FLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	Ground = SpawnActor<PlayerHome2FGround>();
	Stairs = SpawnActor<APlayerHome2FStairs>();

	Stairs->SetActorLocation({ (144) * FScaleMultiple , (48 + (FTileScale / 2)) * FScaleMultiple });

	Player->SetActorLocation({ (96 + (FTileScale / 2)) * FScaleMultiple , (112) * FScaleMultiple });
}

void UPlayerHome2FLevel::Tick(float _DeltaTime)
{
}

void UPlayerHome2FLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	if (nullptr != _PrevLevel)
	{
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
		if (UEngineString::ToUpper("PlayerHome1FLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Right);
			GetPlayer()->SetActorLocation({ (160 + (FTileScale / 2)) * FScaleMultiple , (48) * FScaleMultiple });
		}

		if (UEngineString::ToUpper("PlayerHome1FLevel") != Field->GetName())
		{
			ChangeBGM("Pallet_Town.mp3");
		}
	}
}

void UPlayerHome2FLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
	}
}
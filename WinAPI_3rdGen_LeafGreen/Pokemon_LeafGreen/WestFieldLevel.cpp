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

	Door->SetActorLocation({ (1136 + FTileScale / 2) * FScaleMultiple , (2016 - FTileScale) * FScaleMultiple });

	Player->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
}

void UWestFieldLevel::Tick(float _DeltaTime)
{
	if (GetPlayer()->GetActorLocation().iY() == (1888 * IScaleMultiple))
	{
		if ("Route_1.mp3" != PrevMusic)
		{
			ChangeBGM("Route_1.mp3");
		}
	}
	if (GetPlayer()->GetActorLocation().iY() == (1904 * IScaleMultiple))
	{
		if ("Pallet_Town.mp3" != PrevMusic)
		{
			ChangeBGM("Pallet_Town.mp3");
		}
	}
}

void UWestFieldLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();

	if (nullptr != _PrevLevel)
	{
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
		if (UEngineString::ToUpper("PlayerHome1FLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Down);
			GetPlayer()->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
		}
	}
	else
	{
		ChangeBGM("Pallet_Town.mp3");
	}
}

void UWestFieldLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
	}
}
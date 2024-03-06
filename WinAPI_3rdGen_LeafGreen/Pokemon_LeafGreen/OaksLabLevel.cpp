#include "OaksLabLevel.h"

UOaksLabLevel::UOaksLabLevel()
{
}

UOaksLabLevel::~UOaksLabLevel()
{
}

void UOaksLabLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	IsOutside = false;

	Ground = SpawnActor<AOaksLabGround>();
	Door = SpawnActor<AOaksLabDoor>();

	Door->SetActorLocation({ (80 + (FTileScale / 2)) * FScaleMultiple , (160 + (FTileScale / 2)) * FScaleMultiple });
}

void UOaksLabLevel::Tick(float _DeltaTime)
{
}

void UOaksLabLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	GetPlayer()->SetMoveType(PlayerHelper::PlayerMoveType);
	if (EMoveType::Bike == GetPlayer()->GetMoveType())
	{
		GetPlayer()->SetMoveType(PlayerHelper::PrevMoveType);
	}

	UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
	if (nullptr != Field && UEngineString::ToUpper("TitleLevel4") != Field->GetName())
	{
		if (UEngineString::ToUpper("WestFieldLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Up);
			GetPlayer()->SetActorLocation({ (80 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
		}

		if (UEngineString::ToUpper("WestFieldLevel") != Field->GetName())
		{
			Global::ChangeBGM("Pallet_Town.mp3");
		}
	}
	else
	{
		Global::ChangeBGM("Pallet_Town.mp3");
	}
}

void UOaksLabLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
		PlayerHelper::PlayerMoveType = GetPlayer()->GetMoveType();
	}
}
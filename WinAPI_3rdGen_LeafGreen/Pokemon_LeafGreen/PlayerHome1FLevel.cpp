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

	PlayerHome1FGround* Ground = SpawnActor<PlayerHome1FGround>();
	APlayerHomeDoor* Door = SpawnActor<APlayerHomeDoor>();

	Door->SetActorLocation({ (64 + FTileScale) * FScaleMultiple , (144 + (FTileScale / 2)) * FScaleMultiple });

	Player->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
}

void UPlayerHome1FLevel::Tick(float _DeltaTime)
{
}

void UPlayerHome1FLevel::LevelStart(ULevel* _PrevLevel)
{
}

void UPlayerHome1FLevel::LevelEnd(ULevel* _NextLevel)
{
	
	UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_NextLevel);
	if (UEngineString::ToUpper("WestFieldLevel") == Field->GetName())
	{
		Field->GetPlayer()->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
	}
	
}
#include "WestFieldLevel.h"
#include "Player.h"
#include "WestFieldGround.h"
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

	AWestFieldGround* Ground = SpawnActor<AWestFieldGround>();

	Player->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
}

void UWestFieldLevel::Tick(float _DeltaTime)
{
}

void UWestFieldLevel::LevelStart(ULevel* _PrevLevel)
{
}

void UWestFieldLevel::LevelEnd(ULevel* _NextLevel)
{
}
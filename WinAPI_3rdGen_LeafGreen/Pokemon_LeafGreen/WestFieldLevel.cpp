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
	Ground->SetMapImage("West_Map.png");
	Ground->SetColMapImage("Col_West_Map.png");
	Player->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
}

void UWestFieldLevel::Tick(float _DeltaTime)
{
}
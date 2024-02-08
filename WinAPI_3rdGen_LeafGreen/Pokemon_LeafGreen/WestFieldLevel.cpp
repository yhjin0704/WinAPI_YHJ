#include "WestFieldLevel.h"
#include "Player.h"
#include "WestFieldGround.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
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
	
	FieldPath.Move("WestField");

	AWestFieldGround* Ground = SpawnActor<AWestFieldGround>();
	Ground->SetMapImage("West_Map.png");
	Ground->SetColMapImage("Col_West_Map.png");
}
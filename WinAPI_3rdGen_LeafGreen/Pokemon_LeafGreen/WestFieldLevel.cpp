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
	UEngineDirectory NewPath;
	NewPath.MoveParent();
	NewPath.Move("Resources");
	NewPath.Move("Field");
	NewPath.Move("WestField");

	this->SpawnActor<AWestFieldGround>();
}
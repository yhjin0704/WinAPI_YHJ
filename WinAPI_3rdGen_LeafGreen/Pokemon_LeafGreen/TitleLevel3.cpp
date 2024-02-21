#include "TitleLevel3.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "TitleActor3.h"

UTitleLevel3::UTitleLevel3()
{
}

UTitleLevel3::~UTitleLevel3()
{
}

void UTitleLevel3::BeginPlay()
{
	ULevel::BeginPlay();

	this->SpawnActor<ATitleActor3>();
}
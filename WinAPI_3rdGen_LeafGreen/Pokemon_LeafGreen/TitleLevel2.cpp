#include "TitleLevel2.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "TitleActor2.h"

UTitleLevel2::UTitleLevel2()
{
}

UTitleLevel2::~UTitleLevel2()
{
}

void UTitleLevel2::BeginPlay()
{
	ULevel::BeginPlay();

	this->SpawnActor<ATitleActor2>();
}
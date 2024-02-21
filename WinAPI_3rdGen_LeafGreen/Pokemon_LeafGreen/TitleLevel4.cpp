#include "TitleLevel4.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "TitleActor4.h"

UTitleLevel4::UTitleLevel4()
{
}

UTitleLevel4::~UTitleLevel4()
{
}

void UTitleLevel4::BeginPlay()
{
	ULevel::BeginPlay();

	this->SpawnActor<ATitleActor4>();
}
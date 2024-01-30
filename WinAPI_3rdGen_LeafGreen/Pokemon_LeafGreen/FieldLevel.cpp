#include "FieldLevel.h"
#include "Player.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>

UFieldLevel::UFieldLevel()
{
}

UFieldLevel::~UFieldLevel()
{
}

void UFieldLevel::BeginPlay()
{
	UEngineDirectory NewPath;

	NewPath.MoveParent();

	//NewPath.Move("Resources");

	std::list<UEngineFile> AllFileList = NewPath.AllFile({ ".png", ".bmp" }, true);

	this->SpawnActor<Player>();
}

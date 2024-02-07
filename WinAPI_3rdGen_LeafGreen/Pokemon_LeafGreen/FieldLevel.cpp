#include "FieldLevel.h"
#include "Player.h"
#include "Ground.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include "global.h"

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
	NewPath.Move("Resources");
	NewPath.Move("Field");

	std::list<UEngineFile> AllFileList = NewPath.AllFile({ ".png", ".bmp" }, true);
	
	for (UEngineFile& File : AllFileList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Down.png", ITile_Scale, ITile_Scale * 2);

	this->SpawnActor<APlayer>();
	this->SpawnActor<AGround>();
}
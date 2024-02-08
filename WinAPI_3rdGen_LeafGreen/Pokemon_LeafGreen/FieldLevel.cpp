#include "FieldLevel.h"
#include "Player.h"
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
	
	FieldPath.MoveParent();
	FieldPath.Move("Resources");
	FieldPath.Move("Field");
	FieldPath.Move("Player");

	std::list<UEngineFile> AllFileList = FieldPath.AllFile({ ".png", ".bmp" }, true);
	
	for (UEngineFile& File : AllFileList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Down.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Up.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Left.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Right.png", 4, 1);

	APlayer* Player = SpawnActor<APlayer>();
}
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
	ULevel::BeginPlay();

	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Down.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Up.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Left.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Right.png", 4, 1);

	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Walk_Down_Jump.png", 7, 2);

	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Run_Down.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Run_Up.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Run_Left.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Run_Right.png", 4, 1);

	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Bike_Down.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Bike_Up.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Bike_Left.png", 4, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Bike_Right.png", 4, 1);

	UEngineResourcesManager::GetInst().CuttingImage("Player_Boy_Bike_Down_Jump.png", 7, 2);

	Player = SpawnActor<APlayer>();
	Player->SetCharacterName("Player_Boy");

	MenuCursor = SpawnActor<AMenuCursor>();
}

void UFieldLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}
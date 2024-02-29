#include "Pokemon3rdGen_Core.h"
#include "Global.h"
#include "Player.h"
#include "TitleLevel1.h"
#include "TitleLevel2.h"
#include "TitleLevel3.h"
#include "TitleLevel4.h"
#include "WestFieldLevel.h"
#include "PlayerHome1FLevel.h"
#include "PlayerHome2FLevel.h"
#include "RivalHomeLevel.h"
#include "MyPokemonLevel.h"
#include "MyBagLevel.h"
#include "MyTrainerCardLevel.h"
#include <EnginePlatform\EngineSound.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>

Pokemon3rdGen_Core::Pokemon3rdGen_Core()
	: UEngineCore()
{
}

Pokemon3rdGen_Core::~Pokemon3rdGen_Core()
{
}

// 게임시작
void Pokemon3rdGen_Core::BeginPlay()
{
	MainWindow.SetWindowScale({ FScreen_X, FScreen_Y });
	MainWindow.SetClearColor(Color8Bit::BlackA);
	SetFrame(60);

	{
		FieldPath.MoveParent();
		FieldPath.Move("Resources");
		FieldPath.Move("Field");

		std::list<UEngineFile> AllFieldGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllFieldGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		std::list<UEngineFile> NewSoundsList = FieldPath.AllFile({ ".wav", ".mp3" }, true);

		for (UEngineFile& File : NewSoundsList)
		{
			UEngineSound::Load(File.GetFullPath());
		}
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("UI");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("Pokemon");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}

		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Front_Back_1.png", 12, 17);
	}

	CreateLevel<UTitleLevel1>("TitleLevel1");
	CreateLevel<UTitleLevel2>("TitleLevel2");
	CreateLevel<UTitleLevel3>("TitleLevel3");
	CreateLevel<UTitleLevel4>("TitleLevel4");

	CreateLevel<UWestFieldLevel>("WestFieldLevel");
	CreateLevel<UPlayerHome1FLevel>("PlayerHome1FLevel");
	CreateLevel<UPlayerHome2FLevel>("PlayerHome2FLevel");
	CreateLevel<URivalHomeLevel>("RivalHomeLevel");

	CreateLevel<UMyPokemonLevel>("MyPokemonLevel");
	CreateLevel<UMyBagLevel>("MyBagLevel");
	CreateLevel<UMyTrainerCardLevel>("MyTrainerCardLevel");

	ChangeLevel("TitleLevel1");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('9'))
	{
		GEngine->EngineDebugSwitch();
	}
}

void Pokemon3rdGen_Core::End()
{
}
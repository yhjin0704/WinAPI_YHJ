#include "Pokemon3rdGen_Core.h"
#include "Global.h"
#include "Player.h"
#include "TitleLevel1.h"
#include "TitleLevel2.h"
#include "TitleLevel3.h"
#include "TitleLevel4.h"
#include "WestFieldLevel.h"
#include "PlayerHome1FLevel.h"
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

	FieldPath.MoveParent();
	FieldPath.Move("Resources");
	FieldPath.Move("Field");

	std::list<UEngineFile> AllFileList = FieldPath.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : AllFileList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	CreateLevel<UTitleLevel1>("TitleLevel1");
	CreateLevel<UTitleLevel2>("TitleLevel2");
	CreateLevel<UTitleLevel3>("TitleLevel3");
	CreateLevel<UTitleLevel4>("TitleLevel4");

	CreateLevel<UWestFieldLevel>("WestFieldLevel");
	CreateLevel<UPlayerHome1FLevel>("PlayerHome1FLevel");

	ChangeLevel("WestFieldLevel");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
}

void Pokemon3rdGen_Core::End()
{
}
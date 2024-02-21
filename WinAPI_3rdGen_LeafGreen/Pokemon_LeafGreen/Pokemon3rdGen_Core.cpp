#include "Pokemon3rdGen_Core.h"
#include "Global.h"
#include "Player.h"
#include "TitleLevel1.h"
#include "TitleLevel2.h"
#include "WestFieldLevel.h"

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

	CreateLevel<UTitleLevel1>("TitleLevel1");
	CreateLevel<UTitleLevel2>("TitleLevel2");
	CreateLevel<UWestFieldLevel>("WestFieldLevel");

	ChangeLevel("TitleLevel1");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
}

void Pokemon3rdGen_Core::End()
{
}
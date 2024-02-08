#include "Pokemon3rdGen_Core.h"
#include "Global.h"
#include "Player.h"
#include "TitleLevel.h"
#include "FieldLevel.h"

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

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UFieldLevel>("WestFieldLevel");

	ChangeLevel("TitleLevel");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
}

void Pokemon3rdGen_Core::End()
{
}
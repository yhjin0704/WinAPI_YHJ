#include "Pokemon3rdGen_Core.h"
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
	MainWindow.SetWindowScale({ 240 * 3.0f, 160 * 3.0f });

	SetFrame(60);

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UFieldLevel>("FieldLevel");

	ChangeLevel("FieldLevel");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
}

void Pokemon3rdGen_Core::End()
{
}
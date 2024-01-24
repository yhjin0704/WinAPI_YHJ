#include "Pokemon3rdGen_Core.h"
#include "TitleLevel.h"

Pokemon3rdGen_Core::Pokemon3rdGen_Core()
{
}

Pokemon3rdGen_Core::~Pokemon3rdGen_Core()
{
}

// 게임시작
void Pokemon3rdGen_Core::BeginPlay()
{
	CreateLevel<UTitleLevel>("TitleLevel");

	ChangeLevel("TitleLevel");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
	int a = 0;
}

void Pokemon3rdGen_Core::End()
{
	int a = 0;
}
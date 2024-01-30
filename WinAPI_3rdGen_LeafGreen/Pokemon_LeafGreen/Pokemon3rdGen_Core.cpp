#include "Pokemon3rdGen_Core.h"
#include "Player.h"
#include "TitleLevel.h"
#include "FieldLevel.h"

Pokemon3rdGen_Core::Pokemon3rdGen_Core()
	: EngineCore()
{
}

Pokemon3rdGen_Core::~Pokemon3rdGen_Core()
{
}

// ���ӽ���
void Pokemon3rdGen_Core::BeginPlay()
{
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
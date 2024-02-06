#include "Ground.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include "Global.h"

AGround::AGround()
{
}

AGround::~AGround()
{
}

void AGround::BeginPlay()
{
	AActor::BeginPlay();

	SetActorLocation({ 0, 0 });

	Renderer = CreateImageRenderer(-10);
	Renderer->SetImage("West_Map.png");
	Renderer->SetTransform({ {FGBAScreen_X * 1.5f, FGBAScreen_Y * 1.5f}, {FScreen_X, FScreen_Y} });
	Renderer->SetImageCuttingTransform({ {1146, 3510}, {FGBAScreen_X, FGBAScreen_Y} });
}

void AGround::Tick(float _DeltaTime)
{
}


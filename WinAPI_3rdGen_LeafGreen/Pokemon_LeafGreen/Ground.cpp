#include "Ground.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>

AGround::AGround()
{
}

AGround::~AGround()
{
}

void AGround::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(0);
	Renderer->SetImage("Full_Map.png");

	SetActorLocation({ 0, 0 });

	Renderer->SetTransform({ {360, 240}, {720, 480} });
	Renderer->SetImageCuttingTransform({ {1100, 4250}, {240, 160} });
}

void AGround::Tick(float _DeltaTime)
{
}
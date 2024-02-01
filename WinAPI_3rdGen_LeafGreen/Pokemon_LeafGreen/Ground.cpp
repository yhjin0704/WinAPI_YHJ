#include "Ground.h"
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

	Renderer = CreateImageRenderer();
	Renderer->SetImage("West_Full_Map.bmp");
	SetActorLocation({ 0, 0 });
	Renderer->SetTransform({ {120 * 3, 80 * 3}, {100, 100} });
	Renderer->SetImageCuttingTransform({ {0,0}, {200, 200} });
}

void AGround::Tick(float _DeltaTime)
{
	if (true == EngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Right * 600.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Left * 600.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('W'))
	{
		AddActorLocation(FVector::Down * 600.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('S'))
	{
		AddActorLocation(FVector::Up * 600.0f * _DeltaTime);
	}
}
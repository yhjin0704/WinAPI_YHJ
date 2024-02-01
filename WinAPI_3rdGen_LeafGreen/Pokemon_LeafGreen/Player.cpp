#include "Player.h"
#include <EnginePlatform\EngineInput.h>

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer();
	Renderer->SetImage("player alone.png");
	SetActorLocation({ 120 * 3, 80 * 3 });
	Renderer->SetTransform({ {120 * 3, 80 * 3}, {100, 100} });
	Renderer->SetImageCuttingTransform({ {0,0}, {200, 200} });
}

void APlayer::Tick(float _DeltaTime)
{
	/*if (true == EngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Left * 600.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Right * 600.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('W'))
	{
		AddActorLocation(FVector::Up * 600.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('S'))
	{
		AddActorLocation(FVector::Down * 600.0f * _DeltaTime);
	}*/
}
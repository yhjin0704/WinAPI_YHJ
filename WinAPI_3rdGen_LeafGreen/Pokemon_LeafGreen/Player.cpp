#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineCore\EngineResourcesManager.h>
#include "Global.h"

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();



	SetActorLocation({ FHSceen_X , FHSceen_Y });

	Renderer = CreateImageRenderer(0);
	Renderer->SetImage("Player_Boy_Walk_Down.png");
	Renderer->SetTransform({ {0, 0}, {FTile_Scale, FTile_Scale * 2} });
	Renderer->CreateAnimation("Boy_Idle_Down", "Player_Boy_Walk_Down.png", 0, 3, 0.1f, true);

	Renderer->ChangeAnimation("Boy_Idle_Down");
}

void APlayer::Tick(float _DeltaTime)
{
	if (true == EngineInput::IsPress('A'))
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
	}
}
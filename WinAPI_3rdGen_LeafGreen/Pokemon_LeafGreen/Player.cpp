#include "Player.h"
#include <EnginePlatform\EngineInput.h>

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	AActor::BeginPlay();

	//Renderer = CreateImageRenderer(0);

	{
		Renderer = CreateImageRenderer(0);
		Renderer->SetPosition({ 0, 30 });
		Renderer->SetScale({ 8, 8 });
	}

	SetActorLocation({ 100, 100 });
	SetActorScale({ 8, 8 });
}

void Player::Tick(float _DeltaTime)
{
	if (true == EngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Left * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Right * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('W'))
	{
		AddActorLocation(FVector::Up * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('S'))
	{
		AddActorLocation(FVector::Down * 500.0f * _DeltaTime);
	}
}
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

	SetActorLocation({ FHSceen_X , (FHSceen_Y - (FScreen_Tile_Scale / 2)) });

	Renderer = CreateImageRenderer(Player);
	Renderer->SetImage("Player_Boy_Walk_Down.png");
	Renderer->SetTransform({ {0, 0}, {FScreen_Tile_Scale, FScreen_Tile_Scale * 2} });

	Renderer->CreateAnimation("Boy_Walk_Down_R", "Player_Boy_Walk_Down.png", 0, 1, 0.5f, false);
	Renderer->CreateAnimation("Boy_Walk_UP_R", "Player_Boy_Walk_UP.png", 0, 1, 0.5f, false);
	Renderer->CreateAnimation("Boy_Walk_Left_R", "Player_Boy_Walk_Left.png", 0, 1, 0.5f, false);
	Renderer->CreateAnimation("Boy_Walk_Right_R", "Player_Boy_Walk_Right.png", 0, 1, 0.5f, false);

	Renderer->CreateAnimation("Boy_Walk_Down_L", "Player_Boy_Walk_Down.png", 2, 3, 0.5f, false);
	Renderer->CreateAnimation("Boy_Walk_UP_L", "Player_Boy_Walk_UP.png", 2, 3, 0.5f, false);
	Renderer->CreateAnimation("Boy_Walk_Left_L", "Player_Boy_Walk_Left.png", 2, 3, 0.5f, false);
	Renderer->CreateAnimation("Boy_Walk_Right_L", "Player_Boy_Walk_Right.png", 2, 3, 0.5f, false);

	Renderer->SetImage("Player_Boy_Walk_Down.png", 1);
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (true == UEngineInput::IsPress('S'))
	{
		if (EPlayerMoveState::Walk == MoveState)
		{
			if (false == PrevFootRight)
			{
				Renderer->ChangeAnimation("Boy_Walk_Down_R");
				PrevFootRight = true;
			}
			else
			{
				Renderer->ChangeAnimation("Boy_Walk_Down_L");
				PrevFootRight = false;
			}
			AddActorLocation(FVector::Down * 600.0f * _DeltaTime);
		}
		PrevDirinput = EDirState::Down;
	}

	if (true == UEngineInput::IsPress('W'))
	{
		if (EPlayerMoveState::Walk == MoveState)
		{
			if (false == PrevFootRight)
			{
				Renderer->ChangeAnimation("Boy_Walk_Up_R");
				PrevFootRight = true;
			}
			else
			{
				Renderer->ChangeAnimation("Boy_Walk_Up_L");
				PrevFootRight = false;
			}
			AddActorLocation(FVector::Up * 600.0f * _DeltaTime);
		}
		PrevDirinput = EDirState::Up;
	}

	if (true == UEngineInput::IsPress('A'))
	{
		if (EPlayerMoveState::Walk == MoveState)
		{
			if (false == PrevFootRight)
			{
				Renderer->ChangeAnimation("Boy_Walk_Left_R");
				PrevFootRight = true;
			}
			else
			{
				Renderer->ChangeAnimation("Boy_Walk_Left_L");
				PrevFootRight = false;
			}
			AddActorLocation(FVector::Left * 600.0f * _DeltaTime);
		}
		PrevDirinput = EDirState::Left;
	}

	if (true == UEngineInput::IsPress('D'))
	{
		if (EPlayerMoveState::Walk == MoveState)
		{
			if (false == PrevFootRight)
			{
				Renderer->ChangeAnimation("Boy_Walk_Right_R");
				PrevFootRight = true;
			}
			else
			{
				Renderer->ChangeAnimation("Boy_Walk_Right_L");
				PrevFootRight = false;
			}
			AddActorLocation(FVector::Right * 600.0f * _DeltaTime);
		}
		PrevDirinput = EDirState::Right;
	}

	//if (true == EngineKey::Free)
	
}
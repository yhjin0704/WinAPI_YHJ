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

	Renderer = CreateImageRenderer(Player);
	Renderer->SetImage("Player_Boy_Walk_Down.png");
	Renderer->SetTransform({ {0, 0}, {FScreenTileScale, FScreenTileScale * 2} });

	
	Renderer->CreateAnimation("Boy_Walk_Down_R", "Player_Boy_Walk_Down.png", 0, 1, (WalkTime / 2), false);
	Renderer->CreateAnimation("Boy_Walk_UP_R", "Player_Boy_Walk_UP.png", 0, 1, (WalkTime / 2), false);
	Renderer->CreateAnimation("Boy_Walk_Left_R", "Player_Boy_Walk_Left.png", 0, 1, (WalkTime / 2), false);
	Renderer->CreateAnimation("Boy_Walk_Right_R", "Player_Boy_Walk_Right.png", 0, 1, (WalkTime / 2), false);

	Renderer->CreateAnimation("Boy_Walk_Down_L", "Player_Boy_Walk_Down.png", 2, 3, (WalkTime / 2), false);
	Renderer->CreateAnimation("Boy_Walk_UP_L", "Player_Boy_Walk_UP.png", 2, 3, (WalkTime / 2), false);
	Renderer->CreateAnimation("Boy_Walk_Left_L", "Player_Boy_Walk_Left.png", 2, 3, (WalkTime / 2), false);
	Renderer->CreateAnimation("Boy_Walk_Right_L", "Player_Boy_Walk_Right.png", 2, 3, (WalkTime / 2), false);

	Renderer->SetImage("Player_Boy_Walk_Down.png", 1);
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	GetWorld()->SetCameraPos(GetActorLocation() - FVector(FHSceen_X, FHSceen_Y));

	InputDelayCheck(_DeltaTime);

	if (true == IsPlayerMove)
	{
		if (EPlayerMoveState::Walk == MoveState)
		{
			if (EDirState::Down == PrevDirinput)
			{
				if (false == IsActionDelay)
				{
					IsPlayerMove = false;
					return;
				}
				float DeltaTimeMove = FScreenTileScale / FWalkTime;
				AddActorLocation(FVector::Down * DeltaTimeMove * _DeltaTime);
				
			}

			if (EDirState::Up == PrevDirinput)
			{
				if (false == IsActionDelay)
				{
					IsPlayerMove = false;
					return;
				}
				float DeltaTimeMove = FScreenTileScale / FWalkTime;
				AddActorLocation(FVector::Up * DeltaTimeMove * _DeltaTime);
			}

			if (EDirState::Left == PrevDirinput)
			{
				if (false == IsActionDelay)
				{
					IsPlayerMove = false;
					return;
				}
				float DeltaTimeMove = FScreenTileScale / FWalkTime;
				AddActorLocation(FVector::Left * DeltaTimeMove * _DeltaTime);
			}

			if (EDirState::Right == PrevDirinput)
			{
				if (false == IsActionDelay)
				{
					IsPlayerMove = false;
					return;
				}
				float DeltaTimeMove = FScreenTileScale / FWalkTime;
				AddActorLocation(FVector::Right * DeltaTimeMove * _DeltaTime);
			}
		}
	}

	if (true == UEngineInput::IsPress('S'))
	{
		if (false == IsActionDelay)
		{
			if (EPlayerMoveState::Walk == MoveState)
			{
				CurDelayTime = FWalkTime;
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
				IsPlayerMove = true;
			}
			PrevDirinput = EDirState::Down;
		}
	}

	if (true == UEngineInput::IsPress('W'))
	{
		if (false == IsActionDelay)
		{
			if (EPlayerMoveState::Walk == MoveState)
			{
				CurDelayTime = FWalkTime;
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
				IsPlayerMove = true;
			}
			PrevDirinput = EDirState::Up;
		}
	}

	if (true == UEngineInput::IsPress('A'))
	{
		if (false == IsActionDelay)
		{
			if (EPlayerMoveState::Walk == MoveState)
			{
				CurDelayTime = FWalkTime;
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
				IsPlayerMove = true;
			}
			PrevDirinput = EDirState::Left;
		}
	}

	if (true == UEngineInput::IsPress('D'))
	{
		if (false == IsActionDelay)
		{
			if (EPlayerMoveState::Walk == MoveState)
			{
				CurDelayTime = FWalkTime;
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
				IsPlayerMove = true;
			}
			PrevDirinput = EDirState::Right;
		}
	}
}

void APlayer::InputDelayCheck(float _DeltaTime)
{
	if (CurDelayTime > 0.0f)
	{
		IsActionDelay = true;
		CurDelayTime -= _DeltaTime;
	}
	else
	{
		IsActionDelay = false;
	}
}
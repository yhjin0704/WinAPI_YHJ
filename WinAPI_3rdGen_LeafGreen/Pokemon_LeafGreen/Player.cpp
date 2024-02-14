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
	ACharacter::BeginPlay();

	CharacterRenderer = CreateImageRenderer(Player);
	CharacterRenderer->SetTransform({ {0, 0}, {FScreenTileScale * 2.0f, FScreenTileScale * 2.0f} });

	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_Idle", "Player_Boy_Walk_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_Idle", "Player_Boy_Walk_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_Idle", "Player_Boy_Walk_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_Idle", "Player_Boy_Walk_Right.png", 1, 1, 0.0f, false);

	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_R", "Player_Boy_Walk_Down.png", 0, 1, (WalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_R", "Player_Boy_Walk_UP.png", 0, 1, (WalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_R", "Player_Boy_Walk_Left.png", 0, 1, (WalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_R", "Player_Boy_Walk_Right.png", 0, 1, (WalkTime / 2), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_L", "Player_Boy_Walk_Down.png", 2, 3, (WalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_L", "Player_Boy_Walk_UP.png", 2, 3, (WalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_L", "Player_Boy_Walk_Left.png", 2, 3, (WalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_L", "Player_Boy_Walk_Right.png", 2, 3, (WalkTime / 2), false);

	CharacterRenderer->SetImage("Player_Boy_Walk_Down.png", 1);
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	GetWorld()->SetCameraPos(GetActorLocation() - FVector(FHSceen_X, FHSceen_Y));

	KeyInputMove(_DeltaTime);
}

void APlayer::KeyInputMove(float _DeltaTime)
{
	if (true == UEngineInput::IsPress('S'))
	{
		SetKeyInputAnimation(EDirState::Down);
	}
	else if (true == UEngineInput::IsPress('W'))
	{
		SetKeyInputAnimation(EDirState::Up);
	}
	else if (true == UEngineInput::IsPress('A'))
	{
		SetKeyInputAnimation(EDirState::Left);
	}
	else if (true == UEngineInput::IsPress('D'))
	{
		SetKeyInputAnimation(EDirState::Right);
	}

	InputDelayCheck(_DeltaTime);

	if (false == IsActionDelay)
	{
		IsPlayerMove = false;
	}

	if (true == IsPlayerMove)
	{
		MovePos(MoveState, _DeltaTime);
	}
}

void APlayer::SetKeyInputAnimation(EDirState _InputDir)
{
	if (false == IsActionDelay)
	{
		if (_InputDir == PrevDirInput)
		{
			SetCurDelayTime();
			PlayMoveAnimation();
			IsPlayerMove = true;
		}
		else
		{
			CurDelayTime = FIdleTime;
			PrevDirInput = _InputDir;
			PlayIdleAnimation();
		}
	}
}

void APlayer::SetCurDelayTime()
{
	switch (MoveState)
	{
	case EMoveState::Walk:
		CurDelayTime = FWalkTime;
		break;
	case EMoveState::Run:
		break;
	case EMoveState::Bike:
		break;
	case EMoveState::Surf:
		break;
	default:
		break;
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
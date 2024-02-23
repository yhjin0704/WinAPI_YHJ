#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineCore\EngineDebug.h>
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

	CharacterRenderer = CreateImageRenderer(ERenderOrder::Player);
	CharacterRenderer->SetTransform({ {0, 0}, {FGameTileScale * 2.0f, FGameTileScale * 2.0f} });

	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_Idle", "Player_Boy_Walk_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_Idle", "Player_Boy_Walk_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_Idle", "Player_Boy_Walk_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_Idle", "Player_Boy_Walk_Right.png", 1, 1, 0.0f, false);

	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_R", "Player_Boy_Walk_Down.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_R", "Player_Boy_Walk_UP.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_R", "Player_Boy_Walk_Left.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_R", "Player_Boy_Walk_Right.png", 0, 1, (FWalkTime / 2), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_L", "Player_Boy_Walk_Down.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_L", "Player_Boy_Walk_UP.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_L", "Player_Boy_Walk_Left.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_L", "Player_Boy_Walk_Right.png", 2, 3, (FWalkTime / 2), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_Jump", "Player_Boy_Walk_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_Idle", "Player_Boy_Walk_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_Idle", "Player_Boy_Walk_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_Idle", "Player_Boy_Walk_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_Idle", "Player_Boy_Walk_Right.png", 1, 1, 0.0f, false);

	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_R", "Player_Boy_Run_Down.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_R", "Player_Boy_Run_UP.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_R", "Player_Boy_Run_Left.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_R", "Player_Boy_Run_Right.png", 0, 1, (FRunTime / 2), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_L", "Player_Boy_Run_Down.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_L", "Player_Boy_Run_UP.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_L", "Player_Boy_Run_Left.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_L", "Player_Boy_Run_Right.png", 2, 3, (FRunTime / 2), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_Jump", "Player_Boy_Walk_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_Idle", "Player_Boy_Bike_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_Idle", "Player_Boy_Bike_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_Idle", "Player_Boy_Bike_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_Idle", "Player_Boy_Bike_Right.png", 1, 1, 0.0f, false);

	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_R", "Player_Boy_Bike_Down.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_R", "Player_Boy_Bike_UP.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_R", "Player_Boy_Bike_Left.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_R", "Player_Boy_Bike_Right.png", 0, 1, (FBikeTime / 2), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_L", "Player_Boy_Bike_Down.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_L", "Player_Boy_Bike_UP.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_L", "Player_Boy_Bike_Left.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_L", "Player_Boy_Bike_Right.png", 2, 3, (FBikeTime / 2), false);

	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_Jump", "Player_Boy_Bike_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	CharacterRenderer->SetImage("Player_Boy_Walk_Down.png", 1);

	PlayerCollision = CreateCollision(ECollisionOrder::Player);
	PlayerCollision->SetScale({ IGameTileScale, IGameTileScale });
	PlayerCollision->SetColType(ECollisionType::Rect);
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	GetWorld()->SetCameraPos(GetActorLocation() - FVector(FHScreen_X, FHScreen_Y));

	if (EMoveState::Idle == MoveState)
	{
		UseRunningShoes();
		UseBike();
	}

	KeyInputMove(_DeltaTime);

	if (EMoveState::Idle == MoveState)
	{
		PlayIdleAnimation();
	}

	if (UEngineInput::IsDown('9'))
	{
		if (false == IsTextDebugView)
		{
			IsTextDebugView = true;
		}
		else
		{
			IsTextDebugView = false;
		}
	}
	UEngineDebug::DebugTextPrint("PlayerPos : " + GetTransform().GetPosition().ToString(), 15.0f);
	UEngineDebug::DebugTextPrint("PlayerScale : " + GetTransform().GetPosition().ToString(), 20.0f);
}

void APlayer::KeyInputMove(float _DeltaTime)
{
	if (false == IsActionDelay)
	{
		if (true == UEngineInput::IsPress('S'))
		{
			SetColCheckPos(PrevDirInput);
			if (Color8Bit(0, 255, 255, 0) == Global::GColMapImage->GetColor((IsColCheckPos.iX() / IScaleMultiple), (IsColCheckPos.iY() / IScaleMultiple), Color8Bit::MagentaA))
			{
				MoveState = EMoveState::Jump;
			}
			SetKeyInputAnimation(EDirState::Down);
		}
		else if (true == UEngineInput::IsPress('W'))
		{
			SetColCheckPos(PrevDirInput);
			SetKeyInputAnimation(EDirState::Up);
		}
		else if (true == UEngineInput::IsPress('A'))
		{
			SetColCheckPos(PrevDirInput);
			SetKeyInputAnimation(EDirState::Left);
		}
		else if (true == UEngineInput::IsPress('D'))
		{
			SetColCheckPos(PrevDirInput);
			SetKeyInputAnimation(EDirState::Right);
		}
	}

	InputDelayCheck(_DeltaTime);

	if (true == IsMove)
	{
		MovePos(_DeltaTime);
	}
}

void APlayer::SetKeyInputAnimation(EDirState _InputDir)
{
	if (false == IsActionDelay)
	{
		if (_InputDir == PrevDirInput)
		{
			if (EMoveState::Jump != MoveState)
			{
				MoveState = EMoveState::Move;
			}
			SetPlayerMovePos();
		}
		else
		{
			MoveState = EMoveState::Idle;
			PrevDirInput = _InputDir;
		}
		PlayMoveAnimation();
		SetCurDelayTime();
	}
}

// 행동 딜레이 시간 설정
void APlayer::SetCurDelayTime()
{
	switch (MoveType)
	{
	case EMoveType::Walk:
		CurDelayTime = FWalkTime;
		if (EMoveState::Jump == MoveState)
		{
			CurDelayTime += FWalkTime;
		}
		break;
	case EMoveType::Run:
		CurDelayTime = FRunTime;
		if (EMoveState::Jump == MoveState)
		{
			CurDelayTime = (FWalkTime * 2);
		}
		break;
	case EMoveType::Bike:
		CurDelayTime = FBikeTime;
		if (EMoveState::Jump == MoveState)
		{
			CurDelayTime = (FWalkTime * 2);
		}
		break;
	case EMoveType::Surf:
		break;
	default:
		break;
	}
	if (EMoveState::Idle == MoveState)
	{
		CurDelayTime = FIdleTime;
	}
	IsActionDelay = true;
}

void APlayer::InputDelayCheck(float _DeltaTime)
{
	if (0.0f < CurDelayTime)
	{
		IsActionDelay = true;
		CurDelayTime -= _DeltaTime;
	}
	else
	{
		MoveState = EMoveState::Idle;
		IsActionDelay = false;
	}
}

void APlayer::SetPlayerMovePos()
{
	bool DefaltColCheck = false;
	DefaltColCheck = ColCheck(PrevDirInput);

	if (false == DefaltColCheck)
	{
		SetMovePos();
	}
}

void APlayer::UseRunningShoes()
{
	if (EMoveType::Walk == MoveType || EMoveType::Run == MoveType)
	{
		if (true == UEngineInput::IsDown('L'))
		{
			if (EMoveType::Walk == MoveType)
			{
				MoveType = EMoveType::Run;
			}
			else if (EMoveType::Run == MoveType)
			{
				MoveType = EMoveType::Walk;
			}
		}
	}
}

void APlayer::UseBike()
{
	if (true == UEngineInput::IsDown(' '))
	{
		if (EMoveType::Walk == MoveType || EMoveType::Run == MoveType)
		{
			PrevMoveType = MoveType;
			MoveType = EMoveType::Bike;
		}
		else if (EMoveType::Bike == MoveType)
		{
			MoveType = PrevMoveType;
		}
	}
}
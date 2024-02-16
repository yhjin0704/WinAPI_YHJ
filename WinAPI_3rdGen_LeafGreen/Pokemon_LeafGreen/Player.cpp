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

	CharacterRenderer = CreateImageRenderer(ERenderOrder::Player);
	CharacterRenderer->SetTransform({ {0, 0}, {FScreenTileScale * 2.0f, FScreenTileScale * 2.0f} });

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

	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_Jump", "Player_Boy_Walk_Down_Jump.png", 0, 12, (FRunTime / 13.0f * 2.0f), false);

	CharacterRenderer->SetImage("Player_Boy_Walk_Down.png", 1);

	PlayerCollision = CreateCollision(0);
	PlayerCollision->SetScale({ IScreenTileScale, IScreenTileScale });
	PlayerCollision->SetColType(ECollisionType::Rect);
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	GetWorld()->SetCameraPos(GetActorLocation() - FVector(FHSceen_X, FHSceen_Y));

	UseRunningShoes();
	KeyInputMove(_DeltaTime);
}

void APlayer::KeyInputMove(float _DeltaTime)
{
	if (true == UEngineInput::IsPress('S'))
	{
		SetColCheckPos(PrevDirInput);
		if (Color8Bit(0, 255, 255, 0) == Global::GColMapImage->GetColor((IsColCheckPos.iX() / FScaleMultiple), (IsColCheckPos.iY() / FScaleMultiple), Color8Bit::MagentaA))
		{
			PrevFoot = EMoveState::Jump;
		}
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

	if (EMoveState::Jump == PrevFoot)
	{
		SetColCheckPos(PrevDirInput);
		if (Color8Bit(0, 255, 255, 0) != Global::GColMapImage->GetColor((IsColCheckPos.iX() / FScaleMultiple), (IsColCheckPos.iY() / FScaleMultiple), Color8Bit::MagentaA))
		{
			PrevFoot = EMoveState::Left;
		}
	}

	InputDelayCheck(_DeltaTime);

	if (false == IsActionDelay)
	{
		IsPlayerMove = false;
	}

	if (true == IsPlayerMove)
	{
		PlayerMovePos(_DeltaTime);
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

// 행동 딜레이 시간 설정
void APlayer::SetCurDelayTime()
{
	switch (MoveType)
	{
	case EMoveType::Walk:
		CurDelayTime = FWalkTime;
		if (EMoveState::Jump == PrevFoot)
		{
			CurDelayTime += FWalkTime;
		}
		break;
	case EMoveType::Run:
		CurDelayTime = FRunTime;
		if (EMoveState::Jump == PrevFoot)
		{
			CurDelayTime += FRunTime;
		}
		break;
	case EMoveType::Bike:
		break;
	case EMoveType::Surf:
		break;
	default:
		break;
	}
}

void APlayer::InputDelayCheck(float _DeltaTime)
{
	if (CurDelayTime >= 0.0f)
	{
		IsActionDelay = true;
		CurDelayTime -= _DeltaTime;
	}
	else
	{
		IsActionDelay = false;
	}
}

void APlayer::PlayerMovePos(float _DeltaTime)
{
	bool DefaltColCheck = false;
	DefaltColCheck = ColCheck(PrevDirInput);

	if (false == DefaltColCheck)
	{
		MovePos(_DeltaTime);
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
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineCore\EngineDebug.h>
#include "FieldLevel.h"
#include "Global.h"
#include "PlayerHelper.h"

APlayer* APlayer::MainPlayer = nullptr;

APlayer* APlayer::GetMainPlayer()
{
	return MainPlayer;
}

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	ACharacter::BeginPlay();

	this->SetCharacterName("����");

	CreatePlayerAllRender();
	CreateMenu();
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	GetWorld()->SetCameraPos(GetActorLocation() - FVector(FHScreen_X, FHScreen_Y));

	if (EMoveState::Idle == MoveState)
	{
		UseMenu();
		UseRunningShoes();
		UseBike();
	}
	if (false == IsUseMenu)
	{
		KeyInputMove(_DeltaTime);
	}

	if (EMoveState::Idle == MoveState)
	{
		PlayIdleAnimation();
	}

	FVector PlayerPosDebug = { (GetTransform().GetPosition().X - FHGameTileScale) / FScaleMultiple, GetTransform().GetPosition().Y / FScaleMultiple };
	UEngineDebug::DebugTextPrint("�÷��̾� ��ǥ : " + PlayerPosDebug.ToString(), 15.0f);
}

void APlayer::CreatePlayerAllRender()
{
	CharacterRenderer = CreateImageRenderer(ERenderOrder::Player);
	CharacterRenderer->SetTransform({ {0, 0}, {FGameTileScale * 2.0f, FGameTileScale * 2.0f} });

	//�ȱ� Idle �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_Idle", "Player_Boy_Walk_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_Idle", "Player_Boy_Walk_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_Idle", "Player_Boy_Walk_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_Idle", "Player_Boy_Walk_Right.png", 1, 1, 0.0f, false);
	
	//�ȱ� ������ �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_R", "Player_Boy_Walk_Down.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_R", "Player_Boy_Walk_UP.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_R", "Player_Boy_Walk_Left.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_R", "Player_Boy_Walk_Right.png", 0, 1, (FWalkTime / 2), false);

	//�ȱ� �޹� �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_L", "Player_Boy_Walk_Down.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_L", "Player_Boy_Walk_UP.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_L", "Player_Boy_Walk_Left.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_L", "Player_Boy_Walk_Right.png", 2, 3, (FWalkTime / 2), false);

	//�ȱ� ���� �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_Jump", "Player_Boy_Walk_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	//�ٱ� Idle �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_Idle", "Player_Boy_Walk_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_Idle", "Player_Boy_Walk_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_Idle", "Player_Boy_Walk_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_Idle", "Player_Boy_Walk_Right.png", 1, 1, 0.0f, false);

	//�ٱ� ������ �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_R", "Player_Boy_Run_Down.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_R", "Player_Boy_Run_UP.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_R", "Player_Boy_Run_Left.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_R", "Player_Boy_Run_Right.png", 0, 1, (FRunTime / 2), false);

	//�ٱ� �޹� �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_L", "Player_Boy_Run_Down.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_L", "Player_Boy_Run_UP.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_L", "Player_Boy_Run_Left.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_L", "Player_Boy_Run_Right.png", 2, 3, (FRunTime / 2), false);

	//�ٱ� ���� �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_Jump", "Player_Boy_Walk_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	//������ Idle �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_Idle", "Player_Boy_Bike_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_Idle", "Player_Boy_Bike_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_Idle", "Player_Boy_Bike_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_Idle", "Player_Boy_Bike_Right.png", 1, 1, 0.0f, false);

	//������ ������ �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_R", "Player_Boy_Bike_Down.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_R", "Player_Boy_Bike_UP.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_R", "Player_Boy_Bike_Left.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_R", "Player_Boy_Bike_Right.png", 0, 1, (FBikeTime / 2), false);

	//������ �޹� �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_L", "Player_Boy_Bike_Down.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_L", "Player_Boy_Bike_UP.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_L", "Player_Boy_Bike_Left.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_L", "Player_Boy_Bike_Right.png", 2, 3, (FBikeTime / 2), false);

	//������ ���� �ִϸ��̼� ����
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_Jump", "Player_Boy_Bike_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	PlayerCollision = CreateCollision(ECollisionOrder::Player);
	PlayerCollision->SetScale({ IGameTileScale, IGameTileScale });
	PlayerCollision->SetPosition({ GetActorLocation().X, GetActorLocation().Y + FHGameTileScale });
	PlayerCollision->SetColType(ECollisionType::Rect);
}

void APlayer::CreateMenu()
{
	MenuRenderer = CreateImageRenderer(ERenderOrder::Menu);
	MenuRenderer->SetTransform({ { ((ITileScale * 5) + 4) * IScaleMultiple, ((ITileScale * -2) - 12) * IScaleMultiple }, { 70.0f * FScaleMultiple, 72.0f * FScaleMultiple} });
	MenuRenderer->SetImage("Menu4.png");
	MenuRenderer->ActiveOff();

	MenuPlayerTextRenderer = CreateImageRenderer(ERenderOrder::Text);
	MenuPlayerTextRenderer->SetTransform({ { ((ITileScale * 4) + 10) * IScaleMultiple, ((ITileScale * -2) - 3) * IScaleMultiple }, { 0, 0 } });
	Global::SetPokemonText(MenuPlayerTextRenderer, GetCharacterName());
	MenuPlayerTextRenderer->ActiveOff();

	MenuExplainRenderer = CreateImageRenderer(ERenderOrder::Menu);
	MenuExplainRenderer->SetTransform({ { 0, ((ITileScale * 3) + 12) * IScaleMultiple }, { 240.0f * FScaleMultiple, 40.0f * FScaleMultiple} });
	MenuExplainRenderer->SetImage("MenuExplain.png");
	MenuExplainRenderer->ActiveOff();
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

//Ű �Է½� �ִϸ��̼� ���
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

// �ൿ ������ �ð� ����
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
// ������ �� �ִ� ��Ȳ�̸� �����̰� �Ѵ�
void APlayer::SetPlayerMovePos()
{
	bool DefaltColCheck = false;
	DefaltColCheck = ColCheck(PrevDirInput);

	if (false == DefaltColCheck)
	{
		SetMovePos();
	}
}

void APlayer::UseMenu()
{
	if (true == UEngineInput::IsDown(VK_RETURN))
	{
		if (true == IsUseMenu)
		{
			IsUseMenu = false;
			MenuRenderer->ActiveOff();
			MenuPlayerTextRenderer->ActiveOff();

			MenuExplainRenderer->ActiveOff();
		}
		else
		{
			IsUseMenu = true;
			MenuRenderer->ActiveOn();
			MenuPlayerTextRenderer->ActiveOn();

			MenuExplainRenderer->ActiveOn();
		}
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
		UFieldLevel* Field = dynamic_cast<UFieldLevel*>(GetWorld());
		if (true == Field->GetIsOutside())
		{
			if (EMoveType::Walk == MoveType || EMoveType::Run == MoveType)
			{
				PlayerHelper::PrevMoveType = MoveType;
				MoveType = EMoveType::Bike;
			}
			else if (EMoveType::Bike == MoveType)
			{
				MoveType = PlayerHelper::PrevMoveType;
			}

		}
	}
}
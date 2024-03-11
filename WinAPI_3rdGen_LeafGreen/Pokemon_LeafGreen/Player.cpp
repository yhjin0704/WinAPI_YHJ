#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineCore\EngineDebug.h>
#include "Pokemon3rdGen_Core.h"
#include "FieldLevel.h"
#include "Global.h"
#include "PlayerHelper.h"

APlayer* APlayer::MainPlayer = nullptr;

APlayer* APlayer::GetMainPlayer()
{
	return MainPlayer;
}

void APlayer::SetMainPlayer(APlayer* _MainPlayer)
{
	MainPlayer = _MainPlayer;
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

	SetCharacterName("레드");

	CreatePlayerAllRender();
	CreateMenu();
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	GetWorld()->SetCameraPos(GetActorLocation() - FVector(FHScreen_X, FHScreen_Y));
	if (false == PlayerHelper::PlayerPause)
	{
		if (EMoveState::Idle == MoveState)
		{
			UseMenu();
			if (false == PlayerHelper::IsUseMenu)
			{
				UseRunningShoes();
				UseBike();
			}
		}
		//메뉴 사용 중 체크
		if (false == PlayerHelper::IsUseMenu)
		{
			KeyInputMove(_DeltaTime);
		}
		else
		{
			MenuCursorMove();
		}

		if (EMoveState::Idle == MoveState)
		{
			PlayIdleAnimation();
		}
	}

	FVector PlayerPosDebug = { (GetTransform().GetPosition().X - FHGameTileScale) / FScaleMultiple, GetTransform().GetPosition().Y / FScaleMultiple };
	UEngineDebug::DebugTextPrint("플레이어 좌표 : " + PlayerPosDebug.ToString(), 15.0f);
}

void APlayer::CreatePlayerAllRender()
{
	CharacterRenderer = CreateImageRenderer(ERenderOrder::Player);
	CharacterRenderer->SetTransform({ {0, 0}, {FGameTileScale * 2.0f, FGameTileScale * 2.0f} });

	//걷기 Idle 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_Idle", "Player_Boy_Walk_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_Idle", "Player_Boy_Walk_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_Idle", "Player_Boy_Walk_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_Idle", "Player_Boy_Walk_Right.png", 1, 1, 0.0f, false);

	//걷기 오른발 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_R", "Player_Boy_Walk_Down.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_R", "Player_Boy_Walk_UP.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_R", "Player_Boy_Walk_Left.png", 0, 1, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_R", "Player_Boy_Walk_Right.png", 0, 1, (FWalkTime / 2), false);

	//걷기 왼발 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_L", "Player_Boy_Walk_Down.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_UP_L", "Player_Boy_Walk_UP.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Left_L", "Player_Boy_Walk_Left.png", 2, 3, (FWalkTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Right_L", "Player_Boy_Walk_Right.png", 2, 3, (FWalkTime / 2), false);

	//걷기 점프 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Walk_Down_Jump", "Player_Boy_Walk_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	//뛰기 Idle 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_Idle", "Player_Boy_Walk_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_Idle", "Player_Boy_Walk_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_Idle", "Player_Boy_Walk_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_Idle", "Player_Boy_Walk_Right.png", 1, 1, 0.0f, false);

	//뛰기 오른발 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_R", "Player_Boy_Run_Down.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_R", "Player_Boy_Run_UP.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_R", "Player_Boy_Run_Left.png", 0, 1, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_R", "Player_Boy_Run_Right.png", 0, 1, (FRunTime / 2), false);

	//뛰기 왼발 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_L", "Player_Boy_Run_Down.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_UP_L", "Player_Boy_Run_UP.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Left_L", "Player_Boy_Run_Left.png", 2, 3, (FRunTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Right_L", "Player_Boy_Run_Right.png", 2, 3, (FRunTime / 2), false);

	//뛰기 점프 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Run_Down_Jump", "Player_Boy_Walk_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	//자전거 Idle 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_Idle", "Player_Boy_Bike_Down.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_Idle", "Player_Boy_Bike_UP.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_Idle", "Player_Boy_Bike_Left.png", 1, 1, 0.0f, false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_Idle", "Player_Boy_Bike_Right.png", 1, 1, 0.0f, false);

	//자전거 오른발 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_R", "Player_Boy_Bike_Down.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_R", "Player_Boy_Bike_UP.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_R", "Player_Boy_Bike_Left.png", 0, 1, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_R", "Player_Boy_Bike_Right.png", 0, 1, (FBikeTime / 2), false);

	//자전거 왼발 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_L", "Player_Boy_Bike_Down.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_UP_L", "Player_Boy_Bike_UP.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Left_L", "Player_Boy_Bike_Left.png", 2, 3, (FBikeTime / 2), false);
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Right_L", "Player_Boy_Bike_Right.png", 2, 3, (FBikeTime / 2), false);

	//자전거 점프 애니메이션 생성
	CharacterRenderer->CreateAnimation("Player_Boy_Bike_Down_Jump", "Player_Boy_Bike_Down_Jump.png", 0, 12, (FWalkTime / 13.0f * 2.0f), false);

	/*PlayerCollision = CreateCollision(ECollisionOrder::Player);
	PlayerCollision->SetScale({ IGameTileScale, IGameTileScale });
	PlayerCollision->SetPosition({ GetActorLocation().X, (GetActorLocation().Y + FHGameTileScale) });
	PlayerCollision->SetColType(ECollisionType::Rect);*/

	PlayerDownCollision = CreateCollision(ECollisionOrder::Player);
	PlayerDownCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	PlayerDownCollision->SetPosition({ GetActorLocation().X, (GetActorLocation().Y + FHGameTileScale + (FHGameTileScale / 2)) });
	PlayerDownCollision->SetColType(ECollisionType::Rect);

	PlayerUPCollision = CreateCollision(ECollisionOrder::Player);
	PlayerUPCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	PlayerUPCollision->SetPosition({ GetActorLocation().X, (GetActorLocation().Y + FHGameTileScale - (FHGameTileScale / 2)) });
	PlayerUPCollision->SetColType(ECollisionType::Rect);

	PlayerLeftCollision = CreateCollision(ECollisionOrder::Player);
	PlayerLeftCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	PlayerLeftCollision->SetPosition({ GetActorLocation().X - (FHGameTileScale / 2), (GetActorLocation().Y + FHGameTileScale) });
	PlayerLeftCollision->SetColType(ECollisionType::Rect);

	PlayerRightCollision = CreateCollision(ECollisionOrder::Player);
	PlayerRightCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	PlayerRightCollision->SetPosition({ GetActorLocation().X + (FHGameTileScale / 2), (GetActorLocation().Y + FHGameTileScale) });
	PlayerRightCollision->SetColType(ECollisionType::Rect);
}

void APlayer::CreateMenu()
{
	CursorRender = CreateImageRenderer(ERenderOrder::Text);
	CursorRender->SetImage("MenuCursor.png");
	CursorRender->SetTransform({ { ((ITileScale * 4) - 4) * IScaleMultiple, ((ITileScale * -4) - 3) * IScaleMultiple }, { (CursorRender->GetImage()->GetScale()) * FScaleMultiple} });
	CursorRender->ActiveOff();

	MenuRenderer = CreateImageRenderer(ERenderOrder::Menu);
	MenuRenderer->SetImage("Menu4.png");
	MenuRenderer->SetTransform({ { ((ITileScale * 5) + 4) * IScaleMultiple, ((ITileScale * -2) - 12) * IScaleMultiple }, {(MenuRenderer->GetImage()->GetScale()) * FScaleMultiple} });
	MenuRenderer->ActiveOff();

	MenuPlayerTextRenderer = CreateImageRenderer(ERenderOrder::Text);
	Global::SetPokemonText(MenuPlayerTextRenderer, Gdiplus::StringAlignment::StringAlignmentNear, GetCharacterName());
	MenuPlayerTextRenderer->SetTransform({ { ((FTileScale * 4.0f) - 0.25f ) * FScaleMultiple, ((FTileScale * -2.0f) - 11.0f) * FScaleMultiple }, { 0, 0 } });
	MenuPlayerTextRenderer->ActiveOff();

	MenuExplainRenderer = CreateImageRenderer(ERenderOrder::Menu);
	MenuExplainRenderer->SetImage("MenuExplain.png");
	MenuExplainRenderer->SetTransform({ { 0, ((ITileScale * 3) + 12) * IScaleMultiple }, {(MenuExplainRenderer->GetImage()->GetScale()) * FScaleMultiple} });
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
	SetColBoxDir(PrevDirInput);
}

void APlayer::SetColBoxDir(EDirState _InputDir)
{
	switch (_InputDir)
	{
	case EDirState::Down:
		PlayerDownCollision->ActiveOn();
		PlayerUPCollision->ActiveOff();
		PlayerLeftCollision->ActiveOff();
		PlayerRightCollision->ActiveOff();
		break;
	case EDirState::Up:
		PlayerDownCollision->ActiveOff();
		PlayerUPCollision->ActiveOn();
		PlayerLeftCollision->ActiveOff();
		PlayerRightCollision->ActiveOff();
		break;
	case EDirState::Left:
		PlayerDownCollision->ActiveOff();
		PlayerUPCollision->ActiveOff();
		PlayerLeftCollision->ActiveOn();
		PlayerRightCollision->ActiveOff();
		break;
	case EDirState::Right:
		PlayerDownCollision->ActiveOff();
		PlayerUPCollision->ActiveOff();
		PlayerLeftCollision->ActiveOff();
		PlayerRightCollision->ActiveOn();
		break;
	default:
		break;
	}
}

//키 입력시 애니메이션 재생
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
// 움직일 수 있는 상황이면 움직이게 한다
void APlayer::SetPlayerMovePos()
{
	bool DefaltColCheck = false;
	DefaltColCheck = ColCheck(PrevDirInput);

	if (false == DefaltColCheck)
	{
		SetMovePos();
	}
}

void APlayer::MenuCursorMove()
{
	if (true == PlayerHelper::IsUseMenu)
	{
		if (true == UEngineInput::IsDown('W'))
		{
			--MenuCursorPos;
			if (0 > MenuCursorPos)
			{
				MenuCursorPos = 3;
			}
		}
		else if (true == UEngineInput::IsDown('S'))
		{
			++MenuCursorPos;
			if (3 < MenuCursorPos)
			{
				MenuCursorPos = 0;
			}
		}

		CursorRender->SetTransform({ { ((ITileScale * 4) - 4) * IScaleMultiple, ((ITileScale * (-4 + MenuCursorPos)) - 3) * IScaleMultiple }, {FGameTileScale, FGameTileScale}});

		if (true == UEngineInput::IsDown('P'))
		{
			switch (MenuCursorPos)
			{
			case 0:
				if (false == dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry().empty())
				{
					GEngine->ChangeLevel("MyPokemonLevel");
				}
				break;
			case 1:
				GEngine->ChangeLevel("MyBagLevel");
				break;
			case 2:
				GEngine->ChangeLevel("MyTrainerCardLevel");
				break;
			case 3:
				CloseMenu();
				break;
			default:
				break;
			}
		}
		else if (true == UEngineInput::IsDown('L'))
		{
			CloseMenu();
		}
	}
	else
	{
		MsgBoxAssert("메뉴창이 켜지지 않았는데 MenuCursorMove()가 실행되었습니다.");
		return;
	}
}

void APlayer::UseMenu()
{
	if (true == UEngineInput::IsDown(VK_RETURN))
	{
		if (true == PlayerHelper::IsUseMenu)
		{
			CloseMenu();
		}
		else
		{
			PlayerHelper::IsUseMenu = true;
			MenuRenderer->ActiveOn();
			CursorRender->ActiveOn();
			MenuPlayerTextRenderer->ActiveOn();

			MenuExplainRenderer->ActiveOn();
		}
	}
}

void APlayer::CloseMenu()
{
	PlayerHelper::IsUseMenu = false;
	MenuRenderer->ActiveOff();
	CursorRender->ActiveOff();
	MenuPlayerTextRenderer->ActiveOff();

	MenuExplainRenderer->ActiveOff();
	MenuCursorPos = 0;
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
	if (true == UEngineInput::IsDown(VK_SHIFT))
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


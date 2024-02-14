#include "Character.h"

ACharacter::ACharacter()
{
}

ACharacter::~ACharacter()
{
}

void ACharacter::BeginPlay()
{
	AActor::BeginPlay();
}

void ACharacter::Tick(float _DeltaTime)
{

}

std::string ACharacter::GetAnimationName(std::string _Name, EMoveType _Move, EDirState _Dir, EMoveState _MoveState)
{
	std::string MoveName = "";
	std::string DirName = "";
	std::string FootName = "";

	switch (_Move)
	{
	case EMoveType::Walk:
		MoveName = "_Walk";
		break;
	case EMoveType::Run:
		MoveName = "_Run";
		break;
	case EMoveType::Bike:
		MoveName = "_Bike";
		break;
	case EMoveType::Surf:
		MoveName = "_Surf";
		break;
	default:
		break;
	}

	switch (_Dir)
	{
	case EDirState::Down:
		DirName = "_Down";
		break;
	case EDirState::Up:
		DirName = "_Up";
		break;
	case EDirState::Left:
		DirName = "_Left";
		break;
	case EDirState::Right:
		DirName = "_Right";
		break;
	default:
		break;
	}

	switch (_MoveState)
	{
	case EMoveState::Idle:
		FootName = "_Idle";
		break;
	case EMoveState::Left:
		FootName = "_R";
		break;
	case EMoveState::Right:
		FootName = "_L";
		break;
	default:
		break;
	}

	return _Name + MoveName + DirName + FootName;
}

bool ACharacter::ColCheck(EDirState _PrevDirInput)
{
	switch (_PrevDirInput)
	{
	case EDirState::Down:
		IsColCheckPos = GetActorLocation() + (FVector::Down * FColCheckDown);
		break;
	case EDirState::Up:
		IsColCheckPos = GetActorLocation() + (FVector::Up * FColCheckUp);
		break;
	case EDirState::Left:
		IsColCheckPos = GetActorLocation() + (FVector::Left * FColCheckLeft);
		break;
	case EDirState::Right:
		IsColCheckPos = GetActorLocation() + (FVector::Right * FColCheckRight);
		break;
	default:
		break;
	}
	Color8Bit ColColor = Global::GColMapImage->GetColor((IsColCheckPos.iX() / FScaleMultiple), (IsColCheckPos.iY() / FScaleMultiple), Color8Bit::MagentaA);
	return ColColor == Color8Bit::MagentaA;
}

void ACharacter::MovePos(EMoveType _MoveType, float _DeltaTime)
{
	bool DefaltColCheck = false;
	float DeltaTimeMove = 0;
	DefaltColCheck = ColCheck(PrevDirInput);

	if (false == DefaltColCheck)
	{
		switch (_MoveType)
		{
		case EMoveType::Walk:
			DeltaTimeMove = FScreenTileScale / FWalkTime;
			break;
		case EMoveType::Run:
			break;
		case EMoveType::Bike:
			break;
		case EMoveType::Surf:
			break;
		default:
			break;
		}

		switch (PrevDirInput)
		{
		case EDirState::Down:
			AddActorLocation(FVector::Down * DeltaTimeMove * _DeltaTime);
			break;
		case EDirState::Up:
			AddActorLocation(FVector::Up * DeltaTimeMove * _DeltaTime);
			break;
		case EDirState::Left:
			AddActorLocation(FVector::Left * DeltaTimeMove * _DeltaTime);
			break;
		case EDirState::Right:
			AddActorLocation(FVector::Right * DeltaTimeMove * _DeltaTime);
			break;
		default:
			break;
		}
	}
}

void ACharacter::PlayMoveAnimation()
{
	if (EMoveState::Left == PrevFoot)
	{
		CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, PrevFoot);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, FWalkTime);
		PrevFoot = EMoveState::Right;
	}
	else
	{
		CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, PrevFoot);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, FWalkTime);
		PrevFoot = EMoveState::Left;
	}
}

void ACharacter::PlayIdleAnimation()
{
	CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput);
	CharacterRenderer->ChangeAnimation(CharacterAnimation);
}
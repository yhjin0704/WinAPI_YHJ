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

std::string ACharacter::GetAnimationName(std::string _Name, EMoveState _Move, EDirState _Dir, EPrevFoot _PrevFoot)
{
	std::string MoveName = "";
	std::string DirName = "";
	std::string FootName = "";

	switch (_Move)
	{
	case EMoveState::Walk:
		MoveName = "_Walk";
		break;
	case EMoveState::Run:
		MoveName = "_Run";
		break;
	case EMoveState::Bike:
		MoveName = "_Bike";
		break;
	case EMoveState::Surf:
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

	switch (_PrevFoot)
	{
	case EPrevFoot::Idle:
		FootName = "_Idle";
		break;
	case EPrevFoot::Left:
		FootName = "_R";
		break;
	case EPrevFoot::Right:
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

void ACharacter::MovePos(EMoveState _MoveState, float _DeltaTime)
{
	bool DefaltColCheck = false;
	float DeltaTimeMove = 0;
	DefaltColCheck = ColCheck(PrevDirInput);

	if (false == DefaltColCheck)
	{
		switch (_MoveState)
		{
		case EMoveState::Walk:
			DeltaTimeMove = FScreenTileScale / FWalkTime;
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
	if (EPrevFoot::Left == PrevFoot)
	{
		CharacterAnimation = GetAnimationName(Name, MoveState, PrevDirInput, PrevFoot);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, FWalkTime);
		PrevFoot = EPrevFoot::Right;
	}
	else
	{
		CharacterAnimation = GetAnimationName(Name, MoveState, PrevDirInput, PrevFoot);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, FWalkTime);
		PrevFoot = EPrevFoot::Left;
	}
}

void ACharacter::PlayIdleAnimation()
{
	CharacterAnimation = GetAnimationName(Name, MoveState, PrevDirInput);
	CharacterRenderer->ChangeAnimation(CharacterAnimation);
}
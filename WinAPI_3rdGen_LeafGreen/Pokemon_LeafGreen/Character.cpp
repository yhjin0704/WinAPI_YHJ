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
	case EMoveState::Jump:
		FootName = "_Jump";
		break;
	default:
		break;
	}

	return _Name + MoveName + DirName + FootName;
}

void ACharacter::SetColCheckPos(EDirState _PrevDirInput)
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
}

bool ACharacter::ColCheck(EDirState _PrevDirInput)
{
	SetColCheckPos(_PrevDirInput);
	Color8Bit ColColor = Global::GColMapImage->GetColor((IsColCheckPos.iX() / FScaleMultiple), (IsColCheckPos.iY() / FScaleMultiple), Color8Bit::MagentaA);
	if (Color8Bit::MagentaA == ColColor)
	{
		return true;
	}
	else if (Color8Bit::BlueA == ColColor)
	{
		return true;
	}
	else if (Color8Bit(0, 255, 255, 0) == ColColor)
	{
		if (EDirState::Down == PrevDirInput)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}

}

void ACharacter::MovePos(float _DeltaTime)
{
	float MoveTime = 0;
	switch (MoveType)
	{
	case EMoveType::Walk:
		MoveTime = FWalkTime;
		break;
	case EMoveType::Run:
		MoveTime = FRunTime;
		break;
	case EMoveType::Bike:
		break;
	case EMoveType::Surf:
		break;
	default:
		break;
	}

	StartPos = GetTransform().GetPosition();

	switch (PrevDirInput)
	{
	case EDirState::Down:
		MoveTime += _DeltaTime;
		TargetPos = StartPos + (FVector::Down * FGameTileScale);
		MovingPos = FVector::Lerp(StartPos, GetTransform().GetPosition(), MoveTime);
		SetActorLocation(MovingPos);
		if (1.0f <= MoveTime)
		{
			MoveTime = 0.0f;
		}
		break;
	case EDirState::Up:
		AddActorLocation(FVector::Up * MoveTime * _DeltaTime);
		break;
	case EDirState::Left:
		AddActorLocation(FVector::Left * MoveTime * _DeltaTime);
		break;
	case EDirState::Right:
		AddActorLocation(FVector::Right * MoveTime * _DeltaTime);
		break;
	default:
		break;
	}
}

void ACharacter::PlayMoveAnimation()
{
	float MoveAnimationTime = 0.0f;

	switch (MoveType)
	{
	case EMoveType::Walk:
		MoveAnimationTime = FWalkTime;
		break;
	case EMoveType::Run:
		MoveAnimationTime = FRunTime;
		break;
	case EMoveType::Bike:
		break;
	case EMoveType::Surf:
		break;
	default:
		break;
	}

	switch (PrevFoot)
	{
	case EMoveState::Left:
		CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, PrevFoot);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, MoveAnimationTime / 2.0f);
		PrevFoot = EMoveState::Right;
		break;
	case EMoveState::Right:
		CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, PrevFoot);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, MoveAnimationTime / 2.0f);
		PrevFoot = EMoveState::Left;
		break;
	case EMoveState::Jump:
		CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, PrevFoot);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, MoveAnimationTime / 13.0f * 2.0f);
		PrevFoot = EMoveState::Left;
		break;
	default:
		break;
	}
}

void ACharacter::PlayIdleAnimation()
{
	CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput);
	CharacterRenderer->ChangeAnimation(CharacterAnimation);
}
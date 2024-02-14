#pragma once
#include <EngineCore\Actor.h>
#include "Global.h"

class ACharacter : public AActor
{
public:
	// constrcuter destructer
	ACharacter();
	~ACharacter();

	// delete Function
	ACharacter(const ACharacter& _Other) = delete;
	ACharacter(ACharacter&& _Other) noexcept = delete;
	ACharacter& operator=(const ACharacter& _Other) = delete;
	ACharacter& operator=(ACharacter&& _Other) noexcept = delete;

	void SetCharacterName(std::string _Name)
	{
		Name = _Name;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* CharacterRenderer;
	std::string Name = "";
	std::string CharacterAnimation = "";

	EPrevFoot PrevFoot = EPrevFoot::Left;
	FVector IsColCheckPos = FVector::Zero;
	EMoveState MoveState = EMoveState::Walk;
	EDirState PrevDirInput = EDirState::Down;

	bool ColCheck(EDirState _PrevDirInput);
	void MovePos(EMoveState _MoveState, float _DeltaTime);

	std::string GetAnimationName(std::string _Name, EMoveState _Move, EDirState _Dir, EPrevFoot _PrevFoot = EPrevFoot::Idle);
	void PlayMoveAnimation();
	void PlayIdleAnimation();

private:

};


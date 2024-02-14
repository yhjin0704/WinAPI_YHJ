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

	EMoveState PrevFoot = EMoveState::Left;
	FVector IsColCheckPos = FVector::Zero;
	EMoveType MoveType = EMoveType::Walk;
	EDirState PrevDirInput = EDirState::Down;

	bool ColCheck(EDirState _PrevDirInput);
	void MovePos(EMoveType _MoveType, float _DeltaTime);

	std::string GetAnimationName(std::string _Name, EMoveType _Move, EDirState _Dir, EMoveState _MoveState = EMoveState::Idle);
	void PlayMoveAnimation();
	void PlayIdleAnimation();

private:

};


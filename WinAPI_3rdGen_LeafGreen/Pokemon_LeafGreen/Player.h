#pragma once
#include <EngineCore\Actor.h>
#include "Global.h"

class APlayer : public AActor
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Renderer;

	FVector PrevFieldPos = FVector::Zero;

	bool IsPlayerMove = false;
	EDirState PrevDirinput = EDirState::Down;
	bool PrevFootRight = false;
	EPlayerMoveState MoveState = EPlayerMoveState::Walk;
	float WalkTime = FWalkTime;

	bool IsActionDelay = false;
	float CurDelayTime = 0.0f;

	void InputDelayCheck(float _DeltaTime);
};


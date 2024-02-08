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
	EDirState PrevDirinput = EDirState::Down;
	bool PrevFootRight = false;
	EPlayerMoveState MoveState = EPlayerMoveState::Walk;
};


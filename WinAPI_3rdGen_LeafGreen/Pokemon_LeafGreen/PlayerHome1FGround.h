#pragma once
#include "Ground.h"
#include <EngineBase\EngineDirectory.h>

class PlayerHome1FGround : public AGround
{
public:
	// constrcuter destructer
	PlayerHome1FGround();
	~PlayerHome1FGround();

	// delete Function
	PlayerHome1FGround(const PlayerHome1FGround& _Other) = delete;
	PlayerHome1FGround(PlayerHome1FGround&& _Other) noexcept = delete;
	PlayerHome1FGround& operator=(const PlayerHome1FGround& _Other) = delete;
	PlayerHome1FGround& operator=(PlayerHome1FGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};


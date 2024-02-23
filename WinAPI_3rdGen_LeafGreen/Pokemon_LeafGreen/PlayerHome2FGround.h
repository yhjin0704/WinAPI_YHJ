#pragma once
#include "Ground.h"
#include <EngineBase\EngineDirectory.h>

class PlayerHome2FGround : public AGround
{
public:
	// constrcuter destructer
	PlayerHome2FGround();
	~PlayerHome2FGround();

	// delete Function
	PlayerHome2FGround(const PlayerHome2FGround& _Other) = delete;
	PlayerHome2FGround(PlayerHome2FGround&& _Other) noexcept = delete;
	PlayerHome2FGround& operator=(const PlayerHome2FGround& _Other) = delete;
	PlayerHome2FGround& operator=(PlayerHome2FGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};


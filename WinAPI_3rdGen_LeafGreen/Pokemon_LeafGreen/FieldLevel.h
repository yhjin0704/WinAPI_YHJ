#pragma once
#include <EngineCore\Level.h>
#include <EnginePlatform\EngineSound.h>
#include "Player.h"

class UFieldLevel : public ULevel
{
public:
	// constrcuter destructer
	UFieldLevel();
	~UFieldLevel();

	// delete Function
	UFieldLevel(const UFieldLevel& _Other) = delete;
	UFieldLevel(UFieldLevel&& _Other) noexcept = delete;
	UFieldLevel& operator=(const UFieldLevel& _Other) = delete;
	UFieldLevel& operator=(UFieldLevel&& _Other) noexcept = delete;

	APlayer* GetPlayer()
	{
		return Player;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	APlayer* Player;
	UEngineSoundPlayer BGMPlayer;
	std::string PrevMusic = "";

	void ChangeBGM(std::string_view _BGMName);

private:

};


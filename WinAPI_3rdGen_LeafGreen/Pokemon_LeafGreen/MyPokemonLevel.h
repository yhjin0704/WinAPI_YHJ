#pragma once
#include "MenuUILevel.h"
#include "MyPokemonBackGround.h"
#include <EngineBase/EngineString.h>
#include <EngineCore\EngineCore.h>

class UMyPokemonLevel : public UMenuUILevel
{
public:
	// constrcuter destructer
	UMyPokemonLevel();
	~UMyPokemonLevel();

	// delete Function
	UMyPokemonLevel(const UMyPokemonLevel& _Other) = delete;
	UMyPokemonLevel(UMyPokemonLevel&& _Other) noexcept = delete;
	UMyPokemonLevel& operator=(const UMyPokemonLevel& _Other) = delete;
	UMyPokemonLevel& operator=(UMyPokemonLevel&& _Other) noexcept = delete;

	std::string GetPrevLevelName()
	{
		return PrevLevelName;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	AMyPokemonBackGround* BackGround;

	std::string PrevLevelName = "";
};


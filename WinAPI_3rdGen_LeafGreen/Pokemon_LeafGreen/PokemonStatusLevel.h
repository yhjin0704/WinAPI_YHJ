#pragma once
#include "MenuUILevel.h"

class UPokemonStatusLevel : public UMenuUILevel
{
public:
	// constrcuter destructer
	UPokemonStatusLevel();
	~UPokemonStatusLevel();

	// delete Function
	UPokemonStatusLevel(const UPokemonStatusLevel& _Other) = delete;
	UPokemonStatusLevel(UPokemonStatusLevel&& _Other) noexcept = delete;
	UPokemonStatusLevel& operator=(const UPokemonStatusLevel& _Other) = delete;
	UPokemonStatusLevel& operator=(UPokemonStatusLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:

};


#pragma once
#include "MenuUILevel.h"

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};


#pragma once
#include <EngineCore/Actor.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDirectory.h>
#include "Global.h"

class AMyPokemonSlot : public AActor
{
public:
	// constrcuter destructer
	AMyPokemonSlot();
	~AMyPokemonSlot();

	// delete Function
	AMyPokemonSlot(const AMyPokemonSlot& _Other) = delete;
	AMyPokemonSlot(AMyPokemonSlot&& _Other) noexcept = delete;
	AMyPokemonSlot& operator=(const AMyPokemonSlot& _Other) = delete;
	AMyPokemonSlot& operator=(AMyPokemonSlot&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* PokemonSlotRenderer = nullptr;
	UImageRenderer* PokemonImageRenderer = nullptr;
	UImageRenderer* PokemonNameRenderer = nullptr;
	UImageRenderer* PokemonLevelRenderer = nullptr;
	UImageRenderer* PokemonGenderRenderer = nullptr;
	UImageRenderer* PokemonHPRenderer = nullptr;
	UImageRenderer* PokemonHpTextRenderer = nullptr;
};


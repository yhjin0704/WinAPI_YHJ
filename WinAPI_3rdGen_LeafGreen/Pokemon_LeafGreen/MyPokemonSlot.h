#pragma once
#include <EngineCore/Actor.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDirectory.h>
#include "PokemonInfo.h"
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

	void SetSlotRenderer(std::string_view _SlotImage, float _Slot_X, float _Slot_Y);
	void SetDotRenderer(std::string_view _AniName, float _Ani_X, float _Ani_Y, PokemonInfo _Entry);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* PokemonSlotRenderer = nullptr;
	UImageRenderer* PokemonImageRenderer = nullptr;
	//UImageRenderer* PokemonNameRenderer = nullptr;
	//UImageRenderer* PokemonLevelRenderer = nullptr;
	//UImageRenderer* PokemonGenderRenderer = nullptr;
	//UImageRenderer* PokemonHPRenderer = nullptr;
	//UImageRenderer* PokemonHpTextRenderer = nullptr;
private:
};


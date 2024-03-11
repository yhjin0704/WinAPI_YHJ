#pragma once
#include <EngineCore\Actor.h>

class ABattlePokemonStatus : public AActor
{
public:
	// constrcuter destructer
	ABattlePokemonStatus();
	~ABattlePokemonStatus();

	// delete Function
	ABattlePokemonStatus(const ABattlePokemonStatus& _Other) = delete;
	ABattlePokemonStatus(ABattlePokemonStatus&& _Other) noexcept = delete;
	ABattlePokemonStatus& operator=(const ABattlePokemonStatus& _Other) = delete;
	ABattlePokemonStatus& operator=(ABattlePokemonStatus&& _Other) noexcept = delete;

	void SetRenderer(std::string_view _Image);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* StatusWindowRenderer = nullptr;
	UImageRenderer* PokemonNameRenderer = nullptr;
	UImageRenderer* PokemonLevelRenderer = nullptr;
	UImageRenderer* PokemonGenderRenderer = nullptr;
	UImageRenderer* PokemonHpBarRenderer = nullptr;
	UImageRenderer* PokemonHPRenderer = nullptr;
	UImageRenderer* PokemonMaxHpRenderer = nullptr;
};


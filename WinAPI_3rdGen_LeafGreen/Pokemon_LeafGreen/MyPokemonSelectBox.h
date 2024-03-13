#pragma once
#include <EngineCore\Actor.h>

class AMyPokemonSelectBox : public AActor
{
public:
	// constrcuter destructer
	AMyPokemonSelectBox();
	~AMyPokemonSelectBox();

	// delete Function
	AMyPokemonSelectBox(const AMyPokemonSelectBox& _Other) = delete;
	AMyPokemonSelectBox(AMyPokemonSelectBox&& _Other) noexcept = delete;
	AMyPokemonSelectBox& operator=(const AMyPokemonSelectBox& _Other) = delete;
	AMyPokemonSelectBox& operator=(AMyPokemonSelectBox&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* BoxRenderer = nullptr;
};


#pragma once
class AMyPokemonCancle
{
public:
	// constrcuter destructer
	AMyPokemonCancle();
	~AMyPokemonCancle();

	// delete Function
	AMyPokemonCancle(const AMyPokemonCancle& _Other) = delete;
	AMyPokemonCancle(AMyPokemonCancle&& _Other) noexcept = delete;
	AMyPokemonCancle& operator=(const AMyPokemonCancle& _Other) = delete;
	AMyPokemonCancle& operator=(AMyPokemonCancle&& _Other) noexcept = delete;

protected:

private:

};


#pragma once
class AEvolvePokemon
{
public:
	// constrcuter destructer
	AEvolvePokemon();
	~AEvolvePokemon();

	// delete Function
	AEvolvePokemon(const AEvolvePokemon& _Other) = delete;
	AEvolvePokemon(AEvolvePokemon&& _Other) noexcept = delete;
	AEvolvePokemon& operator=(const AEvolvePokemon& _Other) = delete;
	AEvolvePokemon& operator=(AEvolvePokemon&& _Other) noexcept = delete;

protected:

private:

};


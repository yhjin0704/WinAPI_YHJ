#pragma once

enum class ENature
{
	Hardy,
	Lonely,
	Adamant,
	Naughty,
	Brave,
	Bold,
	Docile,
	Impish,
	Lax,
	Relaxed,
	Modest,
	Mild,
	Bashful,
	Rash,
	Quiet,
	Calm,
	Gentle,
	Careful,
	Quirky,
	Sassy,
	Timid,
	Hasty,
	Jolly,
	Naive,
	Serious
};

class PokemonHelper
{
public:
	// constrcuter destructer
	PokemonHelper();
	~PokemonHelper();

	// delete Function
	PokemonHelper(const PokemonHelper& _Other) = delete;
	PokemonHelper(PokemonHelper&& _Other) noexcept = delete;
	PokemonHelper& operator=(const PokemonHelper& _Other) = delete;
	PokemonHelper& operator=(PokemonHelper&& _Other) noexcept = delete;

protected:

private:

};


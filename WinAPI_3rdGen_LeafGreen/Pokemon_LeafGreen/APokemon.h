#pragma once
class APokemon
{
public:
	// constrcuter destructer
	APokemon();
	~APokemon();

	// delete Function
	APokemon(const APokemon& _Other) = delete;
	APokemon(APokemon&& _Other) noexcept = delete;
	APokemon& operator=(const APokemon& _Other) = delete;
	APokemon& operator=(APokemon&& _Other) noexcept = delete;

protected:

private:

};


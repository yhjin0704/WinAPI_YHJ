#pragma once
#include <EngineCore/Actor.h>

class APokemon : public AActor
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
	std::string Tribe = "";
	float Hp = 1;
	float Atk = 1;
	float Def = 1;
	float SAtk = 1;
	float SDef = 1;
	float Spd = 1;
	std::string Ability = "";

	std::string Name = Tribe;
	int Level = 1;
	int Exp = 0;
	std::string Nature = "";
	float IVHp = 0;
	float IVAtk = 0;
	float IVDef = 0;
	float IVSAtk = 0;
	float IVSDef = 0;
	float IVSpd = 0;

private:

};


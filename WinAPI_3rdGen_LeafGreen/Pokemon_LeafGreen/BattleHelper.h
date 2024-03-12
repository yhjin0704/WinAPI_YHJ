#pragma once

enum class EBattleSequence
{
	Start,
	SetPokemon,
	Change,
	MyTurn,
	EnemyTurn,
	End
};

class BattleHelper
{
public:
	// constrcuter destructer
	BattleHelper();
	~BattleHelper();

	// delete Function
	BattleHelper(const BattleHelper& _Other) = delete;
	BattleHelper(BattleHelper&& _Other) noexcept = delete;
	BattleHelper& operator=(const BattleHelper& _Other) = delete;
	BattleHelper& operator=(BattleHelper&& _Other) noexcept = delete;

protected:

private:

};


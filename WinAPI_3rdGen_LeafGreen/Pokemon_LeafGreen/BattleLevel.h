#pragma once
#include <EngineCore\Level.h>
#include "PokemonInfo.h"
#include "BattleBackGround.h"
#include "BattleGround.h"
#include "BattlePokemonStatus.h"
#include "BattleTextBox.h"
#include "BattleSelectBox.h"
#include "BattleHelper.h"

class UBattleLevel : public ULevel
{
public:
	// constrcuter destructer
	UBattleLevel();
	~UBattleLevel();

	// delete Function
	UBattleLevel(const UBattleLevel& _Other) = delete;
	UBattleLevel(UBattleLevel&& _Other) noexcept = delete;
	UBattleLevel& operator=(const UBattleLevel& _Other) = delete;
	UBattleLevel& operator=(UBattleLevel&& _Other) noexcept = delete;

	std::string GetPrevLevelName()
	{
		return PrevLevelName;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	ABattleBackGround* BackGround;
	ABattleGround* EnemyGround;
	ABattleGround* PlayerGround;
	ABattlePokemonStatus* EnemyStatus;
	ABattlePokemonStatus* PlayerStatus;
	ABattleTextBox* TextBox;
	ABattleSelectBox* SelectBox;

	std::list<PokemonInfo> BattleEntry;
	PokemonInfo MyPokemon;

	PokemonInfo EnemyPokemon;

	std::string PrevLevelName = "";

	EBattleSequence BattleSequence = EBattleSequence::Start;

	bool FirstTurn = true;
	float Delay = 0;

	PokemonInfo SpawnWildPokemon(int _DexNo, int _Level);
	void TurnChange();
};


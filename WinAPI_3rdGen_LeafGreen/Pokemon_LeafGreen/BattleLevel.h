#pragma once
#include <EngineCore\Level.h>
#include "BattleBackGround.h"
#include "BattleGround.h"
#include "BattlePokemonStatus.h"

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
	std::list<PokemonInfo> Entry;

	ABattleBackGround* BackGround;
	ABattleGround* EnemyGround;
	ABattleGround* PlayerGround;
	ABattlePokemonStatus* EnemyStatus;
	ABattlePokemonStatus* PlayerStatus;

	std::string PrevLevelName = "";
};


#pragma once
#include <list>
#include "Pokemon.h"
#include "Global.h"

class PlayerHelper
{
public:
	// constrcuter destructer
	PlayerHelper();
	~PlayerHelper();

	// delete Function
	PlayerHelper(const PlayerHelper& _Other) = delete;
	PlayerHelper(PlayerHelper&& _Other) noexcept = delete;
	PlayerHelper& operator=(const PlayerHelper& _Other) = delete;
	PlayerHelper& operator=(PlayerHelper&& _Other) noexcept = delete;

	static EMoveType PlayerMoveType;
	static EMoveType PrevMoveType;
	static bool IsUseMenu;
	static bool PlayerPause;
	static inline std::list<APokemon> EntryPokemon = std::list<APokemon>();

protected:

private:

};


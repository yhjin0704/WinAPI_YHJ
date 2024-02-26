#pragma once
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

protected:

private:

};


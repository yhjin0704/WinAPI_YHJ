#include "PlayerHelper.h"

EMoveType PlayerHelper::PlayerMoveType = EMoveType::Walk;
EMoveType PlayerHelper::PrevMoveType = EMoveType::Walk;
bool PlayerHelper::IsUseMenu = false;
bool PlayerHelper::PlayerPause = false;

PlayerHelper::PlayerHelper()
{
}

PlayerHelper::~PlayerHelper()
{
}
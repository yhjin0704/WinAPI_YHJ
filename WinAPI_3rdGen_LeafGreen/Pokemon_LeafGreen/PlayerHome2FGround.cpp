#include "PlayerHome2FGround.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>

PlayerHome2FGround::PlayerHome2FGround()
{
}

PlayerHome2FGround::~PlayerHome2FGround()
{
}

void PlayerHome2FGround::BeginPlay()
{
	AGround::BeginPlay();

	SetMapImage("Player_Home_2F.png");
	SetColMapImage("Col_Player_Home_2F.png");
	SetCoverMapImage("Cover_Player_Home_2F.png");
}

void PlayerHome2FGround::Tick(float _DeltaTime)
{
	AGround::Tick(_DeltaTime);
}

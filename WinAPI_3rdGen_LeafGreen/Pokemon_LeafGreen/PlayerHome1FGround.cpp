#include "PlayerHome1FGround.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>

PlayerHome1FGround::PlayerHome1FGround()
{
}

PlayerHome1FGround::~PlayerHome1FGround()
{
}

void PlayerHome1FGround::BeginPlay()
{
	AGround::BeginPlay();

	SetMapImage("Player_Home_1F.png");
	SetColMapImage("Col_Player_Home_1F.png");
	SetCoverMapImage("Cover_Player_Home_1F.png");
}

void PlayerHome1FGround::Tick(float _DeltaTime)
{
	AGround::Tick(_DeltaTime);
}


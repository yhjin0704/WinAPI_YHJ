#include "WestFieldGround.h"

AWestFieldGround::AWestFieldGround()
{
}

AWestFieldGround::~AWestFieldGround()
{
}

void AWestFieldGround::BeginPlay()
{
	AGround::BeginPlay();

	SetMapImage("West_Map.png");
	SetColMapImage("Col_West_Map.png");
	SetCoverMapImage("Cover_West_Map.png");
}

void AWestFieldGround::Tick(float _DeltaTime)
{
	AGround::Tick(_DeltaTime);
}






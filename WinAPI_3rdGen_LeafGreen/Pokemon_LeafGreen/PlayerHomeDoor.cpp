#include "PlayerHomeDoor.h"
#include "Global.h"

APlayerHomeDoor::APlayerHomeDoor()
{
}

APlayerHomeDoor::~APlayerHomeDoor()
{
}

void APlayerHomeDoor::BeginPlay()
{
	HomeDoorCollision = CreateCollision(0);
	HomeDoorCollision->SetScale({ IGameTileScale, IGameTileScale });
	HomeDoorCollision->SetColType(ECollisionType::Rect);
}

void APlayerHomeDoor::Tick(float _DeltaTime) 
{
	
}
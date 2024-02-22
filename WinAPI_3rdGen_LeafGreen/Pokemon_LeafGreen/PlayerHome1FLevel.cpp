#include "PlayerHome1FLevel.h"
#include "Player.h"
#include "PlayerHome1FGround.h"
#include "PlayerHomeDoor.h"
#include "global.h"

UPlayerHome1FLevel::UPlayerHome1FLevel()
{
}

UPlayerHome1FLevel::~UPlayerHome1FLevel()
{
}

void UPlayerHome1FLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	PlayerHome1FGround* Ground = SpawnActor<PlayerHome1FGround>();
	APlayerHomeDoor* Door = SpawnActor<APlayerHomeDoor>();

	Door->SetActorLocation({ (48 + (FTileScale / 2)) * FScaleMultiple , (144) * FScaleMultiple });

	Player->SetActorLocation({ (48 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
}

void UPlayerHome1FLevel::Tick(float _DeltaTime)
{
}
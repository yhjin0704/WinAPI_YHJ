#include "WestFieldGround.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include "Global.h"

AWestFieldGround::AWestFieldGround()
{
}

AWestFieldGround::~AWestFieldGround()
{
}

void AWestFieldGround::BeginPlay()
{
	AActor::BeginPlay();

	SetActorLocation({ 0, 0 });

	Renderer = CreateImageRenderer(Map);
	Renderer->SetImage("West_Map.png");
	Renderer->SetTransform({ {FGBAScreen_X * 1.5f, FGBAScreen_Y * 1.5f}, {FScreen_X, FScreen_Y} });
}

void AWestFieldGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}


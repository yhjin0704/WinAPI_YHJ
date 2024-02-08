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

void AWestFieldGround::SetMapImage(std::string_view _MapImageName)
{
	MapRenderer->SetImage(_MapImageName);
	UWindowImage* MapImage = MapRenderer->GetImage();
	MapRenderer->SetTransform({ {FGBAScreen_X * 1.5f, FGBAScreen_Y * 1.5f}, {FScreen_X, FScreen_Y} });
}

void AWestFieldGround::SetColMapImage(std::string_view _MapImageName)
{
	ColMapRenderer->SetImage(_MapImageName);
	UWindowImage* Image = ColMapRenderer->GetImage();
	//UContentsHelper::ColMapImage = Image;
	ColMapRenderer->SetTransform({ {FGBAScreen_X * 1.5f, FGBAScreen_Y * 1.5f}, {FScreen_X, FScreen_Y} });
}

void AWestFieldGround::BeginPlay()
{
	AActor::BeginPlay();

	MapRenderer = CreateImageRenderer(Map);
	ColMapRenderer = CreateImageRenderer(ColMap);
	ColMapRenderer->SetActive(false);
}

void AWestFieldGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}


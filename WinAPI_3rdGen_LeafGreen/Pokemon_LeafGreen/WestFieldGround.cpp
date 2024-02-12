#include "WestFieldGround.h"
#include "Player.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDirectory.h>
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
	FVector ImageScale = MapImage->GetScale();
	MapRenderer->SetTransform({ (ImageScale.Half2D() * FScale_Multiple), (ImageScale * FScale_Multiple)});
	int a = 0;
}

void AWestFieldGround::SetColMapImage(std::string_view _MapImageName)
{
	ColMapRenderer->SetImage(_MapImageName);
	UWindowImage* ColMapImage = ColMapRenderer->GetImage();
	FVector ImageScale = ColMapImage->GetScale();
	//UContentsHelper::ColMapImage = Image;
	ColMapRenderer->SetTransform({ (ImageScale.Half2D() * FScale_Multiple), (ImageScale * FScale_Multiple) });
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


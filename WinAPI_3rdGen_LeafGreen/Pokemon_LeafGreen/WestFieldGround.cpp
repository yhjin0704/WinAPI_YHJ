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
	MapRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), (ImageScale * FScaleMultiple)});
}

void AWestFieldGround::SetColMapImage(std::string_view _MapImageName)
{
	ColMapRenderer->SetImage(_MapImageName);
	UWindowImage* ColMapImage = ColMapRenderer->GetImage();
	Global::GColMapImage = ColMapImage;
	FVector ImageScale = ColMapImage->GetScale();
	ColMapRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), (ImageScale * FScaleMultiple) });
}

void AWestFieldGround::SwitchDebug()
{
	if (true == MapRenderer->IsActive())
	{
		MapRenderer->SetActive(false, 10.0f);
		ColMapRenderer->SetActive(true);
	}
	else
	{
		MapRenderer->SetActive(true);
		ColMapRenderer->SetActive(false);
	}
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

	if (UEngineInput::IsDown('0'))
	{
		SwitchDebug();
	}
}


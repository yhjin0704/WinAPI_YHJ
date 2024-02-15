#include "Ground.h"
#include <EnginePlatform\EngineInput.h>
#include "Global.h"

AGround::AGround()
{
}

AGround::~AGround()
{
}

void AGround::SwitchDebug()
{
	if (true == MapRenderer->IsActive())
	{
		MapRenderer->SetActive(false);
		ColMapRenderer->SetActive(true);
	}
	else
	{
		MapRenderer->SetActive(true);
		ColMapRenderer->SetActive(false);
	}
}

void AGround::BeginPlay()
{
	AActor::BeginPlay();
	MapRenderer = CreateImageRenderer(ERenderOrder::Map);
	ColMapRenderer = CreateImageRenderer(ERenderOrder::ColMap);
	ColMapRenderer->SetActive(false);
}

void AGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown('0'))
	{
		SwitchDebug();
	}
}

void AGround::SetMapImage(std::string_view _MapImageName)
{
	MapRenderer->SetImage(_MapImageName);
	UWindowImage* MapImage = MapRenderer->GetImage();
	FVector ImageScale = MapImage->GetScale();
	MapRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), (ImageScale * FScaleMultiple) });
}

void AGround::SetColMapImage(std::string_view _MapImageName)
{
	ColMapRenderer->SetImage(_MapImageName);
	UWindowImage* ColMapImage = ColMapRenderer->GetImage();
	Global::GColMapImage = ColMapImage;
	FVector ImageScale = ColMapImage->GetScale();
	ColMapRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), (ImageScale * FScaleMultiple) });
}
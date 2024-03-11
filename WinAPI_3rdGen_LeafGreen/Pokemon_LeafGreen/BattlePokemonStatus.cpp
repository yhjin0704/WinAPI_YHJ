#include "BattlePokemonStatus.h"
#include "Global.h"

ABattlePokemonStatus::ABattlePokemonStatus()
{
}

ABattlePokemonStatus::~ABattlePokemonStatus()
{
}

void ABattlePokemonStatus::BeginPlay()
{
	AActor::BeginPlay();

	StatusWindowRenderer = CreateImageRenderer(ERenderOrder::Menu);
}

void ABattlePokemonStatus::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ABattlePokemonStatus::SetRenderer(std::string_view _Image)
{
	StatusWindowRenderer->SetImage(_Image);
	UWindowImage* Image = StatusWindowRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	StatusWindowRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), {ImageScale * FScaleMultiple} });
}
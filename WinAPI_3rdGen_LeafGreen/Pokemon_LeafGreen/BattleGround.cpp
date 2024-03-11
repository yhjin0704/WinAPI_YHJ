#include "BattleGround.h"
#include "Global.h"

ABattleGround::ABattleGround()
{
}

ABattleGround::~ABattleGround()
{
}

void ABattleGround::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(ERenderOrder::Object);
}

void ABattleGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ABattleGround::SetRenderer(std::string_view _Image)
{
	Renderer->SetImage(_Image);
	UWindowImage* Image = Renderer->GetImage();
	FVector ImageScale = Image->GetScale();
	Renderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), {ImageScale * FScaleMultiple} });
}
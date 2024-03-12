#include "BattleTextBox.h"
#include "Global.h"

ABattleTextBox::ABattleTextBox()
{
}

ABattleTextBox::~ABattleTextBox()
{
}

void ABattleTextBox::BeginPlay()
{
	AActor::BeginPlay();

	BoxRenderer = CreateImageRenderer(ERenderOrder::Menu);
	TextRendererTop = CreateImageRenderer(ERenderOrder::Text);
	TextRendererBottom = CreateImageRenderer(ERenderOrder::Text);

	TextRendererTop->ActiveOff();
	TextRendererBottom->ActiveOff();

	BoxRenderer->SetImage("BattleMsgBox.png");
	UWindowImage* Image = BoxRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	BoxRenderer->SetTransform({ {120.0f * FScaleMultiple, 136.0f * FScaleMultiple }, { ImageScale * FScaleMultiple }});
}

void ABattleTextBox::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
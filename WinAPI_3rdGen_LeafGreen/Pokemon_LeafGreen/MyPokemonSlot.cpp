#include "MyPokemonSlot.h"
#include "Pokemon3rdGen_Core.h"

AMyPokemonSlot::AMyPokemonSlot()
{
}

AMyPokemonSlot::~AMyPokemonSlot()
{
}

void AMyPokemonSlot::BeginPlay()
{
	AActor::BeginPlay();

	PokemonSlotRenderer = CreateImageRenderer(ERenderOrder::Menu);
	/*PokemonImageRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonNameRenderer	= CreateImageRenderer(ERenderOrder::Text);
	PokemonLevelRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonGenderRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHPRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHpTextRenderer = CreateImageRenderer(ERenderOrder::Text);*/
}

void AMyPokemonSlot::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AMyPokemonSlot::SetSlotRenderer(std::string_view _Image, float _X, float _Y)
{
	PokemonSlotRenderer->SetImage(_Image);
	UWindowImage* Image = PokemonSlotRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	PokemonSlotRenderer->SetTransform({ { _X, _Y }, (ImageScale * FScaleMultiple) });
}
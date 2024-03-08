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
	PokemonImageRenderer = CreateImageRenderer(ERenderOrder::Text);
	//PokemonNameRenderer	= CreateImageRenderer(ERenderOrder::Text);
	//PokemonLevelRenderer = CreateImageRenderer(ERenderOrder::Text);
	//PokemonGenderRenderer = CreateImageRenderer(ERenderOrder::Text);
	//PokemonHPRenderer = CreateImageRenderer(ERenderOrder::Text);
	//PokemonHpTextRenderer = CreateImageRenderer(ERenderOrder::Text);
}

void AMyPokemonSlot::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AMyPokemonSlot::SetSlotRenderer(std::string_view _SlotImage, float _Slot_X, float _Slot_Y)
{
	PokemonSlotRenderer->SetImage(_SlotImage);
	UWindowImage* SlotImage = PokemonSlotRenderer->GetImage();
	FVector SlotImageScale = SlotImage->GetScale();
	PokemonSlotRenderer->SetTransform({ { _Slot_X, _Slot_Y }, (SlotImageScale * FScaleMultiple) });
}

void AMyPokemonSlot::SetDotRenderer(std::string_view _AniName, float _Ani_X, float _Ani_Y, PokemonInfo _Entry)
{
	PokemonImageRenderer->CreateAnimation(_AniName, "1st_Gen_Dot.png", _Entry.DotAnimationStart, _Entry.DotAnimationEnd, 0.5f, true);
	PokemonImageRenderer->SetTransform({ { _Ani_X, _Ani_Y }, {32.0f * FScaleMultiple, 32.0f * FScaleMultiple} });
	PokemonImageRenderer->ChangeAnimation(_AniName, false, 0, 0.5f);
}
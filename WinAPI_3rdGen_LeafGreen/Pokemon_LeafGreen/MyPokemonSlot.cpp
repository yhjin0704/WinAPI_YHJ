#include "MyPokemonSlot.h"
#include "Pokemon3rdGen_Core.h"
#include "Global.h"

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
	PokemonNameRenderer	= CreateImageRenderer(ERenderOrder::Text);
	//PokemonLevelRenderer = CreateImageRenderer(ERenderOrder::Text);
	//PokemonGenderRenderer = CreateImageRenderer(ERenderOrder::Text);
	//PokemonHPRenderer = CreateImageRenderer(ERenderOrder::Text);
	//PokemonMaxHpRenderer = CreateImageRenderer(ERenderOrder::Text);
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
	PokemonSlotRenderer->SetTransform({ { _Slot_X * FScaleMultiple, _Slot_Y * FScaleMultiple }, (SlotImageScale * FScaleMultiple) });
}

void AMyPokemonSlot::SetDotRenderer(float _Ani_X, float _Ani_Y, PokemonInfo _Entry)
{
	if (false == PokemonImageRenderer->IsAnimation(_Entry.Tribe + "_Dot"))
	{
		PokemonImageRenderer->CreateAnimation(_Entry.Tribe + "_Dot", "1st_Gen_Dot.png", _Entry.DotAnimationStart, _Entry.DotAnimationEnd, 0.5f, true);
	}
	PokemonImageRenderer->SetTransform({ { _Ani_X * FScaleMultiple, _Ani_Y * FScaleMultiple }, {32.0f * FScaleMultiple, 32.0f * FScaleMultiple} });
	PokemonImageRenderer->ChangeAnimation(_Entry.Tribe + "_Dot", false, 0, 0.5f);
}

void AMyPokemonSlot::SetDataRenderers(PokemonInfo _Entry, float _Name_X, float _Name_Y)
{
	//PokemonNameRenderer->SetTextSortOption(Gdiplus::StringAlignment::StringAlignmentCenter, Gdiplus::StringAlignment::StringAlignmentFar);
	Global::SetPokemonText(PokemonNameRenderer, _Entry.Name, Color8Bit::WhiteA);
	PokemonNameRenderer->SetTransform({ { _Name_X * FScaleMultiple, _Name_Y * FScaleMultiple }, { 0, 0 } });
}
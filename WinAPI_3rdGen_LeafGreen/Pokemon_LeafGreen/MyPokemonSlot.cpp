#include "MyPokemonSlot.h"

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
	PokemonLevelRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonGenderRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHPRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHpTextRenderer = CreateImageRenderer(ERenderOrder::Text);
}

void AMyPokemonSlot::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
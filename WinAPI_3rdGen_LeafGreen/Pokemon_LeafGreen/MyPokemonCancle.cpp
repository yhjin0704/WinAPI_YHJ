#include "MyPokemonCancle.h"
#include "Global.h"

AMyPokemonCancle::AMyPokemonCancle()
{
}

AMyPokemonCancle::~AMyPokemonCancle()
{
}

void AMyPokemonCancle::BeginPlay()
{
	AActor::BeginPlay();

	ButtonRenderer = CreateImageRenderer(ERenderOrder::Text);
	ButtonRenderer->SetImage("MyPokemon_Cancel_Button.png");
}

void AMyPokemonCancle::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
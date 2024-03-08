#include "MyPokemonLevel.h"
#include "Pokemon3rdGen_Core.h"

UMyPokemonLevel::UMyPokemonLevel()
{
}

UMyPokemonLevel::~UMyPokemonLevel()
{
}

void UMyPokemonLevel::BeginPlay()
{
	UMenuUILevel::BeginPlay();

	BackGround = SpawnActor<AMyPokemonBackGround>();
	Slot1st = SpawnActor<AMyPokemonSlot>();
	/*Slot2nd = SpawnActor<AMyPokemonSlot>();
	Slot3rd = SpawnActor<AMyPokemonSlot>();
	Slot4th = SpawnActor<AMyPokemonSlot>();
	Slot5th = SpawnActor<AMyPokemonSlot>();
	Slot6th = SpawnActor<AMyPokemonSlot>();*/
}

void UMyPokemonLevel::Tick(float _DeltaTime)
{
	UMenuUILevel::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('L'))
	{
		GEngine->ChangeLevel(PrevLevelName);
	}
}

void UMyPokemonLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();

	std::list<PokemonInfo> UIEntry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
	std::list<PokemonInfo>::iterator UIEntryIter;

	UIEntryIter = UIEntry.begin();
	Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f * FScaleMultiple, 47.5f * FScaleMultiple);
	Slot1st->SetDotRenderer(16.0f * FScaleMultiple, 41.0f * FScaleMultiple, *UIEntryIter);
}

void UMyPokemonLevel::LevelEnd(ULevel* _NextLevel)
{

}
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
	Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 47.5f);
	Slot1st->SetDotRenderer(16.0f, 41.0f, *UIEntryIter);
	Slot1st->SetDataRenderers(*UIEntryIter, 
		30.0f, 34.0f, 
		46.0f, 44.6f, 
		76.0f, 52.0f,
		56.0f, 60.5f,
		63.0f, 74.0f, 
		65.0f, 60.5f);
}

void UMyPokemonLevel::LevelEnd(ULevel* _NextLevel)
{

}
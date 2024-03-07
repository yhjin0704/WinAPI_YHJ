#include "MyPokemonLevel.h"

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
	Slot1st->SetSlotRenderer("MyPokemon_First.png", 128.0f, 136.0f);
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
}

void UMyPokemonLevel::LevelEnd(ULevel* _NextLevel)
{
}
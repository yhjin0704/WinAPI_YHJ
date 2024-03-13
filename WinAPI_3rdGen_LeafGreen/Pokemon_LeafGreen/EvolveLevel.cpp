#include "EvolveLevel.h"
#include "Pokemon3rdGen_Core.h"
#include "PlayerHelper.h"

UEvolveLevel::UEvolveLevel()
{
}

UEvolveLevel::~UEvolveLevel()
{
}

void UEvolveLevel::BeginPlay()
{
	ULevel::BeginPlay();


}

void UEvolveLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}

void UEvolveLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();

	Entry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
	MyPokemon = Entry.front();
}

void UEvolveLevel::LevelEnd(ULevel* _NextLevel)
{
	PlayerHelper::IsEncount = false;
	PlayerHelper::IsWild = false;
	Entry.front() = MyPokemon;
	dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->SetEntry(Entry);
}
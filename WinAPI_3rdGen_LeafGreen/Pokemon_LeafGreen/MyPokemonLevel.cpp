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
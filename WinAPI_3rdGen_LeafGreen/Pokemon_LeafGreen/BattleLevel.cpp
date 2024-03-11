#include "BattleLevel.h"
#include <EngineCore\EngineCore.h>
#include "PlayerHelper.h"

UBattleLevel::UBattleLevel()
{
}

UBattleLevel::~UBattleLevel()
{
}

void UBattleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	BackGround = SpawnActor<ABattleBackGround>();
	EnemyGround = SpawnActor<ABattleGround>();
	PlayerGround = SpawnActor<ABattleGround>();
	EnemyStatus = SpawnActor<ABattlePokemonStatus>();
	PlayerStatus = SpawnActor<ABattlePokemonStatus>();

	EnemyGround->SetRenderer("BattleEnemyGround_Grass.png");
	PlayerGround->SetRenderer("BattlePlayerGround_Grass.png");
	EnemyStatus->SetRenderer("BattleEnemyPokemonStatus.png");
	PlayerStatus->SetRenderer("BattlePlayerPokemonStatus.png");
}

void UBattleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('L'))
	{
		GEngine->ChangeLevel(PrevLevelName);
	}
}

void UBattleLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();
}

void UBattleLevel::LevelEnd(ULevel* _NextLevel)
{
	PlayerHelper::IsEncount = false;
}
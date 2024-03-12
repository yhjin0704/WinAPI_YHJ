#include "BattleLevel.h"
#include <EngineCore\EngineCore.h>
#include "Pokemon3rdGen_Core.h"
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
	TextBox = SpawnActor<ABattleTextBox>();

	EnemyGround->SetGroundRenderer("BattleEnemyGround_Grass.png");
	PlayerGround->SetGroundRenderer("BattlePlayerGround_Grass.png");
	EnemyStatus->SetRenderer("BattleEnemyPokemonStatus.png");
	PlayerStatus->SetRenderer("BattlePlayerPokemonStatus.png");
}

void UBattleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	EnemyStatus->SetDataRenderers(EnemyPokemon, true,
		19.0f, 18.0f,
		101.0f, 32.0f, 
		65.0f, 25.0f, 
		77.0f, 34.5f,
		0.0f, 0.0f, 
		0.0f, 0.0f);
	PlayerStatus->SetDataRenderers(MyPokemon, false,
		142.0f, 77.0f,
		224.0f, 91.0f,
		188.0f, 84.0f,
		200.0f, 93.5f,
		205.0f, 108.2f,
		207.0f, 94.7f);

	EnemyGround->SetPokemonRenderer(EnemyPokemon, true);
	PlayerGround->SetPokemonRenderer(MyPokemon, false);

	if (true == UEngineInput::IsDown('L'))
	{
		GEngine->ChangeLevel(PrevLevelName);
	}
}

void UBattleLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();
	BattleEntry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
	MyPokemon = BattleEntry.front();

	if (Color8Bit(1, 255, 0, 0) == PlayerHelper::EncountGround && true == PlayerHelper::IsWild)
	{
		EnemyPokemon = SpawnWildPokemon(4, UEngineRandom::MainRandom.RandomInt(2, 4));
	}
	TextBox->SetTextTop("앗, 야생의 경택이가 나타났다");
	TextBox->SetTextBottom("큰일이넹...");
	
}

void UBattleLevel::LevelEnd(ULevel* _NextLevel)
{
	PlayerHelper::IsEncount = false; 
	PlayerHelper::IsWild = false;
	dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->SetEntry(BattleEntry);
}

PokemonInfo UBattleLevel::SpawnWildPokemon(int _DexNo, int _Level)
{
	PokemonInfo info = Pokemon3rdGen_Core::GetAllPokemonInfo()[_DexNo];
	info.PokemonInfo::CalStatus(_Level);
	if (0 == info.MeetLevel)
	{
		info.MeetLevel = _Level;
	}
	return info;
}
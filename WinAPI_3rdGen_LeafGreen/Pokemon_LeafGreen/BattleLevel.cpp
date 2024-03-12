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
	SelectBox = SpawnActor<ABattleSelectBox>();

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

	if (true == UEngineInput::IsDown('P'))
	{
		switch (BattleSequence)
		{
		case EBattleSequence::Start:
			BattleSequence = EBattleSequence::SetPokemon;
			break;
		case EBattleSequence::SetPokemon:
			if (MyPokemon.Spd >= EnemyPokemon.Spd)
			{
				BattleSequence = EBattleSequence::MyTurn;
			}
			else
			{
				BattleSequence = EBattleSequence::EnemyTurn;
			}
			break;
		case EBattleSequence::MyTurn:
			break;
		default:
			break;
		}
	}

	switch (BattleSequence)
	{
	case EBattleSequence::SetPokemon:
		TextBox->TextOff();
		TextBox->SetTextTop("가랏 " + MyPokemon.Name + "!");

		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			if (MyPokemon.Spd >= EnemyPokemon.Spd)
			{
				BattleSequence = EBattleSequence::MyTurn;
			}
			else
			{
				BattleSequence = EBattleSequence::EnemyTurn;
			}
		}
		break;
	case EBattleSequence::Change:
		TextBox->TextOff();
		TextBox->SetTextTop("가랏 " + MyPokemon.Name + "!");

		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			if (true == FirstTurn)
			{
				BattleSequence = EBattleSequence::EnemyTurn;
			}
			else
			{
				if (MyPokemon.Spd >= EnemyPokemon.Spd)
				{
					BattleSequence = EBattleSequence::MyTurn;
				}
				else
				{
					BattleSequence = EBattleSequence::EnemyTurn;
				}
			}
		}
		break;
	case EBattleSequence::MyTurn:
		TurnChange();

		TextBox->TextOff();
		TextBox->SetTextTop(MyPokemon.Name + "(은)는");
		TextBox->SetTextBottom("무엇을 할까?");

		SelectBox->SetSelectBoxActive(true);
		SelectBox->SetSelectBoxTextActive(true);
		break;
	case EBattleSequence::EnemyTurn:
		TurnChange();
		break;
	case EBattleSequence::End:
		break;
	default:
		break;
	}

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

	TextBox->TextOff();
	SelectBox->SetSelectBoxActive(false);
	SelectBox->SetSelectBoxTextActive(false);
	BattleSequence = EBattleSequence::Start;
	FirstTurn = false;

	if (true == PlayerHelper::IsWild)
	{
		if (Color8Bit(1, 255, 0, 0) == PlayerHelper::EncountGround)
		{
			EnemyPokemon = SpawnWildPokemon(4, UEngineRandom::MainRandom.RandomInt(2, 4));
		}
		TextBox->SetTextTop("앗! 야생의 " + EnemyPokemon.Name + "(이)가 나타났다");
		Delay = 1.5f;
	}
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

void UBattleLevel::TurnChange()
{
	if (true == FirstTurn)
	{
		FirstTurn = false;
	}
	else
	{
		FirstTurn = true;
	}
}

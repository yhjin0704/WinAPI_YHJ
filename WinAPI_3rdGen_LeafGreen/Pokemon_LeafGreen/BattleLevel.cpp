#include "BattleLevel.h"
#include <EngineCore\EngineCore.h>
#include "Pokemon3rdGen_Core.h"
#include "PlayerHelper.h"
#include "Player.h"

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

	if (true == UEngineInput::IsDown('P') && false == IsDelay)
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
			switch (BattleSelectCursor)
			{
			case EBattleSelect::Fight:
				Dmg = BattleHelper::CalDamage(EPSMove::물리, MyPokemon.Level, MyPokemon.Atk, MyPokemon.SAtk, MyPokemon.Type1, MyPokemon.Type2, EnemyPokemon.Def, EnemyPokemon.SDef, EnemyPokemon.Type1, EnemyPokemon.Type2, 35, 95, EType::노말);
				EnemyPokemon.Hp -= Dmg;
				++Sequence;
				break;
			case EBattleSelect::Bag:
				GEngine->ChangeLevel("MyBagLevel");
				break;
			case EBattleSelect::Pokemon:
				GEngine->ChangeLevel("MyPokemonLevel");
				break;
			case EBattleSelect::Run:
				TextBox->TextOff();
				TextBox->SetTextTop("성공적으로 도망쳤다!");

				IsDelay = true;
				Delay -= _DeltaTime;
				if (0 >= Delay)
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::End;
				}
				break;
			case EBattleSelect::Move1:
				break;
			case EBattleSelect::Move2:
				break;
			case EBattleSelect::Move3:
				break;
			case EBattleSelect::Move4:
				break;
			default:
				break;
			}
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

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			if (MyPokemon.Spd >= EnemyPokemon.Spd)
			{
				IsDelay = false;
				Delay = 1.5f;
				BattleSequence = EBattleSequence::MyTurn;
			}
			else
			{
				IsDelay = false;
				Delay = 1.5f;
				BattleSequence = EBattleSequence::EnemyTurn;
			}
		}
		break;
	case EBattleSequence::Change:
		TextBox->TextOff();
		TextBox->SetTextTop("가랏 " + MyPokemon.Name + "!");

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			if (true == FirstTurn)
			{
				IsDelay = false;
				Delay = 1.5f;
				BattleSequence = EBattleSequence::EnemyTurn;
			}
			else
			{
				if (MyPokemon.Spd >= EnemyPokemon.Spd)
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::MyTurn;
				}
				else
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::EnemyTurn;
				}
			}
		}
		break;
	case EBattleSequence::MyTurn:
		switch (Sequence)
		{
		case 0:
			TurnChange();

			TextBox->TextOff();
			TextBox->SetTextTop(MyPokemon.Name + "(은)는");
			TextBox->SetTextBottom("무엇을 할까?");

			SelectBox->SetSelectBoxActive(true);
			SelectBox->SetSelectBoxTextActive(true);
			SelectBox->SetCursorActive(true);

			switch (BattleSelectCursor)
			{
			case EBattleSelect::Fight:
				CursorMovePos(132.0f, 129.0f, EBattleSelect::Pokemon, EBattleSelect::Bag);
				break;
			case EBattleSelect::Bag:
				CursorMovePos(188.0f, 129.0f, EBattleSelect::Run, EBattleSelect::Fight);
				break;
			case EBattleSelect::Pokemon:
				CursorMovePos(132.0f, 145.0f, EBattleSelect::Fight, EBattleSelect::Run);
				break;
			case EBattleSelect::Run:
				CursorMovePos(188.0f, 145.0f, EBattleSelect::Bag, EBattleSelect::Pokemon);
				break;
			default:
				break;
			}
			break;
		case 1:
			TextBox->TextOff();
			TextBox->SetTextTop(MyPokemon.Name + "의");
			TextBox->SetTextBottom("몸통박치기!");

			SelectBox->SetSelectBoxActive(false);
			SelectBox->SetSelectBoxTextActive(false);
			SelectBox->SetCursorActive(false);

			IsDelay = true;
			Delay -= _DeltaTime;
			if (0 >= Delay)
			{
				IsDelay = false;
				Delay = 1.5f;
				++Sequence;
			}
			break;
		case 2:
			if (0 >= EnemyPokemon.Hp)
			{
				TextBox->TextOff();
				TextBox->SetTextTop(EnemyPokemon.Name + "(은)는");
				TextBox->SetTextBottom("쓰러졌다");

				if (true == PlayerHelper::IsWild)
				{
					MyPokemon.Exp += BattleHelper::CalExp(EnemyPokemon.Level, 1.0f);
					MyPokemon.Exp += 200;
				}

				IsDelay = true;
				Delay -= _DeltaTime;
				if (0 >= Delay)
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::End;
				}
			}
			else
			{
				Sequence = 0;
				BattleSequence = EBattleSequence::EnemyTurn;
			}
			break;
		default:
			break;
		}
		break;
	case EBattleSequence::EnemyTurn:
		TurnChange();

		TextBox->TextOff();

		SelectBox->SetSelectBoxActive(false);
		SelectBox->SetSelectBoxTextActive(false);
		SelectBox->SetCursorActive(false);

		switch (Sequence)
		{
		case 0:
			Dmg = BattleHelper::CalDamage(EPSMove::물리, EnemyPokemon.Level, EnemyPokemon.Atk, EnemyPokemon.SAtk, EnemyPokemon.Type1, EnemyPokemon.Type2, MyPokemon.Def, MyPokemon.SDef, MyPokemon.Type1, MyPokemon.Type2, 35, 95, EType::노말);
			MyPokemon.Hp -= Dmg;
			++Sequence;
			break;
		case 1:
			TextBox->TextOff();
			TextBox->SetTextTop(EnemyPokemon.Name + "의");
			TextBox->SetTextBottom("몸통박치기!");

			IsDelay = true;
			Delay -= _DeltaTime;
			if (0 >= Delay)
			{
				IsDelay = false;
				Delay = 1.5f;
				++Sequence;
			}
			break;
		case 2:
			if (0 >= MyPokemon.Hp)
			{
				TextBox->TextOff();
				TextBox->SetTextTop(MyPokemon.Name + "(은)는");
				TextBox->SetTextBottom("쓰러졌다");

				IsDelay = true;
				Delay -= _DeltaTime;
				if (0 >= Delay)
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::End;
				}
			}
			else
			{
				Sequence = 0;
				BattleSequence = EBattleSequence::MyTurn;
			}
			break;
		default:
			break;
		}
		break;
	case EBattleSequence::End:
		MyPokemon.LevelUpCheck();
		GEngine->ChangeLevel(PrevLevelName);
		break;
	default:
		break;
	}

	if (true == UEngineInput::IsDown('L'))
	{
		IsDelay = false;
		Delay = 1.5f;
		GEngine->ChangeLevel(PrevLevelName);
	}
}

void UBattleLevel::LevelStart(ULevel* _PrevLevel)
{
	if (UEngineString::ToUpper("MyPokemonLevel") != _PrevLevel->GetName() && UEngineString::ToUpper("MyBagLevel") != _PrevLevel->GetName())
	{
		PrevLevelName = _PrevLevel->GetName();
		BattleSequence = EBattleSequence::Start;
		BattleSelectCursor = EBattleSelect::Fight;
	}

	BattleEntry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
	MyPokemon = BattleEntry.front();

	TextBox->TextOff();

	SelectBox->SetSelectBoxActive(false);
	SelectBox->SetSelectBoxTextActive(false);
	SelectBox->SetCursorActive(false);

	Sequence = 0;


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
	BattleEntry.front() = MyPokemon;
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

void UBattleLevel::CursorMovePos(float _X, float _Y, EBattleSelect _MoveLength, EBattleSelect _MoveWidth)
{
	SelectBox->SetCursorRocation(_X, _Y);
	if (true == UEngineInput::IsDown('W') || true == UEngineInput::IsDown('S'))
	{
		BattleSelectCursor = _MoveLength;
	}
	else if (true == UEngineInput::IsDown('A') || true == UEngineInput::IsDown('D'))
	{
		BattleSelectCursor = _MoveWidth;
	}
}
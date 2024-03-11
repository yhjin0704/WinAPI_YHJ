#include "MyPokemonLevel.h"
#include "Pokemon3rdGen_Core.h"
#include <EngineCore/Actor.h>

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
	Slot2nd = SpawnActor<AMyPokemonSlot>();
	Slot3rd = SpawnActor<AMyPokemonSlot>();
	Slot4th = SpawnActor<AMyPokemonSlot>();
	Slot5th = SpawnActor<AMyPokemonSlot>();
	Slot6th = SpawnActor<AMyPokemonSlot>();

	//Cancle = SpawnActor<AMyPokemonCancle>();
	//Cancle->SetActorLocation({ 200.0f * FScaleMultiple, 150.0f * FScaleMultiple });
}

void UMyPokemonLevel::Tick(float _DeltaTime)
{
	UMenuUILevel::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('W'))
	{
		--SelectSlot;
		if (0 > SelectSlot)
		{
			SelectSlot = 6;
		}
	}
	else if (true == UEngineInput::IsDown('S'))
	{
		++SelectSlot;
		if (6 < SelectSlot)
		{
			SelectSlot = 0;
		}
	}

	switch (SelectSlot)
	{
	case 0:
		Slot1st->SetSlotRenderer("MyPokemon_First_Select.png", 44.0f, 46.5f);
		CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
		CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
		CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
		CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
		CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		break;
	case 1:
		if (false == Slot2nd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			Slot2nd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		}
		else
		{
			SelectSlot = 6;
		}
		break;
	case 2:
		if (false == Slot3rd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			Slot3rd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		}
		else
		{
			SelectSlot = 6;
		}
		break;
	case 3:
		if (false == Slot4th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 1));
			Slot4th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		}
		else
		{
			SelectSlot = 6;
		}
		break;
	case 4:
		if (false == Slot5th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			Slot5th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		}
		else
		{
			SelectSlot = 6;
		}
		break;
	case 5:
		if (false == Slot6th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			Slot6th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 4));
		}
		else
		{
			SelectSlot = 6;
		}
		break;
	case 6:
		Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
		CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
		CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
		CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
		CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
		CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		break;
	default:
		break;
	}

	if (true == UEngineInput::IsDown('L'))
	{
		GEngine->ChangeLevel(PrevLevelName);
	}
}

void UMyPokemonLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();

	SelectSlot = 0;

	Slot2nd->IsEmpty(163.0f, 20.5f);
	Slot3rd->IsEmpty(163.0f, 20.5f + (24.0f * 1));
	Slot4th->IsEmpty(163.0f, 20.5f + (24.0f * 2));
	Slot5th->IsEmpty(163.0f, 20.5f + (24.0f * 3));
	Slot6th->IsEmpty(163.0f, 20.5f + (24.0f * 4));

	std::list<PokemonInfo> UIEntry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
	std::list<PokemonInfo>::iterator UIEntryIter;

	UIEntryIter = UIEntry.begin();
	Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
	Slot1st->SetDotRenderer(16.0f, 41.0f, *UIEntryIter);
	Slot1st->SetDataRenderers(*UIEntryIter,
		30.0f, 34.0f,
		46.0f, 44.6f,
		76.0f, 52.0f,
		56.0f, 60.5f,
		63.0f, 74.0f,
		66.0f, 60.5f);

	UIEntryIter++;
	if (UIEntryIter != UIEntry.end())
	{
		Slot2nd->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f);
		Slot2nd->SetDotRenderer(101.0f, 23.0f, *UIEntryIter);
		Slot2nd->SetDataRenderers(*UIEntryIter,
			115.0f, 10.0f,
			134.0f, 20.6f,
			164.0f, 28.0f,
			208.0f, 19.5f,
			215.0f, 33.0f,
			218.0f, 19.5f);

		UIEntryIter++;
		if (UIEntryIter != UIEntry.end())
		{
			Slot3rd->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 1));
			Slot3rd->SetDotRenderer(101.0f, 23.0f + (24.0f * 1), *UIEntryIter);
			Slot3rd->SetDataRenderers(*UIEntryIter,
				115.0f, 10.0f + (24.0f * 1),
				134.0f, 20.6f + (24.0f * 1),
				164.0f, 28.0f + (24.0f * 1),
				208.0f, 19.5f + (24.0f * 1),
				215.0f, 33.0f + (24.0f * 1),
				218.0f, 19.5f + (24.0f * 1));

			UIEntryIter++;
			if (UIEntryIter != UIEntry.end())
			{
				Slot4th->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 2));
				Slot4th->SetDotRenderer(101.0f, 23.0f + (24.0f * 2), *UIEntryIter);
				Slot4th->SetDataRenderers(*UIEntryIter,
					115.0f, 10.0f + (24.0f * 2),
					134.0f, 20.6f + (24.0f * 2),
					164.0f, 28.0f + (24.0f * 2),
					208.0f, 19.5f + (24.0f * 2),
					215.0f, 33.0f + (24.0f * 2),
					218.0f, 19.5f + (24.0f * 2));

				UIEntryIter++;
				if (UIEntryIter != UIEntry.end())
				{
					Slot5th->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 3));
					Slot5th->SetDotRenderer(101.0f, 23.0f + (24.0f * 3), *UIEntryIter);
					Slot5th->SetDataRenderers(*UIEntryIter,
						115.0f, 10.0f + (24.0f * 3),
						134.0f, 20.6f + (24.0f * 3),
						164.0f, 28.0f + (24.0f * 3),
						208.0f, 19.5f + (24.0f * 3),
						215.0f, 33.0f + (24.0f * 3),
						218.0f, 19.5f + (24.0f * 3));

					UIEntryIter++;
					if (UIEntryIter != UIEntry.end())
					{
						Slot6th->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 4));
						Slot6th->SetDotRenderer(101.0f, 23.0f + (24.0f * 4), *UIEntryIter);
						Slot6th->SetDataRenderers(*UIEntryIter,
							115.0f, 10.0f + (24.0f * 4),
							134.0f, 20.6f + (24.0f * 4),
							164.0f, 28.0f + (24.0f * 4),
							208.0f, 19.5f + (24.0f * 4),
							215.0f, 33.0f + (24.0f * 4),
							218.0f, 19.5f + (24.0f * 4));
					}
				}
			}
		}
	}
}

void UMyPokemonLevel::LevelEnd(ULevel* _NextLevel)
{

}

void UMyPokemonLevel::CheakEmptySlot(AMyPokemonSlot* _Slot, float _Slot_X, float _Slot_Y)
{
	if (true == _Slot->GetEmpty())
	{
		_Slot->IsEmpty(_Slot_X, _Slot_Y);
	}
	else
	{
		_Slot->SetSlotRenderer("MyPokemon_Slot.png", _Slot_X, _Slot_Y);
	}
}
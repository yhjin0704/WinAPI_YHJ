#include "Mom.h"
#include "Pokemon3rdGen_Core.h"
#include "PlayerHelper.h"

AMom::AMom()
{
}

AMom::~AMom()
{
}

void AMom::BeginPlay()
{
	ANpc::BeginPlay();

	CharacterRenderer->SetImage("Mom_Idle.png", 0);
	CharacterIfDownRenderer->SetImage("Mom_Idle.png", 0);
	
	CharacterRenderer->SetTransform({ { 0, 0 }, { 16.0f * FScaleMultiple, 32.0f * FScaleMultiple } });
	CharacterIfDownRenderer->SetTransform({ { 0, 0 },{ 16.0f * FScaleMultiple, 32.0f * FScaleMultiple } });

	PrevDirInput = EDirState::Left;
}

void AMom::Tick(float _DeltaTime)
{
	ANpc::Tick(_DeltaTime);

	DefaultEvent();

	SetDirImage(PrevDirInput, "Mom_Idle.png");

}

void AMom::DefaultEvent()
{
	std::vector<UCollision*> Result;
	if (true == DownCollision->CollisionCheck(ECollisionOrder::Player, Result)
		|| true == UpCollision->CollisionCheck(ECollisionOrder::Player, Result)
		|| true == LeftCollision->CollisionCheck(ECollisionOrder::Player, Result)
		|| true == RightCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		if (false == PlayerHelper::PlayerPause && false == PlayerHelper::IsUseMenu)
		{
			if (true == UEngineInput::IsDown('P'))
			{
				PlayerHelper::PlayerPause = true;
				SetColPlayerDir();

				std::list<PokemonInfo> Entry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
				std::list<PokemonInfo>::iterator EntryIter;
				for (EntryIter = Entry.begin(); EntryIter != Entry.end(); EntryIter++)
				{
					PokemonInfo HealPokemon = *EntryIter;
					HealPokemon.Hp = HealPokemon.MaxHp;
					*EntryIter = HealPokemon;
				}
				Pokemon3rdGen_Core::SetEntry(Entry);

				MsgBox->ActiveOn();
			}
		}
		else if (true == PlayerHelper::PlayerPause && false == PlayerHelper::IsUseMenu)
		{
			if (true == UEngineInput::IsDown('P') || true == UEngineInput::IsDown('L'))
			{
				PlayerHelper::PlayerPause = false;
				MsgBox->ActiveOff();
			}
		}
	}
}
#include "Npc.h"
#include "Pokemon3rdGen_Core.h"

ANpc::ANpc()
{
}

ANpc::~ANpc()
{
}

void ANpc::BeginPlay()
{
	ACharacter::BeginPlay();

	CharacterRenderer = CreateImageRenderer(ERenderOrder::NpcPosIsUp);
	CharacterIfDownRenderer = CreateImageRenderer(ERenderOrder::NpcPosIsDown);

	DownCollision = CreateCollision(ECollisionOrder::Npc);
	UpCollision = CreateCollision(ECollisionOrder::Npc);
	LeftCollision = CreateCollision(ECollisionOrder::Npc);
	RightCollision = CreateCollision(ECollisionOrder::Npc);

	BattlecheckDownCollision = CreateCollision(ECollisionOrder::BattleCheck);
	BattlecheckUpCollision = CreateCollision(ECollisionOrder::BattleCheck);
	BattlecheckLeftCollision = CreateCollision(ECollisionOrder::BattleCheck);
	BattlecheckRightCollision = CreateCollision(ECollisionOrder::BattleCheck);
}

void ANpc::Tick(float _DeltaTime)
{
	ACharacter::Tick(_DeltaTime);
}

void ANpc::PushBackEntry(int _DexNo, int _Level, std::string _Ability, float _Hp, float _Atk, float _Def, float _SAtk, float _SDef, float _Spd)
{
	if (6 > Entry.size())
	{
		PokemonInfo info = Pokemon3rdGen_Core::GetAllPokemonInfo()[_DexNo];
		info = SetIV(info, _Hp, _Atk, _Def, _SAtk, _SDef, _Spd);
		info.Ability = _Ability;
		info.PokemonInfo::SetLevel(_Level);
		if (0 == info.MeetLevel)
		{
			info.MeetLevel = _Level;
		}
		Entry.push_back(info);
	}
}

PokemonInfo ANpc::SetIV(PokemonInfo _Pokemon, float _Hp, float _Atk, float _Def, float _SAtk, float _SDef, float _Spd)
{
	_Pokemon.IVHp = _Hp;
	_Pokemon.IVAtk = _Atk;
	_Pokemon.IVDef = _Def;
	_Pokemon.IVSAtk = _SAtk;
	_Pokemon.IVSDef = _SDef;
	_Pokemon.IVSpd = _Spd;
	return _Pokemon;
}

void ANpc::SetActiveUpDownRenderer(FVector _PlayerPos)
{
	if (_PlayerPos.Y > GetActorLocation().Y)
	{
		CharacterRenderer->ActiveOn();
		CharacterIfDownRenderer->ActiveOff();
	}
	else
	{
		CharacterRenderer->ActiveOff();
		CharacterIfDownRenderer->ActiveOn();
	}
}
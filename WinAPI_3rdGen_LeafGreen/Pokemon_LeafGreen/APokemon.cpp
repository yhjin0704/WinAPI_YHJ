#include "APokemon.h"

APokemon::APokemon()
{
	int INature = UEngineRandom::MainRandom.RandomInt(0, 24);

	switch (INature)
	{
	case 0:
		Nature = ENature::Hardy;
		KNature = "����ϴ�";
		break;
	case 1:
		Nature = ENature::Lonely;
		KNature = "�ܷο��� Ÿ��";
		NAtk = 1.1f;
		NDef = 0.9f;
		break;
	case 2:
		Nature = ENature::Adamant;
		KNature = "����������";
		NAtk = 1.1f;
		NSAtk = 0.9f;
		break;
	case 3:
		Nature = ENature::Naughty;
		KNature = "�������̰���";
		NAtk = 1.1f;
		NSDef = 0.9f;
		break;
	case 4:
		Nature = ENature::Brave;
		KNature = "�밨��";
		NAtk = 1.1f;
		NSpd = 0.9f;
		break;
	case 5:
		Nature = ENature::Bold;
		KNature = "�����";
		NDef = 1.1f;
		NAtk = 0.9f;
		break;
	case 6:
		Nature = ENature::Docile;
		KNature = "�¼���";
		break;
	case 7:
		Nature = ENature::Impish;
		KNature = "�峭�ٷ��ⰰ��";
		NDef = 1.1f;
		NSAtk = 0.9f;
		break;
	case 8:
		Nature = ENature::Lax;
		KNature = "�Ͷ��Ÿ���";
		NDef = 1.1f;
		NSDef = 0.9f;
		break;
	case 9:
		Nature = ENature::Relaxed;
		KNature = "����������";
		NDef = 1.1f;
		NSpd = 0.9f;
		break;
	case 10:
		Nature = ENature::Modest;
		KNature = "���ɽ�����";
		NSAtk = 1.1f;
		NAtk = 0.9f;
		break;
	case 11:
		Nature = ENature::Mild;
		KNature = "������";
		NSAtk = 1.1f;
		NDef = 0.9f;
		break;
	case 12:
		Nature = ENature::Bashful;
		KNature = "�������� ����";
		break;
	case 13:
		Nature = ENature::Rash;
		KNature = "�����Ÿ���";
		NSAtk = 1.1f;
		NSDef = 0.9f;
		break;
	case 14:
		Nature = ENature::Quiet;
		KNature = "������";
		NSAtk = 1.1f;
		NSpd = 0.9f;
		break;
	case 15:
		Nature = ENature::Calm;
		KNature = "������";
		NSDef = 1.1f;
		NAtk = 0.9f;
		break;
	case 16:
		Nature = ENature::Gentle;
		KNature = "������";
		NSDef = 1.1f;
		NDef = 0.9f;
		break;
	case 17:
		Nature = ENature::Careful;
		KNature = "������";
		NSDef = 1.1f;
		NSAtk = 0.9f;
		break;
	case 18:
		Nature = ENature::Quirky;
		KNature = "����������";
		break;
	case 19:
		Nature = ENature::Sassy;
		KNature = "�ǹ���";
		NSDef = 1.1f;
		NSpd = 0.9f;
		break;
	case 20:
		Nature = ENature::Timid;
		KNature = "�����̰���";
		NSpd = 1.1f;
		NAtk = 0.9f;
		break;
	case 21:
		Nature = ENature::Hasty;
		KNature = "������";
		NSpd = 1.1f;
		NDef = 0.9f;
		break;
	case 22:
		Nature = ENature::Jolly;
		KNature = "�����";
		NSpd = 1.1f;
		NSAtk = 0.9f;
		break;
	case 23:
		Nature = ENature::Naive;
		KNature = "õ��������";
		NSpd = 1.1f;
		NSDef = 0.9f;
		break;
	case 24:
		Nature = ENature::Serious;
		KNature = "������";
		break;
	default:
		break;
	}

	IVHp = static_cast<float>(UEngineRandom::MainRandom.RandomInt(0, 31));
	IVAtk = static_cast<float>(UEngineRandom::MainRandom.RandomInt(0, 31));
	IVDef = static_cast<float>(UEngineRandom::MainRandom.RandomInt(0, 31));
	IVSAtk = static_cast<float>(UEngineRandom::MainRandom.RandomInt(0, 31));
	IVSDef = static_cast<float>(UEngineRandom::MainRandom.RandomInt(0, 31));
	IVSpd = static_cast<float>(UEngineRandom::MainRandom.RandomInt(0, 31));

	MaxHp = std::lround(std::floor((2 * BHp + IVHp + EVHp) * Level / 100 + Level + 10));
	Atk = std::lround(std::floor(std::floor((2 * BAtk + IVAtk + EVAtk) * Level / 100 + 5) * NAtk));
	Def = std::lround(std::floor(std::floor((2 * BDef + IVDef + EVDef) * Level / 100 + 5) * NDef));
	SAtk = std::lround(std::floor(std::floor((2 * BSAtk + IVSAtk + EVSAtk) * Level / 100 + 5) * NSAtk));
	SDef = std::lround(std::floor(std::floor((2 * BSDef + IVSDef + EVSDef) * Level / 100 + 5) * NSDef));
	Spd = std::lround(std::floor(std::floor((2 * BSpd + IVSpd + EVSpd) * Level / 100 + 5) * NSpd));
}

APokemon::~APokemon()
{
}

void APokemon::BeginPlay()
{
	AActor::BeginPlay();
}

void APokemon::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
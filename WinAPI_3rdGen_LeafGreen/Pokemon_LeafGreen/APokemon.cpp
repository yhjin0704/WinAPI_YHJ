#include "APokemon.h"

APokemon::APokemon()
{
	int INature = UEngineRandom::MainRandom.RandomInt(0, 24);

	switch (INature)
	{
	case 0:
		Nature = ENature::Hardy;
		KNature = "노력하는";
		break;
	case 1:
		Nature = ENature::Lonely;
		KNature = "외로움을 타는";
		NAtk = 1.1f;
		NDef = 0.9f;
		break;
	case 2:
		Nature = ENature::Adamant;
		KNature = "고집스러운";
		NAtk = 1.1f;
		NSAtk = 0.9f;
		break;
	case 3:
		Nature = ENature::Naughty;
		KNature = "개구쟁이같은";
		NAtk = 1.1f;
		NSDef = 0.9f;
		break;
	case 4:
		Nature = ENature::Brave;
		KNature = "용감한";
		NAtk = 1.1f;
		NSpd = 0.9f;
		break;
	case 5:
		Nature = ENature::Bold;
		KNature = "대담한";
		NDef = 1.1f;
		NAtk = 0.9f;
		break;
	case 6:
		Nature = ENature::Docile;
		KNature = "온순한";
		break;
	case 7:
		Nature = ENature::Impish;
		KNature = "장난꾸러기같은";
		NDef = 1.1f;
		NSAtk = 0.9f;
		break;
	case 8:
		Nature = ENature::Lax;
		KNature = "촐랑거리는";
		NDef = 1.1f;
		NSDef = 0.9f;
		break;
	case 9:
		Nature = ENature::Relaxed;
		KNature = "무사태평한";
		NDef = 1.1f;
		NSpd = 0.9f;
		break;
	case 10:
		Nature = ENature::Modest;
		KNature = "조심스러운";
		NSAtk = 1.1f;
		NAtk = 0.9f;
		break;
	case 11:
		Nature = ENature::Mild;
		KNature = "의젓한";
		NSAtk = 1.1f;
		NDef = 0.9f;
		break;
	case 12:
		Nature = ENature::Bashful;
		KNature = "수줍음이 많은";
		break;
	case 13:
		Nature = ENature::Rash;
		KNature = "덜렁거리는";
		NSAtk = 1.1f;
		NSDef = 0.9f;
		break;
	case 14:
		Nature = ENature::Quiet;
		KNature = "냉정한";
		NSAtk = 1.1f;
		NSpd = 0.9f;
		break;
	case 15:
		Nature = ENature::Calm;
		KNature = "차분한";
		NSDef = 1.1f;
		NAtk = 0.9f;
		break;
	case 16:
		Nature = ENature::Gentle;
		KNature = "얌전한";
		NSDef = 1.1f;
		NDef = 0.9f;
		break;
	case 17:
		Nature = ENature::Careful;
		KNature = "신중한";
		NSDef = 1.1f;
		NSAtk = 0.9f;
		break;
	case 18:
		Nature = ENature::Quirky;
		KNature = "변덕스러운";
		break;
	case 19:
		Nature = ENature::Sassy;
		KNature = "건방진";
		NSDef = 1.1f;
		NSpd = 0.9f;
		break;
	case 20:
		Nature = ENature::Timid;
		KNature = "겁쟁이같은";
		NSpd = 1.1f;
		NAtk = 0.9f;
		break;
	case 21:
		Nature = ENature::Hasty;
		KNature = "성급한";
		NSpd = 1.1f;
		NDef = 0.9f;
		break;
	case 22:
		Nature = ENature::Jolly;
		KNature = "명랑한";
		NSpd = 1.1f;
		NSAtk = 0.9f;
		break;
	case 23:
		Nature = ENature::Naive;
		KNature = "천진난만한";
		NSpd = 1.1f;
		NSDef = 0.9f;
		break;
	case 24:
		Nature = ENature::Serious;
		KNature = "성실한";
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
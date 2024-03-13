#include "Pokemon3rdGen_Core.h"
#include "TitleLevel1.h"
#include "TitleLevel2.h"
#include "TitleLevel3.h"
#include "TitleLevel4.h"
#include "BattleLevel.h"
#include "WestFieldLevel.h"
#include "PlayerHome1FLevel.h"
#include "PlayerHome2FLevel.h"
#include "RivalHomeLevel.h"
#include "OaksLabLevel.h"
#include "MyPokemonLevel.h"
#include "MyBagLevel.h"
#include "MyTrainerCardLevel.h"

//std::map<int, PokemonInfo> Pokemon3rdGen_Core::AllPokemonInfo;

Pokemon3rdGen_Core::Pokemon3rdGen_Core()
	: UEngineCore()
{
}

Pokemon3rdGen_Core::~Pokemon3rdGen_Core()
{
}

// 게임시작
void Pokemon3rdGen_Core::BeginPlay()
{
	MainWindow.SetWindowScale({ FScreen_X, FScreen_Y });
	MainWindow.SetClearColor(Color8Bit::BlackA);
	SetFrame(60);

	AddFontResourceExA("PokemonGSK2.ttf", FR_PRIVATE, 0);

	{
		FieldPath.MoveParent();
		FieldPath.Move("Resources");

		std::list<UEngineFile> NewSoundsList = FieldPath.AllFile({ ".wav", ".mp3" }, true);

		for (UEngineFile& File : NewSoundsList)
		{
			UEngineSound::Load(File.GetFullPath());
		}
	}

	{
		FieldPath.Move("Field");

		std::list<UEngineFile> AllFieldGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllFieldGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("UI");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("Pokemon");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}

		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Front_Back_1.png", 12, 17);
		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Front_Back_2.png", 12, 17);
		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Front_Back_3.png", 12, 17);
		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Dot.png", 20, 16);
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("Battle");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		PokemonInfo Info;
		Info.DexNo = 1;
		Info.Tribe = "이상해씨";
		Info.Type1 = EType::풀;
		Info.Type2 = EType::독;
		Info.BHp = 45.0f;
		Info.BAtk = 49.0f;
		Info.BDef = 49.0f;
		Info.BSAtk = 65.0f;
		Info.BSDef = 65.0f;
		Info.BSpd = 45.0f;
		Info.Ability = "심록";
		Info.Genderper = 875;
		Info.EvolveLevel = 16;
		Info.NextEvolveDexNo = 2;
		Info.CalImageNo(Info.DexNo);

		AllPokemonInfo[Info.DexNo] = Info;
	}

	{
		PokemonInfo Info;
		Info.DexNo = 2;
		Info.Tribe = "이상해풀";
		Info.Type1 = EType::풀;
		Info.Type2 = EType::독;
		Info.BHp = 60.0f;
		Info.BAtk = 62.0f;
		Info.BDef = 63.0f;
		Info.BSAtk = 80.0f;
		Info.BSDef = 80.0f;
		Info.BSpd = 60.0f;
		Info.Ability = "심록";
		Info.Genderper = 875;
		Info.EvolveLevel = 32;
		Info.NextEvolveDexNo = 3;
		Info.CalImageNo(Info.DexNo);

		AllPokemonInfo[Info.DexNo] = Info;
	}

	{
		PokemonInfo Info;
		Info.DexNo = 3;
		Info.Tribe = "이상해꽃";
		Info.Type1 = EType::풀;
		Info.Type2 = EType::독;
		Info.BHp = 80.0f;
		Info.BAtk = 82.0f;
		Info.BDef = 83.0f;
		Info.BSAtk = 100.0f;
		Info.BSDef = 100.0f;
		Info.BSpd = 80.0f;
		Info.Ability = "심록";
		Info.Genderper = 875;
		Info.EvolveLevel = 101;
		Info.NextEvolveDexNo = 0;
		Info.CalImageNo(Info.DexNo);

		AllPokemonInfo[Info.DexNo] = Info;
	}

	{
		PokemonInfo Info;
		Info.DexNo = 4;
		Info.Tribe = "파이리";
		Info.Type1 = EType::불꽃;
		Info.BHp = 39.0f;
		Info.BAtk = 52.0f;
		Info.BDef = 43.0f;
		Info.BSAtk = 60.0f;
		Info.BSDef = 50.0f;
		Info.BSpd = 65.0f;
		Info.Ability = "맹화";
		Info.Genderper = 875;
		Info.EvolveLevel = 16;
		Info.NextEvolveDexNo = 5;
		Info.CalImageNo(Info.DexNo);

		AllPokemonInfo[Info.DexNo] = Info;
	}

	{
		PokemonInfo Info;
		Info.DexNo = 7;
		Info.Tribe = "꼬부기";
		Info.Type1 = EType::물;
		Info.BHp = 44.0f;
		Info.BAtk = 48.0f;
		Info.BDef = 65.0f;
		Info.BSAtk = 50.0f;
		Info.BSDef = 64.0f;
		Info.BSpd = 43.0f;
		Info.Ability = "급류";
		Info.Genderper = 875;
		Info.EvolveLevel = 16;
		Info.NextEvolveDexNo = 8;
		Info.CalImageNo(Info.DexNo);

		AllPokemonInfo[Info.DexNo] = Info;
	}

	{
		CreateLevel<UTitleLevel1>("TitleLevel1");
		CreateLevel<UTitleLevel2>("TitleLevel2");
		CreateLevel<UTitleLevel3>("TitleLevel3");
		CreateLevel<UTitleLevel4>("TitleLevel4");

		CreateLevel<UBattleLevel>("BattleLevel");

		CreateLevel<UWestFieldLevel>("WestFieldLevel");
		CreateLevel<UPlayerHome1FLevel>("PlayerHome1FLevel");
		CreateLevel<UPlayerHome2FLevel>("PlayerHome2FLevel");
		CreateLevel<URivalHomeLevel>("RivalHomeLevel");
		CreateLevel<UOaksLabLevel>("OaksLabLevel");

		CreateLevel<UMyPokemonLevel>("MyPokemonLevel");
		CreateLevel<UMyBagLevel>("MyBagLevel");
		CreateLevel<UMyTrainerCardLevel>("MyTrainerCardLevel");
	}

	ChangeLevel("OaksLabLevel");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('9'))
	{
		GEngine->EngineDebugSwitch();
	}
}

void Pokemon3rdGen_Core::End()
{
}

void Pokemon3rdGen_Core::AddEntry(int _DexNo, int _Level)
{
	PokemonInfo info = AllPokemonInfo[_DexNo];
	info.PokemonInfo::CalStatus(_Level);
	if (0 == info.MeetLevel)
	{
		info.MeetLevel = _Level;
	}
	Entry.push_back(info);
	PokemonInfo Test = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry().front();
}
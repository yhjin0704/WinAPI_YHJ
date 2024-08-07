#include "Pokemon3rdGen_Core.h"
#include "TitleLevel1.h"
#include "TitleLevel2.h"
#include "TitleLevel3.h"
#include "TitleLevel4.h"
#include "BattleLevel.h"
#include "EvolveLevel.h"
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

	//AddFontResourceExA("PokemonGSK2.ttf", FR_PRIVATE, 0);

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

	// 기술 Info
	{
		// 노말
		// 분노
		{
			MoveInfo Info;
			Info.Name = "분노";
			Info.Type = EType::노말;
			Info.Caterory = EPSMove::물리;
			Info.Power = 20;
			Info.Acc = 100;
			Info.MaxPP = 20;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 몸통박치기
		{
			MoveInfo Info;
			Info.Name = "몸통박치기";
			Info.Type = EType::노말;
			Info.Caterory = EPSMove::물리;
			Info.Power = 35;
			Info.Acc = 95;
			Info.MaxPP = 35;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 할퀴기
		{
			MoveInfo Info;
			Info.Name = "할퀴기";
			Info.Type = EType::노말;
			Info.Caterory = EPSMove::물리;
			Info.Power = 40;
			Info.Acc = 100;
			Info.MaxPP = 35;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 전광석화
		{
			MoveInfo Info;
			Info.Name = "전광석화";
			Info.Type = EType::노말;
			Info.Caterory = EPSMove::물리;
			Info.Power = 40;
			Info.Acc = 100;
			Info.MaxPP = 30;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 필살앞니
		{
			MoveInfo Info;
			Info.Name = "전광석화";
			Info.Type = EType::노말;
			Info.Caterory = EPSMove::물리;
			Info.Power = 80;
			Info.Acc = 90;
			Info.MaxPP = 15;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 분노의앞니
		{
			MoveInfo Info;
			Info.Name = "분노의앞니";
			Info.Type = EType::노말;
			Info.Caterory = EPSMove::물리;
			Info.Power = 120;
			Info.Acc = 90;
			Info.MaxPP = 15;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 불꽃
		// 불꽃세례
		{
			MoveInfo Info;
			Info.Name = "불꽃세례";
			Info.Type = EType::불꽃;
			Info.Caterory = EPSMove::특수;
			Info.Power = 40;
			Info.Acc = 100;
			Info.MaxPP = 25;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 풀
		// 덩굴채찍
		{
			MoveInfo Info;
			Info.Name = "덩굴채찍";
			Info.Type = EType::풀;
			Info.Caterory = EPSMove::물리;
			Info.Power = 35;
			Info.Acc = 100;
			Info.MaxPP = 10;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 잎날가르기
		{
			MoveInfo Info;
			Info.Name = "잎날가르기";
			Info.Type = EType::풀;
			Info.Caterory = EPSMove::물리;
			Info.Power = 55;
			Info.Acc = 95;
			Info.MaxPP = 25;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 솔라빔
		{
			MoveInfo Info;
			Info.Name = "솔라빔";
			Info.Type = EType::풀;
			Info.Caterory = EPSMove::특수;
			Info.Power = 120;
			Info.Acc = 100;
			Info.MaxPP = 10;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 비행
		// 날개치기
		{
			MoveInfo Info;
			Info.Name = "날개치기";
			Info.Type = EType::비행;
			Info.Caterory = EPSMove::물리;
			Info.Power = 60;
			Info.Acc = 100;
			Info.MaxPP = 35;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		// 바람일으키기
		{
			MoveInfo Info;
			Info.Name = "바람일으키기";
			Info.Type = EType::비행;
			Info.Caterory = EPSMove::특수;
			Info.Power = 40;
			Info.Acc = 100;
			Info.MaxPP = 35;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}

		//악
		//따라가때리기
		{
			MoveInfo Info;
			Info.Name = "따라가때리기";
			Info.Type = EType::악;
			Info.Caterory = EPSMove::물리;
			Info.Power = 40;
			Info.Acc = 100;
			Info.MaxPP = 20;
			Info.PP = Info.MaxPP;

			AllMovesInfo[Info.Name] = Info;
		}
	}

	// 포켓몬 Info
	{
		// 이상해씨
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
			Info.Ability1 = "심록";
			Info.Genderper = 875;
			Info.EvolveLevel = 16;
			Info.NextEvolveDexNo = 2;
			Info.CalImageNo(Info.DexNo);

			Info.LPossessMoves.push_back(AllMovesInfo["몸통박치기"]);

			Info.MLevelUpMoves[10] = AllMovesInfo["덩굴채찍"];
			Info.MLevelUpMoves[20] = AllMovesInfo["잎날가르기"];
			Info.MLevelUpMoves[46] = AllMovesInfo["솔라빔"];

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 이상해풀
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
			Info.Ability1 = "심록";
			Info.Genderper = 875;
			Info.EvolveLevel = 32;
			Info.NextEvolveDexNo = 3;
			Info.CalImageNo(Info.DexNo);

			Info.LPossessMoves.push_back(AllMovesInfo["몸통박치기"]);

			Info.MLevelUpMoves[10] = AllMovesInfo["덩굴채찍"];
			Info.MLevelUpMoves[22] = AllMovesInfo["잎날가르기"];
			Info.MLevelUpMoves[56] = AllMovesInfo["솔라빔"];

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 이상해꽃
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
			Info.Ability1 = "심록";
			Info.Genderper = 875;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			Info.LPossessMoves.push_back(AllMovesInfo["몸통박치기"]);
			Info.LPossessMoves.push_back(AllMovesInfo["덩굴채찍"]);

			Info.MLevelUpMoves[10] = AllMovesInfo["덩굴채찍"];
			Info.MLevelUpMoves[22] = AllMovesInfo["잎날가르기"];
			Info.MLevelUpMoves[65] = AllMovesInfo["솔라빔"];

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 파이리
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
			Info.Ability1 = "맹화";
			Info.Genderper = 875;
			Info.EvolveLevel = 16;
			Info.NextEvolveDexNo = 5;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 리자드
		{
			PokemonInfo Info;
			Info.DexNo = 5;
			Info.Tribe = "리자드";
			Info.Type1 = EType::불꽃;
			Info.BHp = 58.0f;
			Info.BAtk = 64.0f;
			Info.BDef = 58.0f;
			Info.BSAtk = 80.0f;
			Info.BSDef = 65.0f;
			Info.BSpd = 80.0f;
			Info.Ability1 = "맹화";
			Info.Genderper = 875;
			Info.EvolveLevel = 36;
			Info.NextEvolveDexNo = 6;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 리자몽
		{
			PokemonInfo Info;
			Info.DexNo = 6;
			Info.Tribe = "리자몽";
			Info.Type1 = EType::불꽃;
			Info.Type2 = EType::비행;
			Info.BHp = 78.0f;
			Info.BAtk = 84.0f;
			Info.BDef = 78.0f;
			Info.BSAtk = 109.0f;
			Info.BSDef = 85.0f;
			Info.BSpd = 100.0f;
			Info.Ability1 = "맹화";
			Info.Genderper = 875;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 꼬부기
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
			Info.Ability1 = "급류";
			Info.Genderper = 875;
			Info.EvolveLevel = 16;
			Info.NextEvolveDexNo = 8;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 어니부기
		{
			PokemonInfo Info;
			Info.DexNo = 8;
			Info.Tribe = "어니부기";
			Info.Type1 = EType::물;
			Info.BHp = 59.0f;
			Info.BAtk = 63.0f;
			Info.BDef = 80.0f;
			Info.BSAtk = 65.0f;
			Info.BSDef = 80.0f;
			Info.BSpd = 58.0f;
			Info.Ability1 = "급류";
			Info.Genderper = 875;
			Info.EvolveLevel = 36;
			Info.NextEvolveDexNo = 9;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 거북왕
		{
			PokemonInfo Info;
			Info.DexNo = 9;
			Info.Tribe = "거북왕";
			Info.Type1 = EType::물;
			Info.BHp = 79.0f;
			Info.BAtk = 83.0f;
			Info.BDef = 100.0f;
			Info.BSAtk = 85.0f;
			Info.BSDef = 105.0f;
			Info.BSpd = 78.0f;
			Info.Ability1 = "급류";
			Info.Genderper = 875;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 구구
		{
			PokemonInfo Info;
			Info.DexNo = 16;
			Info.Tribe = "구구";
			Info.Type1 = EType::노말;
			Info.Type2 = EType::비행;
			Info.BHp = 40.0f;
			Info.BAtk = 45.0f;
			Info.BDef = 40.0f;
			Info.BSAtk = 35.0f;
			Info.BSDef = 35.0f;
			Info.BSpd = 56.0f;
			Info.Ability1 = "날카로운 눈";
			Info.Genderper = 500;
			Info.EvolveLevel = 18;
			Info.NextEvolveDexNo = 17;
			Info.CalImageNo(Info.DexNo);

			Info.LPossessMoves.push_back(AllMovesInfo["몸통박치기"]);

			Info.MLevelUpMoves[9] = AllMovesInfo["바람일으키기"];
			Info.MLevelUpMoves[13] = AllMovesInfo["전광석화"];
			Info.MLevelUpMoves[25] = AllMovesInfo["날개치기"];

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 피죤
		{
			PokemonInfo Info;
			Info.DexNo = 17;
			Info.Tribe = "피죤";
			Info.Type1 = EType::노말;
			Info.Type2 = EType::비행;
			Info.BHp = 63.0f;
			Info.BAtk = 60.0f;
			Info.BDef = 55.0f;
			Info.BSAtk = 50.0f;
			Info.BSDef = 50.0f;
			Info.BSpd = 71.0f;
			Info.Ability1 = "날카로운 눈";
			Info.Genderper = 500;
			Info.EvolveLevel = 36;
			Info.NextEvolveDexNo = 18;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 피죤투
		{
			PokemonInfo Info;
			Info.DexNo = 18;
			Info.Tribe = "피죤투";
			Info.Type1 = EType::노말;
			Info.Type2 = EType::비행;
			Info.BHp = 83.0f;
			Info.BAtk = 80.0f;
			Info.BDef = 75.0f;
			Info.BSAtk = 70.0f;
			Info.BSDef = 70.0f;
			Info.BSpd = 91.0f;
			Info.Ability1 = "날카로운 눈";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 꼬렛
		{
			PokemonInfo Info;
			Info.DexNo = 19;
			Info.Tribe = "꼬렛";
			Info.Type1 = EType::노말;
			Info.BHp = 30.0f;
			Info.BAtk = 56.0f;
			Info.BDef = 35.0f;
			Info.BSAtk = 25.0f;
			Info.BSDef = 35.0f;
			Info.BSpd = 72.0f;
			Info.Ability1 = "도주";
			Info.Ability2 = "근성";
			Info.Genderper = 500;
			Info.EvolveLevel = 20;
			Info.NextEvolveDexNo = 20;
			Info.CalImageNo(Info.DexNo);

			Info.LPossessMoves.push_back(AllMovesInfo["몸통박치기"]);

			Info.MLevelUpMoves[7] = AllMovesInfo["전광석화"];
			Info.MLevelUpMoves[13] = AllMovesInfo["필살앞니"];
			Info.MLevelUpMoves[27] = AllMovesInfo["따라가때리기"];
			Info.MLevelUpMoves[34] = AllMovesInfo["분노의앞니"];

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 레트라
		{
			PokemonInfo Info;
			Info.DexNo = 20;
			Info.Tribe = "레트라";
			Info.Type1 = EType::노말;
			Info.BHp = 55.0f;
			Info.BAtk = 81.0f;
			Info.BDef = 60.0f;
			Info.BSAtk = 50.0f;
			Info.BSDef = 70.0f;
			Info.BSpd = 97.0f;
			Info.Ability1 = "도주";
			Info.Ability2 = "근성";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 꼬마돌
		{
			PokemonInfo Info;
			Info.DexNo = 74;
			Info.Tribe = "꼬마돌";
			Info.Type1 = EType::바위;
			Info.Type1 = EType::땅;
			Info.BHp = 40.0f;
			Info.BAtk = 80.0f;
			Info.BDef = 100.0f;
			Info.BSAtk = 30.0f;
			Info.BSDef = 30.0f;
			Info.BSpd = 20.0f;
			Info.Ability1 = "돌머리";
			Info.Ability2 = "옹골참";
			Info.Genderper = 500;
			Info.EvolveLevel = 25;
			Info.NextEvolveDexNo = 75;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 데구리
		{
			PokemonInfo Info;
			Info.DexNo = 75;
			Info.Tribe = "데구리";
			Info.Type1 = EType::바위;
			Info.Type1 = EType::땅;
			Info.BHp = 55.0f;
			Info.BAtk = 95.0f;
			Info.BDef = 115.0f;
			Info.BSAtk = 45.0f;
			Info.BSDef = 45.0f;
			Info.BSpd = 35.0f;
			Info.Ability1 = "돌머리";
			Info.Ability2 = "옹골참";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 76;
			Info.UseItemEvolve = true;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 딱구리
		{
			PokemonInfo Info;
			Info.DexNo = 76;
			Info.Tribe = "딱구리";
			Info.Type1 = EType::바위;
			Info.Type1 = EType::땅;
			Info.BHp = 80.0f;
			Info.BAtk = 110.0f;
			Info.BDef = 130.0f;
			Info.BSAtk = 55.0f;
			Info.BSDef = 65.0f;
			Info.BSpd = 45.0f;
			Info.Ability1 = "돌머리";
			Info.Ability2 = "옹골참";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		// 롱스톤
		{
			PokemonInfo Info;
			Info.DexNo = 95;
			Info.Tribe = "롱스톤";
			Info.Type1 = EType::바위;
			Info.Type1 = EType::땅;
			Info.BHp = 35.0f;
			Info.BAtk = 45.0f;
			Info.BDef = 160.0f;
			Info.BSAtk = 30.0f;
			Info.BSDef = 45.0f;
			Info.BSpd = 70.0f;
			Info.Ability1 = "돌머리";
			Info.Ability2 = "옹골참";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 208;
			Info.UseItemEvolve = true;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}
	}

	{
		CreateLevel<UTitleLevel1>("TitleLevel1");
		CreateLevel<UTitleLevel2>("TitleLevel2");
		CreateLevel<UTitleLevel3>("TitleLevel3");
		CreateLevel<UTitleLevel4>("TitleLevel4");

		CreateLevel<UBattleLevel>("BattleLevel");
		CreateLevel<UEvolveLevel>("EvolveLevel");

		CreateLevel<UWestFieldLevel>("WestFieldLevel");
		CreateLevel<UPlayerHome1FLevel>("PlayerHome1FLevel");
		CreateLevel<UPlayerHome2FLevel>("PlayerHome2FLevel");
		CreateLevel<URivalHomeLevel>("RivalHomeLevel");
		CreateLevel<UOaksLabLevel>("OaksLabLevel");

		CreateLevel<UMyPokemonLevel>("MyPokemonLevel");
		CreateLevel<UMyBagLevel>("MyBagLevel");
		CreateLevel<UMyTrainerCardLevel>("MyTrainerCardLevel");
	}

	ChangeLevel("TitleLevel1");
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
	if (6 > Entry.size())
	{
		PokemonInfo info = AllPokemonInfo[_DexNo];
		info.PokemonInfo::CalStatus(_Level);
		info.PlayerPokemon = true;
		if (0 == info.MeetLevel)
		{
			info.MeetLevel = _Level;
		}
		Entry.push_back(info);
	}
	else
	{
		PokemonInfo info = AllPokemonInfo[_DexNo];
		info.PokemonInfo::CalStatus(_Level);
		info.PlayerPokemon = true;
		if (0 == info.MeetLevel)
		{
			info.MeetLevel = _Level;
		}
		Box.push_back(info);
	}
}

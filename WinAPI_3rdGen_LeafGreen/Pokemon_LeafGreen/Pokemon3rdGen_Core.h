#pragma once
#include <EngineCore\EngineCore.h>
#include <EngineBase\EngineDirectory.h>
#include "Global.h"
#include "Player.h"
#include "TitleLevel1.h"
#include "TitleLevel2.h"
#include "TitleLevel3.h"
#include "TitleLevel4.h"
#include "WestFieldLevel.h"
#include "PlayerHome1FLevel.h"
#include "PlayerHome2FLevel.h"
#include "RivalHomeLevel.h"
#include "OaksLabLevel.h"
#include "MyPokemonLevel.h"
#include "MyBagLevel.h"
#include "MyTrainerCardLevel.h"
#include <EnginePlatform\EngineSound.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>
#include "PokemonInfo.h"

class Pokemon3rdGen_Core : public UEngineCore
{
public:
	// constrcuter destructer
	Pokemon3rdGen_Core();
	~Pokemon3rdGen_Core();

	// delete Function
	Pokemon3rdGen_Core(const Pokemon3rdGen_Core& _Other) = delete;
	Pokemon3rdGen_Core(Pokemon3rdGen_Core&& _Other) noexcept = delete;
	Pokemon3rdGen_Core& operator=(const Pokemon3rdGen_Core& _Other) = delete;
	Pokemon3rdGen_Core& operator=(Pokemon3rdGen_Core&& _Other) noexcept = delete;

	static std::map<int, PokemonInfo> GetAllPokemonInfo()
	{
		return dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->AllPokemonInfo;
	}

	/*static PokemonInfo GetCalStatusPoketMon(int _DexNo)
	{
		return AllPokemonInfo[_DexNo]
	}*/
	
	static std::list<PokemonInfo> GetEntry()
	{
		return dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->Entry;
	}

	void AddEntry(int _DexNo, int _Level);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void End() override;

	UEngineDirectory FieldPath;

private:
	// �ʱ�����
	// ���ӳ����� ���ü� �ִµ�.
	std::map<int, PokemonInfo> AllPokemonInfo;

	// ���� ��� �ִ� ���ϸ�
	std::list<PokemonInfo> Entry;

	std::list<PokemonInfo> Box;
};


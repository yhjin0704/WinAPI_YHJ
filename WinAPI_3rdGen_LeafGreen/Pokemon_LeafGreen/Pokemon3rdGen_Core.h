#pragma once
#include <EngineCore\EngineCore.h>
#include <EngineBase\EngineDirectory.h>
#include "Global.h"
#include "Player.h"
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

	static void SetEntry(std::list<PokemonInfo> _Entry)
	{
		dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->Entry = _Entry;
	}

	void AddEntry(int _DexNo, int _Level);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void End() override;

	UEngineDirectory FieldPath;

private:
	// 초기정보
	// 게임내에서 나올수 있는데.
	std::map<int, PokemonInfo> AllPokemonInfo;

	// 내가 들고 있는 포켓몬
	std::list<PokemonInfo> Entry;

	std::list<PokemonInfo> Box;
};


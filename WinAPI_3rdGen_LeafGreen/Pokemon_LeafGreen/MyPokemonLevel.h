#pragma once
#include "MenuUILevel.h"
#include "MyPokemonBackGround.h"
#include "MyPokemonSlot.h"
#include "MyPokemonCancle.h"
#include <EngineBase/EngineString.h>
#include <EngineCore\EngineCore.h>

class UMyPokemonLevel : public UMenuUILevel
{
public:
	// constrcuter destructer
	UMyPokemonLevel();
	~UMyPokemonLevel();

	// delete Function
	UMyPokemonLevel(const UMyPokemonLevel& _Other) = delete;
	UMyPokemonLevel(UMyPokemonLevel&& _Other) noexcept = delete;
	UMyPokemonLevel& operator=(const UMyPokemonLevel& _Other) = delete;
	UMyPokemonLevel& operator=(UMyPokemonLevel&& _Other) noexcept = delete;

	std::string GetPrevLevelName()
	{
		return PrevLevelName;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	int SelectSlot = 0;

	AMyPokemonBackGround* BackGround;
	AMyPokemonSlot* Slot1st;
	AMyPokemonSlot* Slot2nd;
	AMyPokemonSlot* Slot3rd;
	AMyPokemonSlot* Slot4th;
	AMyPokemonSlot* Slot5th;
	AMyPokemonSlot* Slot6th;

	//AMyPokemonCancle* Cancle;

	std::string PrevLevelName = "";

	void CheakEmptySlot(AMyPokemonSlot* _Slot, float _Slot_X, float _Slot_Y);
};


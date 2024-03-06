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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void End() override;

	UEngineDirectory FieldPath;

private:

};


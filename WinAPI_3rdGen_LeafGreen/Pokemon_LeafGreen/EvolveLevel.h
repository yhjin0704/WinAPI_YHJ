#pragma once
#include <EngineCore\Level.h>

class UEvolveLevel : public ULevel
{
public:
	// constrcuter destructer
	UEvolveLevel();
	~UEvolveLevel();

	// delete Function
	UEvolveLevel(const UEvolveLevel& _Other) = delete;
	UEvolveLevel(UEvolveLevel&& _Other) noexcept = delete;
	UEvolveLevel& operator=(const UEvolveLevel& _Other) = delete;
	UEvolveLevel& operator=(UEvolveLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:

};


#pragma once
#include "MenuUILevel.h"

class UMyIvenLevel : public UMenuUILevel
{
public:
	// constrcuter destructer
	UMyIvenLevel();
	~UMyIvenLevel();

	// delete Function
	UMyIvenLevel(const UMyIvenLevel& _Other) = delete;
	UMyIvenLevel(UMyIvenLevel&& _Other) noexcept = delete;
	UMyIvenLevel& operator=(const UMyIvenLevel& _Other) = delete;
	UMyIvenLevel& operator=(UMyIvenLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};


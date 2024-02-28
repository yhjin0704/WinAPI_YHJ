#pragma once
#include "MenuUILevel.h"

class UMyTrainerCardLevel : public UMenuUILevel
{
public:
	// constrcuter destructer
	UMyTrainerCardLevel();
	~UMyTrainerCardLevel();

	// delete Function
	UMyTrainerCardLevel(const UMyTrainerCardLevel& _Other) = delete;
	UMyTrainerCardLevel(UMyTrainerCardLevel&& _Other) noexcept = delete;
	UMyTrainerCardLevel& operator=(const UMyTrainerCardLevel& _Other) = delete;
	UMyTrainerCardLevel& operator=(UMyTrainerCardLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};


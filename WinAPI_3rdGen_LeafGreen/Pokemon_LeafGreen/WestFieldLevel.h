#pragma once
#include "FieldLevel.h"

class UWestFieldLevel : public UFieldLevel
{
public:
	// constrcuter destructer
	UWestFieldLevel();
	~UWestFieldLevel();

	// delete Function
	UWestFieldLevel(const UWestFieldLevel& _Other) = delete;
	UWestFieldLevel(UWestFieldLevel&& _Other) noexcept = delete;
	UWestFieldLevel& operator=(const UWestFieldLevel& _Other) = delete;
	UWestFieldLevel& operator=(UWestFieldLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

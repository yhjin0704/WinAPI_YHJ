#pragma once
#include <EngineCore\Actor.h>
#include "Global.h"

class AMenu : public AActor
{
public:
	// constrcuter destructer
	AMenu();
	~AMenu();

	// delete Function
	AMenu(const AMenu& _Other) = delete;
	AMenu(AMenu&& _Other) noexcept = delete;
	AMenu& operator=(const AMenu& _Other) = delete;
	AMenu& operator=(AMenu&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};


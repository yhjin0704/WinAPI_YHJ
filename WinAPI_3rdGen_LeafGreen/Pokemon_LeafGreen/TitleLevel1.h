#pragma once
#include <EngineCore\Level.h>

class UTitleLevel1 : public ULevel
{
public:
	// constrcuter destructer
	UTitleLevel1();
	~UTitleLevel1();

	// delete Function
	UTitleLevel1(const UTitleLevel1& _Other) = delete;
	UTitleLevel1(UTitleLevel1&& _Other) noexcept = delete;
	UTitleLevel1& operator=(const UTitleLevel1& _Other) = delete;
	UTitleLevel1& operator=(UTitleLevel1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;

private:

};


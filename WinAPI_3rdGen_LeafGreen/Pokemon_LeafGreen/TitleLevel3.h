#pragma once
#include <EngineCore\Level.h>

class UTitleLevel3 : public ULevel
{
public:
	// constrcuter destructer
	UTitleLevel3();
	~UTitleLevel3();

	// delete Function
	UTitleLevel3(const UTitleLevel3& _Other) = delete;
	UTitleLevel3(UTitleLevel3&& _Other) noexcept = delete;
	UTitleLevel3& operator=(const UTitleLevel3& _Other) = delete;
	UTitleLevel3& operator=(UTitleLevel3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;

private:

};


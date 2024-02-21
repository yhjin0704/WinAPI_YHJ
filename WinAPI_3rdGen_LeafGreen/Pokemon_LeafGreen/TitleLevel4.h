#pragma once
#include <EngineCore\Level.h>

class UTitleLevel4 : public ULevel
{
public:
	// constrcuter destructer
	UTitleLevel4();
	~UTitleLevel4();

	// delete Function
	UTitleLevel4(const UTitleLevel4& _Other) = delete;
	UTitleLevel4(UTitleLevel4&& _Other) noexcept = delete;
	UTitleLevel4& operator=(const UTitleLevel4& _Other) = delete;
	UTitleLevel4& operator=(UTitleLevel4&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;

private:

};


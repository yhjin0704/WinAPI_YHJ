#pragma once
#include "BackGround.h"

class AMyIvenBackGround : public ABackGround
{
public:
	// constrcuter destructer
	AMyIvenBackGround();
	~AMyIvenBackGround();

	// delete Function
	AMyIvenBackGround(const AMyIvenBackGround& _Other) = delete;
	AMyIvenBackGround(AMyIvenBackGround&& _Other) noexcept = delete;
	AMyIvenBackGround& operator=(const AMyIvenBackGround& _Other) = delete;
	AMyIvenBackGround& operator=(AMyIvenBackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};


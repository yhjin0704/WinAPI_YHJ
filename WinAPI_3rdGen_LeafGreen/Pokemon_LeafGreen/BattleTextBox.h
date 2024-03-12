#pragma once
#include <EngineCore\Actor.h>

class ABattleTextBox : public AActor
{
public:
	// constrcuter destructer
	ABattleTextBox();
	~ABattleTextBox();

	// delete Function
	ABattleTextBox(const ABattleTextBox& _Other) = delete;
	ABattleTextBox(ABattleTextBox&& _Other) noexcept = delete;
	ABattleTextBox& operator=(const ABattleTextBox& _Other) = delete;
	ABattleTextBox& operator=(ABattleTextBox&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* BoxRenderer = nullptr;
	UImageRenderer* TextRendererTop = nullptr;
	UImageRenderer* TextRendererBottom = nullptr;
};


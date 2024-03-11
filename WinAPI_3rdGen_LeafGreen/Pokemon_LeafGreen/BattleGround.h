#pragma once
#include <EngineCore\Actor.h>

class ABattleGround : public AActor
{
public:
	// constrcuter destructer
	ABattleGround();
	~ABattleGround();

	// delete Function
	ABattleGround(const ABattleGround& _Other) = delete;
	ABattleGround(ABattleGround&& _Other) noexcept = delete;
	ABattleGround& operator=(const ABattleGround& _Other) = delete;
	ABattleGround& operator=(ABattleGround&& _Other) noexcept = delete;

	void SetRenderer(std::string_view _Image);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Renderer = nullptr;
};

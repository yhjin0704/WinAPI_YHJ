#pragma once
#include "Character.h"
#include "Global.h"

class APlayer : public ACharacter
{
public:
	static APlayer* GetMainPlayer();

	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	static APlayer* MainPlayer;

	UImageRenderer* MenuRenderer;
	UImageRenderer* MenuPokemonTextRenderer;
	UImageRenderer* MenuIvenTextRenderer;
	UImageRenderer* MenuPlayerTextRenderer;
	UImageRenderer* MenuExitTextRenderer;

	UImageRenderer* MenuExplainRenderer;
	UImageRenderer* MenuExplainTextRenderer;

	FVector PrevFieldPos = FVector::Zero;
	UCollision* PlayerCollision = nullptr;

	bool IsActionDelay = false;
	float CurDelayTime = 0.0f;

	bool IsTextDebugView = false;
	
	void KeyInputMove(float _DeltaTime);
	void SetKeyInputAnimation(EDirState _InputDir);
	void SetCurDelayTime();
	void InputDelayCheck(float _DeltaTime);
	void SetPlayerMovePos();

	void UseMenu();
	void UseRunningShoes();
	void UseBike();
};


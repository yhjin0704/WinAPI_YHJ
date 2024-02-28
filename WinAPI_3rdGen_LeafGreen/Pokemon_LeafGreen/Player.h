#pragma once
#include "Character.h"
#include "Global.h"

class APlayer : public ACharacter
{
public:
	static APlayer* GetMainPlayer();
	static void SetMainPlayer(APlayer* _MainPlayer);

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

	UImageRenderer* CursorRender;
	UImageRenderer* MenuRenderer;
	UImageRenderer* MenuPlayerTextRenderer;

	UImageRenderer* MenuExplainRenderer;
	UImageRenderer* MenuExplainTextRenderer;

	FVector PrevFieldPos = FVector::Zero;
	UCollision* PlayerCollision = nullptr;

	bool IsActionDelay = false;
	float CurDelayTime = 0.0f;

	bool IsUseMenu = false;

	bool IsTextDebugView = false;

	void CreatePlayerAllRender();
	void CreateMenu();
	
	void KeyInputMove(float _DeltaTime);
	void SetKeyInputAnimation(EDirState _InputDir);
	void SetCurDelayTime();
	void InputDelayCheck(float _DeltaTime);
	void SetPlayerMovePos();

	void UseMenu();
	void UseRunningShoes();
	void UseBike();
};


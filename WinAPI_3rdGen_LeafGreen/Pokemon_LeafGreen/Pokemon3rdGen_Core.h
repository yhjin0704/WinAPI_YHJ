#pragma once
#include <EngineCore\EngineCore.h>
#include <EngineBase\EngineDirectory.h>

class Pokemon3rdGen_Core : public UEngineCore
{
public:
	// constrcuter destructer
	Pokemon3rdGen_Core();
	~Pokemon3rdGen_Core();

	// delete Function
	Pokemon3rdGen_Core(const Pokemon3rdGen_Core& _Other) = delete;
	Pokemon3rdGen_Core(Pokemon3rdGen_Core&& _Other) noexcept = delete;
	Pokemon3rdGen_Core& operator=(const Pokemon3rdGen_Core& _Other) = delete;
	Pokemon3rdGen_Core& operator=(Pokemon3rdGen_Core&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void End() override;

	UEngineDirectory FieldPath;

private:

};


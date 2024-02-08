#pragma once
#include <EngineCore\Level.h>
#include <EngineBase\EngineDirectory.h>

class UFieldLevel : public ULevel
{
public:
	// constrcuter destructer
	UFieldLevel();
	~UFieldLevel();

	// delete Function
	UFieldLevel(const UFieldLevel& _Other) = delete;
	UFieldLevel(UFieldLevel&& _Other) noexcept = delete;
	UFieldLevel& operator=(const UFieldLevel& _Other) = delete;
	UFieldLevel& operator=(UFieldLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	//void Tick(float _DeltaTime) override;

	UEngineDirectory FieldPath;

private:

};


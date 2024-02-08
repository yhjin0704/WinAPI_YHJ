#pragma once
#include <EngineCore\Actor.h>

class AWestFieldGround : public AActor 
{
public:
	// constrcuter destructer
	AWestFieldGround();
	~AWestFieldGround();

	// delete Function
	AWestFieldGround(const AWestFieldGround& _Other) = delete;
	AWestFieldGround(AWestFieldGround&& _Other) noexcept = delete;
	AWestFieldGround& operator=(const AWestFieldGround& _Other) = delete;
	AWestFieldGround& operator=(AWestFieldGround&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MapImageName);
	void SetColMapImage(std::string_view _MapImageName);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* MapRenderer;
	UImageRenderer* ColMapRenderer = nullptr;
};


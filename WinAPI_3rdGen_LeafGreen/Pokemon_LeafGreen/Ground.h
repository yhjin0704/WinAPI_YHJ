#pragma once
#include <EngineCore\Actor.h>
#include <EngineBase\EngineDirectory.h>

class AGround : public AActor
{
public:
	// constrcuter destructer
	AGround();
	~AGround();

	// delete Function
	AGround(const AGround& _Other) = delete;
	AGround(AGround&& _Other) noexcept = delete;
	AGround& operator=(const AGround& _Other) = delete;
	AGround& operator=(AGround&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MapImageName);
	void SetColMapImage(std::string_view _MapImageName);
	void SetCoverMapImage(std::string_view _MapImageName);

	void SwitchDebug();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* MapRenderer;
	UImageRenderer* ColMapRenderer;
	UImageRenderer* CoverMapRenderer;

private:
};


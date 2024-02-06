#pragma once
#include <EngineCore/Actor.h>

class ATitleActor : public AActor
{
public:
	// constrcuter destructer
	ATitleActor();
	~ATitleActor();

	// delete Function
	ATitleActor(const ATitleActor& _Other) = delete;
	ATitleActor(ATitleActor&& _Other) noexcept = delete;
	ATitleActor& operator=(const ATitleActor& _Other) = delete;
	ATitleActor& operator=(ATitleActor&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	int TitleOrder = 0;
	UImageRenderer* Title_StartImg = nullptr;
	UImageRenderer* LeafGreen_Tile_K = nullptr;

};


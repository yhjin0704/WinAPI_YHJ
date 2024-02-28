#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/ImageRenderer.h>
#include "Global.h"

class AMenuCursor : public AActor
{
public:
	// constrcuter destructer
	AMenuCursor();
	~AMenuCursor();

	// delete Function
	AMenuCursor(const AMenuCursor& _Other) = delete;
	AMenuCursor(AMenuCursor&& _Other) noexcept = delete;
	AMenuCursor& operator=(const AMenuCursor& _Other) = delete;
	AMenuCursor& operator=(AMenuCursor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* CursorRender;
};


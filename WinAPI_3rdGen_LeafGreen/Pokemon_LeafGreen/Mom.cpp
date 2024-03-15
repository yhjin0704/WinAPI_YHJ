#include "Mom.h"

AMom::AMom()
{
}

AMom::~AMom()
{
}

void AMom::BeginPlay()
{
	ANpc::BeginPlay();

	CharacterRenderer->SetImage("Mom_Idle.png", 0);
	CharacterIfDownRenderer->SetImage("Mom_Idle.png", 0);
	
	CharacterRenderer->SetTransform({ { 0, 0 }, { 16.0f * FScaleMultiple, 32.0f * FScaleMultiple } });
	CharacterIfDownRenderer->SetTransform({ { 0, 0 },{ 16.0f * FScaleMultiple, 32.0f * FScaleMultiple } });

	DownCollision ;
	UpCollision  ;
	LeftCollision ;
	RightCollision;
}

void AMom::Tick(float _DeltaTime)
{
	ANpc::Tick(_DeltaTime);
}
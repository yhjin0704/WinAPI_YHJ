#include "MyBagLevel.h"

UMyBagLevel::UMyBagLevel()
{
}

UMyBagLevel::~UMyBagLevel()
{
}

void UMyBagLevel::BeginPlay()
{
	UMenuUILevel::BeginPlay();
}

void UMyBagLevel::Tick(float _DeltaTime)
{
	UMenuUILevel::Tick(_DeltaTime);
}

void UMyBagLevel::LevelStart(ULevel* _PrevLevel)
{
}

void UMyBagLevel::LevelEnd(ULevel* _NextLevel)
{
}
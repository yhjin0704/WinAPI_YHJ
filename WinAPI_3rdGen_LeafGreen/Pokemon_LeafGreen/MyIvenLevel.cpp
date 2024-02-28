#include "MyIvenLevel.h"

UMyIvenLevel::UMyIvenLevel()
{
}

UMyIvenLevel::~UMyIvenLevel()
{
}

void UMyIvenLevel::BeginPlay()
{
	UMenuUILevel::BeginPlay();
}

void UMyIvenLevel::Tick(float _DeltaTime)
{
	UMenuUILevel::Tick(_DeltaTime);
}
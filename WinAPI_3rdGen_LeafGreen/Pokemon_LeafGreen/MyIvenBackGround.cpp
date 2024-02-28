#include "MyIvenBackGround.h"

AMyIvenBackGround::AMyIvenBackGround()
{
}

AMyIvenBackGround::~AMyIvenBackGround()
{
}

void AMyIvenBackGround::BeginPlay()
{
	ABackGround::BeginPlay();
}

void AMyIvenBackGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);
}
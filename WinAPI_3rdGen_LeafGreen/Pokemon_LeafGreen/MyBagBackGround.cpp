#include "MyBagBackGround.h"

AMyBagBackGround::AMyBagBackGround()
{
}

AMyBagBackGround::~AMyBagBackGround()
{
}

void AMyBagBackGround::BeginPlay()
{
	ABackGround::BeginPlay();
}

void AMyBagBackGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);
}
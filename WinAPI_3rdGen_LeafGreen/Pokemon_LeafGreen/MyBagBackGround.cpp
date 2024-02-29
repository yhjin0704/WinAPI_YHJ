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

	SetBackGroundImage("Iven_Items.png");
}

void AMyBagBackGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('L'))
	{
	}
}
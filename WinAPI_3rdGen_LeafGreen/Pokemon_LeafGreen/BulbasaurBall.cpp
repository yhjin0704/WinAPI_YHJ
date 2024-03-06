#include "BulbasaurBall.h"

ABulbasaurBall::ABulbasaurBall()
{
}

ABulbasaurBall::~ABulbasaurBall()
{
}

void ABulbasaurBall::BeginPlay()
{
	BallRender = CreateImageRenderer(ERenderOrder::Object);
	BallRender->SetImage("Field_Item.png");
	BallRender->SetTransform({ { 0, 0 }, {(BallRender->GetImage()->GetScale()) * FScaleMultiple} });

	SelectImage = CreateImageRenderer(ERenderOrder::Menu);
	SelectImage->SetImage("Select_BBall.png");
	SelectImage->ActiveOff();
	
	

	BallCollision = CreateCollision(ECollisionOrder::Item);
	BallCollision->SetScale({ IGameTileScale, IGameTileScale });
	BallCollision->SetColType(ECollisionType::Rect);
	BallCollision->DebugRender(GetWorld()->GetCameraPos());
}

void ABulbasaurBall::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == BallCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		if (false == PlayerHelper::PlayerPause)
		{
			if (true == UEngineInput::IsDown('P'))
			{
				PlayerHelper::PlayerPause = true;
				SelectImage->SetTransform({ { GetWorld()->GetCameraPos()}, {(SelectImage->GetImage()->GetScale()) * FScaleMultiple} });
				SelectImage->ActiveOn();
			}
		}
	}
}
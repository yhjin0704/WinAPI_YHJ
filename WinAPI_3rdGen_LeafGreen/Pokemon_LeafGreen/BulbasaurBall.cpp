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
	}
}
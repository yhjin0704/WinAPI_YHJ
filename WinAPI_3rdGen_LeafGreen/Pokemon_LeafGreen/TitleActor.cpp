#include "TitleActor.h"
#include <EngineCore/EngineCore.h>
#include "Global.h"

ATitleActor::ATitleActor()
{
}

ATitleActor::~ATitleActor()
{
}

void ATitleActor::BeginPlay()
{
	AActor::BeginPlay();

	Title_StartImg = CreateImageRenderer();
	Title_StartImg->SetImage("Title_Start.png");

	SetActorLocation({ FHSceen_X , FHSceen_Y });
	Title_StartImg->SetTransform({ {0, 0}, {FScreen_X, FScreen_Y} });

	LeafGreen_Tile_K = CreateImageRenderer();
	LeafGreen_Tile_K->SetImage("PokemonLeafGreen_Tile_K.png");

}

void ATitleActor::Tick(float _DeltaTime)
{
	if (EngineInput::IsDown(' '))
	{
		switch (TitleOrder)
		{
		case 0:
			TitleOrder++;
			LeafGreen_Tile_K->SetTransform({ {0, 0}, {FScreen_X, FScreen_Y} });
			break;

		case 1:
			GEngine->ChangeLevel("FieldLevel");
			break;

		default:
			break;
		}
	}
}
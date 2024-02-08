#include "TitleActor.h"
#include <EnginePlatform\EngineInput.h>
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
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsAnykeyDown())
	{
		switch (TitleOrder)
		{
		case 0:
			TitleOrder++;
			Title_StartImg->ActiveOff();
			LeafGreen_Tile_K->SetTransform({ {0, 0}, {FScreen_X, FScreen_Y} });
			break;

		case 1:
			LeafGreen_Tile_K->ActiveOff();
			GEngine->ChangeLevel("WestFieldLevel");
			break;

		default:
			break;
		}
	}
}
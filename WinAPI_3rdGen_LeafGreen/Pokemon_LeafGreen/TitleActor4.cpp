#include "TitleActor4.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

ATitleActor4::ATitleActor4()
{
}

ATitleActor4::~ATitleActor4()
{
}

void ATitleActor4::BeginPlay()
{
	AActor::BeginPlay();

	UEngineDirectory TitlePath;
	TitlePath.MoveParent();
	TitlePath.Move("Resources");
	TitlePath.Move("Title");
	TitlePath.Move("Title_Intro_4");

	TitleIntro4List = TitlePath.AllFile({ ".png", ".bmp" }, true);

	TitleIntro4StartIter = TitleIntro4List.begin();
	TitleIntro4EndIter = TitleIntro4List.end();

	TitleIntroRen4 = CreateImageRenderer(0);

	TitleIntroRen4->SetTransform({ {FHScreen_X, FHScreen_Y}, {FScreen_X, FScreen_Y} });

	UEngineFile& File = (*TitleIntro4StartIter);
	UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	TitleIntroRen4->SetImage(File.GetFileName());
	++TitleIntro4StartIter;
}

void ATitleActor4::Tick(float _DeltaTime)
{
	Time += _DeltaTime;
	if (Time >= FrameTime)
	{
		UEngineFile& File = (*TitleIntro4StartIter);
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		TitleIntroRen4->SetImage(File.GetFileName());
		++TitleIntro4StartIter;
		Time = _DeltaTime - FrameTime;
	}

	if (TitleIntro4StartIter == TitleIntro4EndIter)
	{
		GEngine->ChangeLevel("WestFieldLevel");
	}

	if (UEngineInput::IsAnykeyDown())
	{
		GEngine->ChangeLevel("WestFieldLevel");
	}
}
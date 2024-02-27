#include "Menu.h"

AMenu::AMenu()
{
}

AMenu::~AMenu()
{
}

void AMenu::BeginPlay()
{
	AActor::BeginPlay();

	MenuRenderer = CreateImageRenderer(ERenderOrder::Menu);
	MenuRenderer->SetTransform({ {0, 0}, { 70.0f * FScaleMultiple, 72.0f * FScaleMultiple} });
	MenuRenderer->SetImage("Menu4.png");
}

void AMenu::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	/*APlayer* Player = APlayer::GetMainPlayer();

	if (nullptr == Player)
	{
		MsgBoxAssert("�÷��̾ �������� �ʽ��ϴ�.");
	}

	SetActorLocation(Player->GetActorLocation());*/
}
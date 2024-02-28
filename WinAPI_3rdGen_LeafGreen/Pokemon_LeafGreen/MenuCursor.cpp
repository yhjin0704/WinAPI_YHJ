#include "MenuCursor.h"

AMenuCursor::AMenuCursor()
{
}

AMenuCursor::~AMenuCursor()
{
}

void AMenuCursor::BeginPlay()
{
	CursorRender = CreateImageRenderer(ERenderOrder::Menu);
	CursorRender->SetImage("MenuCursor.png");
}

void AMenuCursor::Tick(float _DeltaTime)
{
}
#include "BattleSelectBox.h"
#include "Global.h"

ABattleSelectBox::ABattleSelectBox()
{
}

ABattleSelectBox::~ABattleSelectBox()
{
}

void ABattleSelectBox::BeginPlay()
{
	AActor::BeginPlay();
	CursorRender = CreateImageRenderer(ERenderOrder::Text);

	BoxRenderer = CreateImageRenderer(ERenderOrder::OnMenu);
	TextRendererFight = CreateImageRenderer(ERenderOrder::Text);
	TextRendererBag = CreateImageRenderer(ERenderOrder::Text);
	TextRendererPokemon = CreateImageRenderer(ERenderOrder::Text);
	TextRendererRun = CreateImageRenderer(ERenderOrder::Text);

	MoveTextRenderer1 = CreateImageRenderer(ERenderOrder::Text);
	MoveTextRenderer2 = CreateImageRenderer(ERenderOrder::Text);
	MoveTextRenderer3 = CreateImageRenderer(ERenderOrder::Text);
	MoveTextRenderer4 = CreateImageRenderer(ERenderOrder::Text);

	PPTextRenderer = CreateImageRenderer(ERenderOrder::Text);
	TypeTextRenderer = CreateImageRenderer(ERenderOrder::Text);

	TextRendererBag->ActiveOff();
	TextRendererPokemon->ActiveOff();
	TextRendererRun->ActiveOff();

	MoveTextRenderer1->ActiveOff();
	MoveTextRenderer2->ActiveOff();
	MoveTextRenderer3->ActiveOff();
	MoveTextRenderer4->ActiveOff();

	PPTextRenderer->ActiveOff();
	TypeTextRenderer->ActiveOff();

	CursorRender->SetImage("MenuCursor.png");
	CursorRender->SetTransform({ { ((ITileScale * 4) - 4) * IScaleMultiple, ((ITileScale * -4) - 3) * IScaleMultiple }, { (CursorRender->GetImage()->GetScale()) * FScaleMultiple} });

	BoxRenderer->SetImage("BattleSelectBox.png");
	BoxRenderer->SetSortType(EImageSortType::Right);
	UWindowImage* Image = BoxRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	BoxRenderer->SetTransform({ {240.0f * FScaleMultiple, 136.0f * FScaleMultiple }, { ImageScale * FScaleMultiple } });

	Global::SetPokemonText(TextRendererFight, Gdiplus::StringAlignment::StringAlignmentNear, "�ο��", Color8Bit::BlackA, 12.0f);
	TextRendererFight->SetTransform({ {134.0f * FScaleMultiple, 123.0f * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(TextRendererBag, Gdiplus::StringAlignment::StringAlignmentNear, "����", Color8Bit::BlackA, 12.0f);
	TextRendererBag->SetTransform({ {190.0f * FScaleMultiple, 123.0f * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(TextRendererPokemon, Gdiplus::StringAlignment::StringAlignmentNear, "���ϸ�", Color8Bit::BlackA, 12.0f);
	TextRendererPokemon->SetTransform({ {134.0f * FScaleMultiple, 139.0f * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(TextRendererRun, Gdiplus::StringAlignment::StringAlignmentNear, "����ģ��", Color8Bit::BlackA, 12.0f);
	TextRendererRun->SetTransform({ {190.0f * FScaleMultiple, 139.0f * FScaleMultiple }, { 0, 0 } });
}

void ABattleSelectBox::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ABattleSelectBox::SetSelectBoxActive(bool _OnOff)
{
	if (true == _OnOff)
	{
		BoxRenderer->ActiveOn();
	}
	else
	{
		BoxRenderer->ActiveOff();
	}
}

void ABattleSelectBox::SetSelectBoxTextActive(bool _OnOff)
{
	if (true == _OnOff)
	{
		TextRendererFight->ActiveOn();
		TextRendererBag->ActiveOn();
		TextRendererPokemon->ActiveOn();
		TextRendererRun->ActiveOn();
	}
	else
	{
		TextRendererFight->ActiveOff();
		TextRendererBag->ActiveOff();
		TextRendererPokemon->ActiveOff();
		TextRendererRun->ActiveOff();
	}
}

void ABattleSelectBox::SetCursorActive(bool _OnOff)
{
	if (true == _OnOff)
	{
		CursorRender->ActiveOn();
	}
	else
	{
		CursorRender->ActiveOff();
	}
}

void ABattleSelectBox::SetCursorRocation(float _X, float _Y)
{
	CursorRender->SetTransform({ { _X * FScaleMultiple, _Y * FScaleMultiple }, { (CursorRender->GetImage()->GetScale()) * FScaleMultiple} });
}
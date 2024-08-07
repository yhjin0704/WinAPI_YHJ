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

	CursorRender = CreateImageRenderer(ERenderOrder::OnText);

	BoxRenderer = CreateImageRenderer(ERenderOrder::OnMenu);
	TextRendererFight = CreateImageRenderer(ERenderOrder::OnText);
	TextRendererBag = CreateImageRenderer(ERenderOrder::OnText);
	TextRendererPokemon = CreateImageRenderer(ERenderOrder::OnText);
	TextRendererRun = CreateImageRenderer(ERenderOrder::OnText);

	MoveTextRenderer1 = CreateImageRenderer(ERenderOrder::OnText);
	MoveTextRenderer2 = CreateImageRenderer(ERenderOrder::OnText);
	MoveTextRenderer3 = CreateImageRenderer(ERenderOrder::OnText);
	MoveTextRenderer4 = CreateImageRenderer(ERenderOrder::OnText);

	PPTextRenderer = CreateImageRenderer(ERenderOrder::OnText);
	TypeTextRenderer = CreateImageRenderer(ERenderOrder::OnText);

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
	CursorRender->SetTransform({ { 0, 0 }, { (CursorRender->GetImage()->GetScale()) * FScaleMultiple} });

	BoxRenderer->SetImage("BattleSelectBox.png");
	BoxRenderer->SetSortType(EImageSortType::Right);
	UWindowImage* Image = BoxRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	BoxRenderer->SetTransform({ {240.0f * FScaleMultiple, 136.0f * FScaleMultiple }, { ImageScale * FScaleMultiple } });

	Global::SetPokemonText(TextRendererFight, Gdiplus::StringAlignment::StringAlignmentNear, "싸운다", Color8Bit::BlackA, 12.0f);
	TextRendererFight->SetTransform({ {134.0f * FScaleMultiple, 129.0f * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(TextRendererBag, Gdiplus::StringAlignment::StringAlignmentNear, "가방", Color8Bit::BlackA, 12.0f);
	TextRendererBag->SetTransform({ {190.0f * FScaleMultiple, 129.0f * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(TextRendererPokemon, Gdiplus::StringAlignment::StringAlignmentNear, "포켓몬", Color8Bit::BlackA, 12.0f);
	TextRendererPokemon->SetTransform({ {134.0f * FScaleMultiple, 145.0f * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(TextRendererRun, Gdiplus::StringAlignment::StringAlignmentNear, "도망친다", Color8Bit::BlackA, 12.0f);
	TextRendererRun->SetTransform({ {190.0f * FScaleMultiple, 145.0f * FScaleMultiple }, { 0, 0 } });

	MoveTextRenderer1->SetTransform({ {20.0f * FScaleMultiple, 129.0f * FScaleMultiple }, { 0, 0 } });
	MoveTextRenderer2->SetTransform({ {80.0f * FScaleMultiple, 129.0f * FScaleMultiple }, { 0, 0 } });
	MoveTextRenderer3->SetTransform({ {20.0f * FScaleMultiple, 145.0f * FScaleMultiple }, { 0, 0 } });
	MoveTextRenderer4->SetTransform({ {80.0f * FScaleMultiple, 145.0f * FScaleMultiple }, { 0, 0 } });
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

void ABattleSelectBox::ChangeToMoveSelect(bool _OnOff)
{
	if (true == _OnOff)
	{
		BoxRenderer->SetImage("BattleMoveSelectBox.png");
		UWindowImage* Image = BoxRenderer->GetImage();
		FVector ImageScale = Image->GetScale();
		BoxRenderer->SetTransform({ {240.0f * FScaleMultiple, 136.0f * FScaleMultiple }, { ImageScale * FScaleMultiple } });
	}
	else
	{
		BoxRenderer->SetImage("BattleSelectBox.png");
		UWindowImage* Image = BoxRenderer->GetImage();
		FVector ImageScale = Image->GetScale();
		BoxRenderer->SetTransform({ {240.0f * FScaleMultiple, 136.0f * FScaleMultiple }, { ImageScale * FScaleMultiple } });
	}
}

void ABattleSelectBox::SetSelectBoxMoveTextActive(bool _OnOff)
{
	if (true == _OnOff)
	{
		MoveTextRenderer1->ActiveOn();
		MoveTextRenderer2->ActiveOn();
		MoveTextRenderer3->ActiveOn();
		MoveTextRenderer4->ActiveOn();
	}
	else
	{
		MoveTextRenderer1->ActiveOff();
		MoveTextRenderer2->ActiveOff();
		MoveTextRenderer3->ActiveOff();
		MoveTextRenderer4->ActiveOff();
	}
}

void ABattleSelectBox::SetMoveText(std::string _Move1Name, std::string _Move2Name, std::string _Move3Name, std::string _Move4Name)
{
	Global::SetPokemonText(MoveTextRenderer1, Gdiplus::StringAlignment::StringAlignmentNear, _Move1Name, Color8Bit::BlackA, 12.0f);
	Global::SetPokemonText(MoveTextRenderer2, Gdiplus::StringAlignment::StringAlignmentNear, _Move2Name, Color8Bit::BlackA, 12.0f);
	Global::SetPokemonText(MoveTextRenderer3, Gdiplus::StringAlignment::StringAlignmentNear, _Move3Name, Color8Bit::BlackA, 12.0f);
	Global::SetPokemonText(MoveTextRenderer4, Gdiplus::StringAlignment::StringAlignmentNear, _Move4Name, Color8Bit::BlackA, 12.0f);
}

void ABattleSelectBox::SetCursorLocation(float _X, float _Y)
{
	CursorRender->SetTransform({ { _X * FScaleMultiple, _Y * FScaleMultiple }, { (CursorRender->GetImage()->GetScale()) * FScaleMultiple} });
}

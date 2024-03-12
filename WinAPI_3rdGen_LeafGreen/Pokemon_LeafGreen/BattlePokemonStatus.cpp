#include "BattlePokemonStatus.h"
#include "Global.h"

ABattlePokemonStatus::ABattlePokemonStatus()
{
}

ABattlePokemonStatus::~ABattlePokemonStatus()
{
}

void ABattlePokemonStatus::BeginPlay()
{
	AActor::BeginPlay();

	StatusWindowRenderer = CreateImageRenderer(ERenderOrder::Menu);
	PokemonNameRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonLevelRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonGenderRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHpBarRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHPRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonMaxHpRenderer = CreateImageRenderer(ERenderOrder::Text);
}

void ABattlePokemonStatus::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ABattlePokemonStatus::SetRenderer(std::string_view _Image)
{
	StatusWindowRenderer->SetImage(_Image);
	UWindowImage* Image = StatusWindowRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	StatusWindowRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), {ImageScale * FScaleMultiple} });
}

void ABattlePokemonStatus::SetDataRenderers(PokemonInfo _Entry,
	float _Name_X, float _Name_Y,
	float _Level_X, float _Level_Y,
	float _Gender_X, float _Gender_Y,
	float _HpBar_X, float _HpBar_Y,
	float _Hp_X, float _Hp_Y,
	float _MaxHp_X, float _MaxHp_Y)
{
	PokemonHPRenderer->ActiveOff();
	PokemonMaxHpRenderer->ActiveOff();

	Global::SetPokemonText(PokemonNameRenderer, Gdiplus::StringAlignment::StringAlignmentNear, _Entry.Name, Color8Bit::BlackA);
	PokemonNameRenderer->SetTransform({ { _Name_X * FScaleMultiple, _Name_Y * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(PokemonLevelRenderer, Gdiplus::StringAlignment::StringAlignmentNear, std::to_string(_Entry.Level), Color8Bit::BlackA, 12.0f);
	PokemonLevelRenderer->SetTransform({ { _Level_X * FScaleMultiple, _Level_Y * FScaleMultiple }, { 0, 0 } });

	if (true == _Entry.Gender)
	{
		PokemonGenderRenderer->SetImage("Gender_Male.png");
	}
	else
	{
		PokemonGenderRenderer->SetImage("Gender_Female.png");
	}
	UWindowImage* GenderImage = PokemonGenderRenderer->GetImage();
	FVector GenderImageScale = GenderImage->GetScale();
	PokemonGenderRenderer->SetTransform({ { _Gender_X * FScaleMultiple, _Gender_Y * FScaleMultiple }, (GenderImageScale * FScaleMultiple) });

	int BarGage = std::lround(std::ceil((static_cast<float>(_Entry.Hp) / static_cast<float>(_Entry.MaxHp)) * 48));
	if (0 > BarGage)
	{
		BarGage = 0;
	}
	if (48 < BarGage)
	{
		BarGage = 48;
	}
	PokemonHpBarRenderer->SetImage("Hp" + std::to_string(BarGage) + ".png");
	UWindowImage* BarImage = PokemonHpBarRenderer->GetImage();
	FVector BarImageScale = BarImage->GetScale();
	PokemonHpBarRenderer->SetTransform({ { _HpBar_X * FScaleMultiple, _HpBar_Y * FScaleMultiple }, (BarImageScale * FScaleMultiple) });

	if (0 > _Entry.Hp)
	{
		_Entry.Hp = 0;
	}
	if (_Entry.MaxHp < _Entry.Hp)
	{
		_Entry.Hp = _Entry.MaxHp;
	}
	Global::SetPokemonText(PokemonHPRenderer, Gdiplus::StringAlignment::StringAlignmentFar, std::to_string(_Entry.Hp), Color8Bit::BlackA, 12.0f);
	PokemonHPRenderer->SetTransform({ { _Hp_X * FScaleMultiple, _Hp_Y * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(PokemonMaxHpRenderer, Gdiplus::StringAlignment::StringAlignmentNear, std::to_string(_Entry.MaxHp), Color8Bit::BlackA, 12.0f);
	PokemonMaxHpRenderer->SetTransform({ { _MaxHp_X * FScaleMultiple, _MaxHp_Y * FScaleMultiple }, { 0, 0 } });
}
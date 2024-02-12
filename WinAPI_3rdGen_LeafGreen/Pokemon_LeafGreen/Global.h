#pragma once

enum ERenderOrder
{
	ColMap,
	Map,
	Player,
	CoverObject
};

enum class EDirState
{
	Idle,
	Down,
	Up,
	Left,
	Right
};

enum class EPlayerMoveState
{
	Walk,
	Run,
	Bike,
	Surf
};

class Global
{
public:
	static const int GIScaleMultiple;
	static const int GIGBAScreen_X;
	static const int GIGBAScreen_Y;
	static const int GIScreen_X;
	static const int GIScreen_Y;
	static const int GITileScale;
	static const int GIScreenTileScale;
	static const int GIHGBAScreen_X;
	static const int GIHGBAScreen_Y;
	static const int GIHSceen_X;
	static const int GIHSceen_Y;
					 
	static const float GFScaleMultiple;
	static const float GFGBAScreen_X;
	static const float GFGBAScreen_Y;
	static const float GFScreen_X;
	static const float GFScreen_Y;
	static const float GFTileScale;
	static const float GFScreenTileScale;
	static const float GFHGBAScreen_X;
	static const float GFHGBAScreen_Y;
	static const float GFHSceen_X;
	static const float GFHSceen_Y;

	static const float GWalkTime;

	// constrcuter destructer
	Global();
	~Global();

	// delete Function
	Global(const Global& _Other) = delete;
	Global(Global&& _Other) noexcept = delete;
	Global& operator=(const Global& _Other) = delete;
	Global& operator=(Global&& _Other) noexcept = delete;

protected:

private:

};

#define IScaleMultiple Global::GIScaleMultiple
#define IGBAScreen_X Global::GIGBAScreen_X
#define IGBAScreen_Y Global::GIGBAScreen_Y
#define IScreen_X Global::GIScreen_X
#define	IScreen_Y Global::GIScreen_Y
#define	ITileScale Global::GITileScale
#define	IScreenTileScale Global::GIScreenTileScale
#define	IHSceen_X Global::GIHSceen_X
#define	IHSceen_Y Global::GIHSceen_Y
		
#define FScaleMultiple Global::GFScaleMultiple
#define FGBAScreen_X Global::GFGBAScreen_X
#define FGBAScreen_Y Global::GFGBAScreen_Y
#define	FScreen_X Global::GFScreen_X
#define	FScreen_Y Global::GFScreen_Y
#define	FTileScale Global::GFTileScale
#define	FScreenTileScale Global::GFScreenTileScale
#define	FHSceen_X Global::GFHSceen_X
#define	FHSceen_Y Global::GFHSceen_Y

#define FWalkTime Global::GWalkTime;

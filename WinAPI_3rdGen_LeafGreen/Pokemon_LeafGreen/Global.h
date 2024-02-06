#pragma once
class Global
{
public:
	static const int GIPixel_Scale;
	static const int GIScreen_X;
	static const int GIScreen_Y;
	static const int GITile_Scale;
	static const int GIScreen_Tile_Scale;
	static const int GIHSceen_X;
	static const int GIHSceen_Y;
					 
	static const int GFPixel_Scale;
	static const int GFScreen_X;
	static const int GFScreen_Y;
	static const int GFTile_Scale;
	static const int GFScreen_Tile_Scale;
	static const int GFHSceen_X;
	static const int GFHSceen_Y;

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

#define IPixel_Scale Global::GIPixel_Scale
#define IScreen_X Global::GIScreen_X
#define	IScreen_Y Global::GIScreen_Y
#define	ITile_Scale Global::GITile_Scale
#define	IScreen_Tile_Scale Global::GIScreen_Tile_Scale
#define	IHSceen_X Global::GIHSceen_X
#define	IHSceen_Y Global::GIHSceen_Y
		
#define FPixel_Scale Global::GFPixel_Scale
#define	FScreen_X Global::GFScreen_X
#define	FScreen_Y Global::GFScreen_Y
#define	FTile_Scale Global::GFTile_Scale
#define	FScreen_Tile_Scale Global::GFScreen_Tile_Scale
#define	FHSceen_X Global::GFHSceen_X
#define	FHSceen_Y Global::GFHSceen_Y


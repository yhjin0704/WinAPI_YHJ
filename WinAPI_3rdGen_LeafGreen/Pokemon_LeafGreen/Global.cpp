#include "Global.h"

Global::Global()
{
}

Global::~Global()
{
}

const int Global::GIPixel_Scale = 3;
const int Global::GIScreen_X = 240 * GIPixel_Scale;
const int Global::GIScreen_Y = 160 * GIPixel_Scale;
const int Global::GITile_Scale = 16;
const int Global::GIScreen_Tile_Scale = GITile_Scale * GIPixel_Scale;
const int Global::GIHSceen_X = (GIScreen_X / 2);
const int Global::GIHSceen_Y = (GIScreen_Y / 2);
				  
const int Global::GFPixel_Scale		 = static_cast<float>(GIPixel_Scale);
const int Global::GFScreen_X			 = static_cast<float>(GIScreen_X);
const int Global::GFScreen_Y			 = static_cast<float>(GIScreen_Y);
const int Global::GFTile_Scale	 = static_cast<float>(GITile_Scale);
const int Global::GFScreen_Tile_Scale = static_cast<float>(GIScreen_Tile_Scale);
const int Global::GFHSceen_X			 = static_cast<float>(GIHSceen_X);
const int Global::GFHSceen_Y			 = static_cast<float>(GIHSceen_Y);
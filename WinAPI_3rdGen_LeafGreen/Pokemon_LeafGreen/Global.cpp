#include "Global.h"
#include <cmath>

Global::Global()
{
}

Global::~Global()
{
}

const int Global::GIPixel_Scale		  = 3;
const int Global::GIGBAScreen_X		  = 240;
const int Global::GIGBAScreen_Y		  = 160;
const int Global::GIScreen_X		  = GIGBAScreen_X * GIPixel_Scale;
const int Global::GIScreen_Y		  = GIGBAScreen_Y * GIPixel_Scale;
const int Global::GITile_Scale		  = 16;
const int Global::GIScreen_Tile_Scale = GITile_Scale * GIPixel_Scale;
const int Global::GIHGBAScreen_X      = (GIGBAScreen_X / 2);
const int Global::GIHGBAScreen_Y      = (GIGBAScreen_Y / 2);
const int Global::GIHSceen_X          = (GIScreen_X / 2);	
const int Global::GIHSceen_Y          = (GIScreen_Y / 2);
				  
const int Global::GFPixel_Scale		  = std::lround(GIPixel_Scale);
const int Global::GFGBAScreen_X		  = std::lround(GFGBAScreen_X);
const int Global::GFGBAScreen_Y       = std::lround(GFGBAScreen_Y);
const int Global::GFScreen_X	   	  = std::lround(GIScreen_X);
const int Global::GFScreen_Y	      = std::lround(GIScreen_Y);
const int Global::GFTile_Scale	      = std::lround(GITile_Scale);
const int Global::GFScreen_Tile_Scale = std::lround(GIScreen_Tile_Scale);
const int Global::GFHGBAScreen_X      = std::lround(GIHGBAScreen_X);
const int Global::GFHGBAScreen_Y      = std::lround(GIHGBAScreen_Y);
const int Global::GFHSceen_X		  = std::lround(GIHSceen_X);
const int Global::GFHSceen_Y	  	  = std::lround(GIHSceen_Y);
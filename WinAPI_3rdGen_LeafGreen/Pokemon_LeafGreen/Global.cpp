#include "Global.h"
#include <cmath>

Global::Global()
{
}

Global::~Global()
{
}

const int Global::GIScaleMultiple	  = 3;
const int Global::GIGBAScreen_X		  = 240;
const int Global::GIGBAScreen_Y		  = 160;
const int Global::GIScreen_X		  = GIGBAScreen_X * GIScaleMultiple;
const int Global::GIScreen_Y		  = GIGBAScreen_Y * GIScaleMultiple;
const int Global::GITileScale		  = 16;
const int Global::GIScreenTileScale = GITileScale * GIScaleMultiple;
const int Global::GIHGBAScreen_X      = (GIGBAScreen_X / 2);
const int Global::GIHGBAScreen_Y      = (GIGBAScreen_Y / 2);
const int Global::GIHSceen_X          = (GIScreen_X / 2);	
const int Global::GIHSceen_Y          = (GIScreen_Y / 2);
				  
const float Global::GFScaleMultiple    = std::lround(GIScaleMultiple);
const float Global::GFGBAScreen_X	    = std::lround(GFGBAScreen_X);
const float Global::GFGBAScreen_Y       = std::lround(GFGBAScreen_Y);
const float Global::GFScreen_X	        = std::lround(GIScreen_X);
const float Global::GFScreen_Y	        = std::lround(GIScreen_Y);
const float Global::GFTileScale	    = std::lround(GITileScale);
const float Global::GFScreenTileScale = std::lround(GIScreenTileScale);
const float Global::GFHGBAScreen_X      = std::lround(GIHGBAScreen_X);
const float Global::GFHGBAScreen_Y      = std::lround(GIHGBAScreen_Y);
const float Global::GFHSceen_X		    = std::lround(GIHSceen_X);
const float Global::GFHSceen_Y	  	    = std::lround(GIHSceen_Y);

const float Global::GWalkTime = 0.5f;
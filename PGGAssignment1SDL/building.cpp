#include "building.h"

/**************************************************************************************************************/

/*Constructs the building object*/
Building::Building(Texture * inputTexture, int spriteXNum, int spriteYNum)
{
	/*sets the texture*/
	texture = inputTexture;

	/*sets the inital posisiton to 0,0*/
	x = 0.0f;
	y = 0.0f;

	/*sets the source dimensions*/
	srcWidth = 88;
	srcHeight = 108;
	srcX = srcWidth * spriteXNum;
	srcY = srcHeight * spriteYNum;

	/*sets the scaled size of the image*/
	width = srcWidth;
	height = srcHeight;
	
}

/**************************************************************************************************************/

/*De-constructs the building object*/
Building::~Building()
{

}

#include "building.h"

/**************************************************************************************************************/

/*Constructs the building object*/
Building::Building(Texture * inputTexture, int spriteXNum, int spriteYNum, int scaledX, int scaledY)
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

	/*sets the scaled size of the image to be 32x32*/
	width = scaledX;
	height = scaledY;
	
}

/**************************************************************************************************************/

/*De-constructs the building object*/
Building::~Building()
{

}

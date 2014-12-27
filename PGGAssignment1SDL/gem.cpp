#include "gem.h"

/**************************************************************************************************************/

/*Constructs the gem object*/
Gem::Gem(Texture * inputTexture, float inputX, float inputY, int spriteSheetNumberX, int spriteSheetNumberY, int inType)
{
	texture = inputTexture; /*sets the texture to the inputed texture*/
	srcWidth = 21; /*sets the srcWidth to 21, the width of the gem sprite*/
	srcHeight = 21; /*sets the srcHeight to 21, the width of the gem sprite*/
	srcX = (23 * (spriteSheetNumberX + inType)) + 2; /*sets the srcX to the x position of the gem sprite*/
	srcY = (23 * spriteSheetNumberY) + 2; /*sets the srcY to the y position of the gem sprite*/

	/*sets the initial position of the player to the input positions*/
	x = inputX;
	y = inputY;

	/*sets the scaled size of the image to be 32x32*/
	width = 32;
	height = 32;

	/*sets the type*/
	type = inType;
}

/**************************************************************************************************************/

/*De-constructs the gem object*/
Gem::~Gem()
{

}

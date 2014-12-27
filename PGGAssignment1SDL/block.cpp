#include "block.h"

/**************************************************************************************************************/

/*Constructs the block object*/
Block::Block(Texture * inputTexture, float inputX, float inputY, int spriteSheetNumberX, int spriteSheetNumberY, int inType)
{
	texture = inputTexture; /*sets the texture to the inputed texture*/
	srcWidth = 21; /*sets the srcWidth to 21, the width of the block sprite*/
	srcHeight = 21; /*sets the srcHeight to 21, the width of the block sprite*/
	srcX = (23 * spriteSheetNumberX) + 2; /*sets the srcX to the x position of the block sprite*/
	srcY = (23 * spriteSheetNumberY) + 2; /*sets the srcY to the y position of the block sprite*/

	/*sets the initial position of the block to the input positions*/
	x = inputX;
	y = inputY;

	/*sets the type*/
	type = inType;

	/*sets the collision booleans*/
	collidable = true;
	damaging = false;
}

/**************************************************************************************************************/

/*De-constructs the block object*/
Block::~Block()
{

}

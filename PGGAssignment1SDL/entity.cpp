#include "entity.h"

/**************************************************************************************************************/

/*Constructs the entity object*/
Entity::Entity(Texture * inputTexture, float inputX, float inputY, int inputWidth, int inputHeight)
{
	texture = inputTexture; /*sets the texture to the inputed texture*/
	srcWidth = inputWidth; /*sets the srcWidth to the width of the Entities sprite*/
	srcHeight = inputHeight; /*sets the srcHeight to the width of the Entities sprite*/

	/*sets the initial position of the Entity to the input positions*/
	x = inputX;
	y = inputY;
}

/**************************************************************************************************************/

/*De-constructs the entity object*/
Entity::~Entity()
{
}

/**************************************************************************************************************/

/*Displays the modified texture renderer*/
void Entity::display(SDL_Renderer* renderer)
{
	/*Pushes the texture to the renderer using the dimensions specified in the entity.*/
	texture->pushSpriteToScreen(renderer, (int) x, (int) y, srcX, srcY, srcWidth, srcHeight, width, height);
}

/**************************************************************************************************************/

/*sets the x position of the entity*/
void Entity::setX(float inputX)
{
	/*sets the x position to the value of the inputed x position*/
	x = inputX;
}

/**************************************************************************************************************/

/*sets the y position of the entity*/
void Entity::setY(float inputY)
{
	/*sets the x position to the value of the inputed x position*/
	y = inputY;
}

/**************************************************************************************************************/

/*returns the x position*/
float Entity::getX()
{
	/*returns the x position*/
	return x;
}

/**************************************************************************************************************/

/*returns the y position*/
float Entity::getY()
{
	/*returns the y position*/
	return y;
}

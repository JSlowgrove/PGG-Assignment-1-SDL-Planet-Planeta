#include "block.h"

/**************************************************************************************************************/

/*Constructs the block object*/
Block::Block(Texture * inputTexture, float inputX, float inputY, int inType, int backgroundType)
	: MapObject(inputTexture, inputX, inputY)
{
	/*sets the type*/
	type = inType;

	/*sets the initial velocity to 0*/
	velocity = 0.0f;

	/*sets the collision booleans*/
	collidable = true;
	damaging = false;

	/*set the type details*/
	typeSetup(backgroundType);
}

/**************************************************************************************************************/

/*De-constructs the block object*/
Block::~Block()
{

}

/**************************************************************************************************************/

/*sets the velocity of the block*/
void Block::setVelocity(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocity = inputVelocity;
}

/**************************************************************************************************************/

/*updates x using the velocity*/
void Block::updateX(float dt)
{
	/*set the x position to value of x added to the velocity * the inputed deltaTime*/
	x += velocity * dt;
}

/**************************************************************************************************************/

/*sets up the block depending on the type*/
void Block::typeSetup(int backgroundType)
{
	/*the position increase on the spritesheet depending on the setting*/
	int setting;
	switch (backgroundType)
	{
	case 0:/*mountain*/
		setting = 2 * 23;
		break;
	case 1:/*jungle*/
		setting = 4 * 23;
		break;
	case 2:/*castle*/
		setting = 10 * 23;
		break;
	}

	switch (type)
	{
	case 0:/*Top Wall*/
		/*sets the srcX to the x position of the block sprite*/
		srcX = 71;
		/*sets the srcY to the y position of the block sprite*/
		srcY = 2 + setting;
		break;
	case 1:/*Top Right Wall*/
		/*sets the srcX to the x position of the block sprite*/
		srcX = 94;
		/*sets the srcY to the y position of the block sprite*/
		srcY = 2 + setting;
		break;
	case 2:/*Top Left Wall*/
		/*sets the srcX to the x position of the block sprite*/
		srcX = 48;
		/*sets the srcY to the y position of the block sprite*/
		srcY = 2 + setting;
		break;
	case 3:/*Middle Wall*/
		/*sets the srcX to the x position of the block sprite*/
		srcX = 48;
		/*sets the srcY to the y position of the block sprite*/
		srcY = 25 + setting;
		break;
	case 4:/*End Goal*/
		/*sets the srcX to the x position of the block sprite*/
		srcX = 232;
		/*sets the srcY to the y position of the block sprite*/
		srcY = 94;
		break;
	}
}
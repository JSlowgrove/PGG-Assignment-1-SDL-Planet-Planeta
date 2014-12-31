#include "gem.h"

/**************************************************************************************************************/

/*Constructs the gem object*/
Gem::Gem(Texture * inputTexture, float inputX, float inputY, int inType)
	: MapObject(inputTexture, inputX, inputY)
{
	/*sets the type*/
	type = inType;

	/*set the type details*/
	typeSetup();

	/*sets the initial velocity to 0*/
	velocity = 0.0f;

	/*sets the collision booleans*/
	collidable = true;
	damaging = false;
}

/**************************************************************************************************************/

/*De-constructs the gem object*/
Gem::~Gem()
{

}

/**************************************************************************************************************/

/*sets up the gem depending on the type*/
void Gem::typeSetup()
{
	switch (type)
	{
	case 0:/*yellow gem*/
		srcX = 370; /*sets the srcX to the x position of the yellow gem sprite*/
		srcY = 278; /*sets the srcY to the y position of the yellow gem sprite*/
		value = 10; /*sets the value of the gem*/
		break;
	case 1:/*green gem*/
		srcX = 393; /*sets the srcX to the x position of the green gem sprite*/
		srcY = 278; /*sets the srcY to the y position of the green gem sprite*/
		value = 20; /*sets the value of the gem*/
		break;
	case 2:/*red gem*/
		srcX = 416; /*sets the srcX to the x position of the red gem sprite*/
		srcY = 278; /*sets the srcY to the y position of the red gem sprite*/
		value = 50; /*sets the value of the gem*/
		break;
	case 3:/*blue gem*/
		srcX = 439; /*sets the srcX to the x position of the blue gem sprite*/
		srcY = 278; /*sets the srcY to the y position of the blue gem sprite*/
		value = 100; /*sets the value of the gem*/
		break;
	}	
}

/**************************************************************************************************************/

/*sets the velocity of the gem*/
void Gem::setVelocity(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocity = inputVelocity;
}

/**************************************************************************************************************/

/*updates x using the velocity*/
void Gem::updateX(float dt)
{
	/*set the x position to value of x added to the velocity * the inputed deltaTime*/
		x += velocity * dt;
}

/**************************************************************************************************************/

/*returns the value*/
int Gem::getValue()
{
	/*returns the value*/
	return value;
}
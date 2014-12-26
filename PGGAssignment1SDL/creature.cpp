#include "creature.h"

/**************************************************************************************************************/

/*Constructs the creature object*/
Creature::Creature()
{
	/*sets the scaled size of the image to be 32x32*/
	width = 32;
	height = 32;

	/*sets the initial velocitys to 0*/
	velocityX = 0.0f;
	velocityY = 0.0f;
}

/**************************************************************************************************************/

/*De-constructs the creature object*/
Creature::~Creature()
{
}

/**************************************************************************************************************/

/*sets the velocity of the creature*/
void Creature::setVelocityX(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocityX = inputVelocity;
}

/**************************************************************************************************************/

/*sets the velocity of the creature*/
void Creature::setVelocityY(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocityY = inputVelocity;
}

/**************************************************************************************************************/

/*updates the x position*/
void Creature::updateX(float dt)
{
	/*set the x position to value of x added to the velocity * the inputed deltaTime*/
	x += velocityX * dt;
}

/**************************************************************************************************************/

/*updates the y position*/
void Creature::updateY(float dt)
{
	/*set the y position to value of y added to the velocity * the inputed deltaTime*/
	y += velocityY * dt;
}

/**************************************************************************************************************/

/*returns the x velocity*/
float Creature::getVelocityX()
{
	/*returns the x velocity*/
	return velocityX;
}

/**************************************************************************************************************/

/*returns the y velocity*/
float Creature::getVelocityY()
{
	/*returns the y velocity*/
	return velocityY;
}
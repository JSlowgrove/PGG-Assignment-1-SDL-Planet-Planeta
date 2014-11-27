#include "minion.h"

/**************************************************************************************************************/

/*Constructs the minion object*/
Minion::Minion(int inAttack, float inSpeed, float radius)
{
	/*sets the scaled size of the image to be 32x32*/
	width = 32;
	height = 32;

	/*sets the initial velocitys to 0*/
	velocityX = 0.0f;
	velocityY = 0.0f;

	/*sets the minions details*/
	attack = inAttack;
	speed = inSpeed;
	sightRadius = radius;
}

/**************************************************************************************************************/

/*De-constructs the minion object*/
Minion::~Minion()
{
}

/**************************************************************************************************************/

/*sets the velocity of the minion*/
void Minion::setVelocityX(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocityX = inputVelocity;
}

/**************************************************************************************************************/

/*sets the velocity of the minion*/
void Minion::setVelocityY(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocityY = inputVelocity;
}

/**************************************************************************************************************/

/*updates the x position*/
void Minion::updateX(float dt)
{
	/*set the x position to value of x added to the velocity * the inputed deltaTime*/
	x += velocityX * dt;
}

/**************************************************************************************************************/

/*updates the y position*/
void Minion::updateY(float dt)
{
	/*set the y position to value of y added to the velocity * the inputed deltaTime*/
	y += velocityY * dt;
}

/**************************************************************************************************************/

/*returns the x velocity*/
float Minion::getVelocityX()
{
	/*returns the x velocity*/
	return velocityX;
}

/**************************************************************************************************************/

/*returns the y velocity*/
float Minion::getVelocityY()
{
	/*returns the y velocity*/
	return velocityY;
}

/**************************************************************************************************************/

/*updates the speed*/
void Minion::setSpeed(float inSpeed)
{
	/*set the speed to value of the inputed speed*/
	speed = inSpeed;
}

/**************************************************************************************************************/

/*returns the speed*/
float Minion::getSpeed()
{
	/*returns the speed*/
	return speed;
}

/**************************************************************************************************************/

/*updates the attack*/
void Minion::setAttack(int inAttack)
{
	/*set the attack to value of the inputed attack*/
	attack = inAttack;
}

/**************************************************************************************************************/

/*returns the attack*/
int Minion::getAttack()
{
	/*returns the attack*/
	return attack;
}

/**************************************************************************************************************/

/*updates the sight radius*/
void Minion::setSightRadius(float inRadius)
{
	/*set the sight radius to value of the inputed radius*/
	sightRadius = inRadius;
}

/**************************************************************************************************************/

/*returns the sightRadius*/
float Minion::getSightRadius()
{
	/*returns the radius of the visible sight*/
	return sightRadius;
}
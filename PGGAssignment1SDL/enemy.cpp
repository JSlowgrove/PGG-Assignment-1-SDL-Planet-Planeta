#include "enemy.h"

/**************************************************************************************************************/

/*Constructs the enemy object*/
Enemy::Enemy(Texture * inputTexture, float inX, float inY, int inType)
	: Creature(inputTexture, inX, inY)
{
	/*initialise type*/
	type = inType;

	/*sets the object to not be deleted*/
	deleteable = false;

	/*set the type details*/
	typeSetup();
}

/**************************************************************************************************************/

/*De-constructs the enemy object*/
Enemy::~Enemy()
{
}

/**************************************************************************************************************/

/*sets up the enemy depending on the type*/
void Enemy::typeSetup()
{
	switch (type)
	{
	case 0:/*killer snail*/
		srcX = 554; /*sets the srcX to the x position of the snail sprite*/
		srcY = 301; /*sets the srcY to the y position of the snail sprite*/
		speed = -100.0f;/*sets the speed of the snail*/
		break;
	case 1:/*evil worm*/
		srcX = 669; /*sets the srcX to the x position of the worm sprite*/
		srcY = 324; /*sets the srcY to the y position of the worm sprite*/
		speed = 0.0f; /*sets the speed of the worm*/
		break;
	}
}

/**************************************************************************************************************/

/*sets if the object is to be deleted*/
void Enemy::setDeletable(bool inputDelete)
{
	/*sets if the object is to be deleted*/
	deleteable = inputDelete;
}

/**************************************************************************************************************/

/*returns deleteable*/
bool Enemy::getDeletable()
{
	/*returns the bool deleteable value*/
	return deleteable;
}

/**************************************************************************************************************/

/*returns speed*/
float Enemy::getSpeed()
{
	/*returns the speed value*/
	return speed;
}

/**************************************************************************************************************/

/*sets the enemy speed*/
void Enemy::setSpeed(float inputSpeed)
{
	/*sets the enemy speed*/
	speed = inputSpeed;
}
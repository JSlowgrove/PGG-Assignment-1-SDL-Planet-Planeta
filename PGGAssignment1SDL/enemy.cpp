#include "enemy.h"

/**************************************************************************************************************/

/*Constructs the enemy object*/
Enemy::Enemy(Texture * inputTexture, float inX, float inY, int inType)
	: Creature(inputTexture, inX, inY)
{
	/*initialise type*/
	type = inType;
	
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
		//velocityX = -10.0f;
		break;
	}
}
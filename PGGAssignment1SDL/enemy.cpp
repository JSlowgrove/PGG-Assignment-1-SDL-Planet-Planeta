#include "enemy.h"

/**************************************************************************************************************/

/*Constructs the enemy object*/
Enemy::Enemy(Texture * inputTexture)
	: Creature(inputTexture, 0.0f, 0.0f)
{
}

/**************************************************************************************************************/

/*De-constructs the enemy object*/
Enemy::~Enemy()
{
}
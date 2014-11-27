#include "player.h"

/**************************************************************************************************************/

/*Constructs the player object*/
Player::Player()
{
	/*sets the initial variables*/
	resources = 0;
	power = 0;
	minionNumber = 0;
	maxMinions = 20;
}

/**************************************************************************************************************/

/*De-constructs the player object*/
Player::~Player()
{
}

/**************************************************************************************************************/

/*sets the number of the resources*/
void Player::setResources(int inputResources)
{
	/*sets the number of the resources to the value of the inputed resources*/
	resources = inputResources;
}

/**************************************************************************************************************/

/*returns the number of resources*/
int Player::getResources()
{
	/*returns the number of resources*/
	return resources;
}

/**************************************************************************************************************/

/*sets the amount of power*/
void Player::setPower(int inputPower)
{
	/*sets the amount of power to the value of the inputed power*/
	power = inputPower;
}

/**************************************************************************************************************/

/*returns the amount of power*/
int Player::getPower()
{
	/*returns the amount of power*/
	return power;
}

/**************************************************************************************************************/

/*sets the number of the minions*/
void Player::setMinions(int inputMinions)
{
	/*sets the number of the minions to the value of the inputed minions*/
	minionNumber = inputMinions;
}

/**************************************************************************************************************/

/*returns the number of minions*/
int Player::getMinions()
{
	/*returns the number of minions*/
	return minionNumber;
}

/**************************************************************************************************************/

/*sets the max number of minions*/
void Player::setMaxMinions(int inputMax)
{
	/*sets the max number of minions to the value of the inputed max*/
	maxMinions = inputMax;
}

/**************************************************************************************************************/

/*returns the max number of minions*/
int Player::getMaxMinions()
{
	/*returns the max number of minions*/
	return maxMinions;
}
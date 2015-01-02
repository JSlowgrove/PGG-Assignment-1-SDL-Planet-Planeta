#include "player.h"

/**************************************************************************************************************/

/*Constructs the player object*/
Player::Player(Texture * inputTexture, float inputX, float inputY, int spriteSheetNumberX, int spriteSheetNumberY)
	: Creature(inputTexture, inputX, inputY)
{
	/*sets the srcX to the x position of the player sprite*/
	srcX = (23 * spriteSheetNumberX) + 2;
	/*sets the srcY to the y position of the player sprite*/
	srcY = (23 * spriteSheetNumberY) + 2;

	/*sets the initial player details*/
	score = 0;
	lives = 3;

	/*initialise jump varibles*/
	gravity = true;
	landed = false;
	jump = false;
	gravityF = 9.81f;
}

/**************************************************************************************************************/

/*De-constructs the player object*/
Player::~Player()
{
}

/**************************************************************************************************************/

/*sets the lives of the player*/
void Player::setLives(int inputLives)
{
	/*sets the number of lives to the value of the inputed lives*/
	lives = inputLives;
}

/**************************************************************************************************************/

/*returns the lives*/
int Player::getLives()
{
	/*returns the lives*/
	return lives;
}

/**************************************************************************************************************/

/*sets the score*/
void Player::setScore(int inputScore)
{
	/*sets the score to the value of the input score*/
	score = inputScore;
}

/**************************************************************************************************************/

/*returns the score*/
int Player::getScore()
{
	/*returns the score*/
	return score;
}

/**************************************************************************************************************/

/*sets if the gravity is acting*/
void Player::setGravity(bool inputGravity)
{
	/*sets if the gravity is acting*/
	gravity = inputGravity;
}

/**************************************************************************************************************/

/*returns if the gravity is acting*/
bool Player::getGravity()
{
	/*returns if the gravity is acting*/
	return gravity;
}

/**************************************************************************************************************/

/*sets if the player has landed*/
void Player::setLanded(bool inputLanding)
{
	/*sets if the player has landed*/
	landed = inputLanding;
}

/**************************************************************************************************************/

/*returns if the player has landed*/
bool Player::getLanded()
{
	/*returns if the player has landed*/
	return landed;
}

/**************************************************************************************************************/

/*sets if the Player is jumping*/
void Player::setJump(bool inputJump)
{
	/*sets if the Player is jumping*/
	jump = inputJump;
}

/**************************************************************************************************************/

/*returns if the Player is jumping*/
bool Player::getJump()
{
	/*returns if the Player is jumping*/
	return jump;
}

/**************************************************************************************************************/

/*returns the value of the force gravity*/
float Player::getGravityF()
{
	/*returns the value of the force gravity*/
	return gravityF;
}

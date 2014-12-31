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
#include "background.h"

/**************************************************************************************************************/

/*Constructs the background object*/
Background::Background(Texture * inputTexture, int backgroundType)
{
	texture = inputTexture; /*sets the texture to the inputed texture*/
	srcWidth = texture->getWidth(); /*sets the srcWidth to the original width of the texture*/
	srcHeight = 63; /*sets the srcHeight to the height of one background in the backgrounds sprite sheet*/
	srcX = 0; /*sets the srcX to the furthest left of the texture*/

	/*sets the srcY to the position of the inputed background type.	example : for the 2nd background the
	background type will be 1, so the srcY will be srcHeight * 1, which would puts its srcY	coordinate to 63,
	setting the background to be loaded as the 2nd one on the background sprite sheet*/
	srcY = srcHeight * backgroundType;

	/*sets the scaled size of the image to be 1760, which is the value of the original width
	scaled to the same aspect ratio to get the height to 480. This has been pre-calculated*/
	width = 1760;
	height = 480;

	/*sets the initial position of the background to 0,0*/
	x = 0.0f;
	y = 0.0f;

	velocity = 0.0f;/*sets the initial velocity to 0*/
	maxX = 0;/*sets the maximum x coordinate to 0, so that the background can not go any further to the right*/

	/*sets the maximum x coordinate to 0 - the size of the background width added to the screen width,
	so that the background can not go any further to the left than this point*/
	minX = (0 - width) + 640;
	moveable = true;/*sets the background to moveable*/
}

/**************************************************************************************************************/

/*De-constructs the background object*/
Background::~Background()
{
}

/**************************************************************************************************************/

/*sets the velocity of the background*/
void Background::setVelocity(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocity = inputVelocity;
}

/**************************************************************************************************************/

/*checks the of the x position is within boundaries and updates it accordingly*/
void Background::updateX(float dt)
{
	/*checks if the background can be moved, this is done before the boundary check to remove stutter*/
	if (moveable)
	{
		/*if it can move, set the x position to value of x added to the velocity * the inputed deltaTime*/
		x += velocity * dt;
	}

	/*checks to see if the x position is between or equal the maxX and minX*/
	if (x <= maxX && x >= minX)
	{
		/*if so set the background to moveable*/
		moveable = true;
	}

	/*if not check if it had gone pass the minX boundary*/
	else if (x <= maxX && x < minX)
	{
		/*if so set the background to not move and the x position to minX*/
		moveable = false;
		x = (float)minX;
	}

	/*if not it had gone pass the maxX boundary*/
	else
	{
		/*if so set the background to not move and the x position to maxX*/
		moveable = false;
		x = (float)maxX;
	}

}
#include "mapObject.h"

/**************************************************************************************************************/

/*Constructs the MapObject object*/
MapObject::MapObject(Texture * inputTexture, float inputX, float inputY)
	: Entity(inputTexture, inputX, inputY, 21, 21)
{
	/*sets the scaled size of the image to be 32x32*/
	width = 32;
	height = 32;

	/*sets the initial velocity to 0*/
	velocity = 0.0f;

	/*sets the object to not be deleted*/
	deleteable = false;

	maxX = inputX;/*sets the maximum x coordinate to its initial x, so that the object can not go any further to the right*/
	/*sets the minimum x coordinate to the maximum x coordinate - the size of the map added to the screen width,
	so that the object can not go any further to the left than this point*/
	minX = (maxX - 1760) + 640;
	moveable = true;/*sets the object to moveable*/
}

/**************************************************************************************************************/

/*De-constructs the mapObject object*/
MapObject::~MapObject()
{
}

/**************************************************************************************************************/

/*sets if the object is collidable*/
void MapObject::setCollidable(bool inputCollidable)
{
	/*sets if the object is collidable to the input boolean*/
	collidable = inputCollidable;
}

/**************************************************************************************************************/

/*returns collidable*/
bool MapObject::getCollidable()
{
	/*returns the bool collidable value*/
	return collidable;
}

/**************************************************************************************************************/

/*sets if the object is damaging*/
void MapObject::setDamaging(bool inputDamaging)
{
	/*sets if the object is damaging to the input boolean*/
	damaging = inputDamaging;
}

/**************************************************************************************************************/

/*returns damaging*/
bool MapObject::getDamaging()
{
	/*returns the bool damaging value*/
	return damaging;
}

/**************************************************************************************************************/

/*sets if the object is to be deleted*/
void MapObject::setDeletable(bool inputDelete)
{
	/*sets if the object is to be deleted*/
	deleteable = inputDelete;
}

/**************************************************************************************************************/

/*returns deleteable*/
bool MapObject::getDeletable()
{
	/*returns the bool deleteable value*/
	return deleteable;
}

/**************************************************************************************************************/

/*sets the velocity of the object*/
void MapObject::setVelocity(float inputVelocity)
{
	/*sets the velocity to the value of the inputed velocity*/
	velocity = inputVelocity;
}

/**************************************************************************************************************/

/*updates x using the velocity*/
void MapObject::updateX(float dt)
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

/**************************************************************************************************************/

/*returns the x velocity*/
float MapObject::getVelocity()
{
	/*returns the velocity*/
	return velocity;
}
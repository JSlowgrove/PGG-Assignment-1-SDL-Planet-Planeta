#include "mapObject.h"

/**************************************************************************************************************/

/*Constructs the MapObject object*/
MapObject::MapObject(Texture * inputTexture, float inputX, float inputY)
	: Entity(inputTexture, inputX, inputY, 21, 21)
{
	/*sets the scaled size of the image to be 32x32*/
	width = 32;
	height = 32;

	/*sets the object to not be deleted*/
	deleteable = false;
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
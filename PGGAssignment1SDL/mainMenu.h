#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

/**
@brief Creates a Building object that inherits Entity.
*/
class Building : public Entity
{
private:
public:
	/**
	Constructs Building object
	Constructs a Building object.
	inputTexture, int spriteXNum, int spriteYNum
	@param Texture* a pointer to the spritesheet
	@int the number of the sprite in the spritesheet along the x axis
	@int the number of the sprite in the spritesheet along the y axis
	*/
	Building(Texture *, int, int);

	/**
	De-constructs a Building object
	De-constructs the Building object
	*/
	~Building();
};
#endif
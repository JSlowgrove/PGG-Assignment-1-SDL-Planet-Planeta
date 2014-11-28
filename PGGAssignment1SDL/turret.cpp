#include "turret.h"

/**************************************************************************************************************/

/*Constructs the turret object*/
Turret::Turret(Texture * inputTexture, int inAttack, float radius, int spriteXNum, int spriteYNum)
{
	/*sets the texture*/
	texture = inputTexture;

	/*sets the inital posisiton to 0,0*/
	x = 0.0f;
	y = 0.0f;

	/*sets the source dimensions*/
	srcWidth = 88;
	srcHeight = 108;
	srcX = srcWidth * spriteXNum;
	srcY = srcHeight * spriteYNum;

	/*sets the scaled size of the image to be 44x54*/
	width = 44;
	height = 54;

	/*sets the turrets details*/
	attack = inAttack;
	sightRadius = radius;
}

/**************************************************************************************************************/

/*De-constructs the turret object*/
Turret::~Turret()
{
}

/**************************************************************************************************************/

/*updates the attack*/
void Turret::setAttack(int inAttack)
{
	/*set the attack to value of the inputed attack*/
	attack = inAttack;
}

/**************************************************************************************************************/

/*returns the attack*/
int Turret::getAttack()
{
	/*returns the attack*/
	return attack;
}

/**************************************************************************************************************/

/*updates the sight radius*/
void Turret::setSightRadius(float inRadius)
{
	/*set the sight radius to value of the inputed radius*/
	sightRadius = inRadius;
}

/**************************************************************************************************************/

/*returns the sightRadius*/
float Turret::getSightRadius()
{
	/*returns the radius of the visible sight*/
	return sightRadius;
}
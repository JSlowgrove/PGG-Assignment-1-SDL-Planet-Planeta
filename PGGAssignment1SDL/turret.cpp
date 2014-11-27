#include "turret.h"

/**************************************************************************************************************/

/*Constructs the turret object*/
Turret::Turret(int, float)
{
	/*sets the scaled size of the image to be 32x32*/
	width = 32;
	height = 32;

	/*sets the details of the Minion*/
	attack;
	sightRadius;
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
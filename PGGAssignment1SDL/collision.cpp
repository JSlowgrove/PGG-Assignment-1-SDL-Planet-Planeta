#include "collision.h"

/**************************************************************************************************************/

/*Constructs the collision object*/
Collision::Collision(Player * inputPlayer, MapLoader * inputMap)
{
	player = inputPlayer;
	map = inputMap;
}

/**************************************************************************************************************/

/*De-constructs the collision object*/
Collision::~Collision()
{
}

/**************************************************************************************************************/

/*tests if the player collides with an object*/
void Collision::playerCollisionTest(float deltaTime)
{
	/*the updated value of the position*/
	float updatedX = player->getX() + (player->getVelocityX() * deltaTime);
	float updatedY = player->getY() + (player->getVelocityY() * deltaTime);

	/*the value to add to fix the rounding errors*/
	int xRoundingFix1 = 0;
	int xRoundingFix2 = 0;
	int yRoundingFix1 = 0;
	int yRoundingFix2 = 0;

	/*if the float will round up*/
	if (updatedX / 32 > 0.5)
	{
		xRoundingFix1 = -1;
	}
	else
	{
		xRoundingFix2 = 1;
	}
	/*the players position on the map grid*/
	int minPlayerMapX = (updatedX / 32) + xRoundingFix1;//rounded down to nearest int
	int maxPlayerMapX = (updatedX / 32) + xRoundingFix2;//rounded up to nearest int

	/*if the float will round up*/
	if (updatedY / 32 > 0.5)
	{
		yRoundingFix1 = -1;
	}
	else
	{
		yRoundingFix2 = 1;
	}
	/*the players position on the map grid*/
	int minPlayerMapY = (updatedY / 32) + yRoundingFix1;//rounded down to nearest int
	int maxPlayerMapY = (updatedY / 32) + yRoundingFix2;//rounded up to nearest int

	/*if the player is going left*/
	//if (player->getVelocityX() < 0)
	//{
		/*test only the tiles within the maxY and minY tiles*/
		for (int i = minPlayerMapY; i <= maxPlayerMapY; i++)
		{
			/*test only the tiles within the 0 and minX tiles*/
			for (int j = 0; j <= minPlayerMapX; j++)
			{
				/*check if the type of the tile*/
				switch (map->getType(i, j))
				{
				case 'X':
					/*empty tile so do nothing*/
					break;
				case 'B':
					/*block tile so do block collision action*/
					blockAction(map->getIndex(i, j));
					break;
				case 'G':
					/*gem tile so do block collision action*/
					gemAction(map->getIndex(i, j));
					/*removes the gem from the map*/
					map->setEntityBlank(i, j);
					break;
				}
			}
		}
	//}
}

/**************************************************************************************************************/

/*Performs the action that happens when the player collides with a Gem*/
void Collision::gemAction(int i)
{
	/*adds the value of the gem to the players score*/
	player->setScore(player->getScore() + map->getGem(i)->getValue());
	/*sets the gem to be able to be hidden*/
	map->getGem(i)->setDeletable(true);
}

/**************************************************************************************************************/

/*Performs the action that happens when the player collides with a Block*/
void Collision::blockAction(int i)
{
	std::cout << "block" << std::endl;
}
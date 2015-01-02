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
void Collision::playerCollisionTest(float deltaTime, float backgroundPos, Texture* tex, SDL_Renderer * tmp)
{
	/*the updated value of the position*/
	float updatedX = player->getX() + (player->getVelocityX() * deltaTime);
	float updatedY = player->getY() + (player->getVelocityY() * deltaTime);

	/*the players position on the map grid*/
	int minPlayerMapX = 0;
	int maxPlayerMapX = 0;
	/*workout the map position depending on how it will round*/
	roundingCheck(updatedX, minPlayerMapX, maxPlayerMapX, backgroundPos);

	/*the players position on the map grid*/
	int minPlayerMapY = 0;
	int maxPlayerMapY = 0;
	/*workout the map position depending on how it will round*/
	roundingCheck(updatedY, minPlayerMapY, maxPlayerMapY, 0);

	/*for the closest objects*/
	std::vector<int> closestIIndex;
	std::vector<int> closestJIndex;
	closestIIndex.resize(0);
	closestJIndex.resize(0);

	/*if the player is going left*/
	if (player->getVelocityX() < 0 || map->getBlock(0)->getVelocity() > 0)
	{
		/*test only the tiles within the maxY and minY tiles*/
		for (int i = minPlayerMapY; i <= maxPlayerMapY; i++)
		{
			closestIIndex.resize(closestIIndex.size() + 1);
			closestJIndex.resize(closestJIndex.size() + 1);
			/*test only the tiles within the 0 and minX tiles*/
			for (int j = 0; j <= minPlayerMapX; j++)
			{
				/*check if the type of the tile*/
				switch (map->getType(i, j))
				{
				case 'X':
					/*empty tile so do nothing*/
					break;
				default:
					/*set as current closest*/
					closestIIndex[closestIIndex.size()-1] = i;
					closestJIndex[closestJIndex.size()-1] = j;
					break;
				}
			}
		}
		/*loop through the closest*/
		for (int i = 0; i < closestIIndex.size(); i++)
		{
			/*tmp to help with debugging*/
			tex->pushSpriteToScreen(tmp, (closestJIndex[i] * 32) + backgroundPos, (closestIIndex[i] * 32), 232, 94, 21, 21, 32, 32);
			
			/*check if the type of the tile*/
			switch (map->getType(closestIIndex[i], closestJIndex[i]))
			{
			case 'X':
				/*empty tile so do nothing*/
				break;
			case 'B':
				/*check if its is interesting*/
				if (map->getBlock(map->getIndex(closestIIndex[i], closestJIndex[i]))->getX() + 32 >= updatedX)
				{
					/*block tile so do block collision action*/
					blockAction(map->getIndex(closestIIndex[i], closestJIndex[i]));
				}
				break;
			case 'G':
				/*check if its is interesting*/
				if (map->getGem(map->getIndex(closestIIndex[i], closestJIndex[i]))->getX() + 32 >= updatedX)
				{
					/*gem tile so do block collision action*/
					gemAction(map->getIndex(closestIIndex[i], closestJIndex[i]));
					/*removes the gem from the map*/
					map->setEntityBlank(closestIIndex[i], closestJIndex[i]);
				}
				break;
			}
		}		
	}
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

}

/**************************************************************************************************************/

/*Checks how the number will be rounded and works out the map position accordingly*/
void Collision::roundingCheck(float updatedPosition, int &minMapPosition, int &maxMapPosition, float extra)
{
	/*check which way it has rounded*/
	if ((int)(updatedPosition / 32) < updatedPosition / 32)
	{
		/*has been rounded down*/
		minMapPosition = ((updatedPosition - extra) / 32);//rounded down to nearest int
		maxMapPosition = ((updatedPosition - extra) / 32) + 1;//rounded up to nearest int
	}
	else
	{
		/*has been rounded up*/
		minMapPosition = ((updatedPosition - extra) / 32) - 1;//rounded down to nearest int
		maxMapPosition = ((updatedPosition - extra) / 32);//rounded up to nearest int
	}	
}


#include "collision.h"

/**************************************************************************************************************/

/*Constructs the collision object*/
Collision::Collision(Player * inputPlayer, MapLoader * inputMap, Background * inputBackground)
{
	player = inputPlayer;
	map = inputMap;
	background = inputBackground;
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

	/*the players position on the map grid*/
	int minPlayerMapX = 0;
	int maxPlayerMapX = 0;
	/*workout the map position depending on how it will round*/
	roundingCheck(updatedX, minPlayerMapX, maxPlayerMapX, background->getX());

	/*the players position on the map grid*/
	int minPlayerMapY = 0;
	int maxPlayerMapY = 0;
	/*workout the map position depending on how it will round*/
	roundingCheck(updatedY, minPlayerMapY, maxPlayerMapY, 0);

	/*if the player is going left*/
	if (player->getVelocityX() < 0 || map->getBlock(0)->getVelocity() > 0)
	{
		/*run the test for left*/
		leftTest(updatedX, minPlayerMapX, minPlayerMapY, maxPlayerMapY);
	}
	/*if the player is going right*/
	if (player->getVelocityX() > 0 || map->getBlock(0)->getVelocity() < 0)
	{
		/*run the test for left*/
		rightTest(updatedX, maxPlayerMapX, minPlayerMapY, maxPlayerMapY);
	}
}

/**************************************************************************************************************/

/*performs the tests for when the player goes left*/
void Collision::leftTest(float updatedPosition, int minCurrentAxis, int minOppositeAxis, int maxOppositeAxis)
{
	/*for the closest objects*/
	std::vector<int> closestIIndex;
	std::vector<int> closestJIndex;
	closestIIndex.resize(0);
	closestJIndex.resize(0);

	/*test only the tiles within the max and min tiles on the opposite axis*/
	for (int i = minOppositeAxis; i <= maxOppositeAxis; i++)
	{
		closestIIndex.resize(closestIIndex.size() + 1);
		closestJIndex.resize(closestJIndex.size() + 1);
		/*test only the tiles within the 0 and min tiles on the current axis*/
		for (int j = 0; j <= minCurrentAxis; j++)
		{
			/*check if the type of the tile*/
			switch (map->getType(i, j))
			{
			case 'X':
				/*empty tile so do nothing*/
				break;
			default:
				/*set as current closest*/
				closestIIndex[closestIIndex.size() - 1] = i;
				closestJIndex[closestJIndex.size() - 1] = j;
				break;
			}
		}
	}
	/*loop through the closest*/
	for (int i = 0; i < closestIIndex.size(); i++)
	{

		/*check if the type of the tile*/
		switch (map->getType(closestIIndex[i], closestJIndex[i]))
		{
		case 'X':
			/*empty tile so do nothing*/
			break;
		case 'B':
			/*check if its is interesting*/
			if (map->getBlock(map->getIndex(closestIIndex[i], closestJIndex[i]))->getX() + 32 >= updatedPosition)
			{
				/*block tile so do block collision action*/
				blockAction(map->getIndex(closestIIndex[i], closestJIndex[i]));
			}
			break;
		case 'G':
			/*check if its is interesting*/
			if (map->getGem(map->getIndex(closestIIndex[i], closestJIndex[i]))->getX() + 32 >= updatedPosition)
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

/**************************************************************************************************************/

/*performs the tests for when the player goes right*/
void Collision::rightTest(float updatedPosition, int maxCurrentAxis, int minOppositeAxis, int maxOppositeAxis)
{
	/*for the closest objects*/
	std::vector<int> closestIIndex;
	std::vector<int> closestJIndex;
	closestIIndex.resize(0);
	closestJIndex.resize(0);

	/*test only the tiles within the max and min tiles on the opposite axis*/
	for (int i = minOppositeAxis; i <= maxOppositeAxis; i++)
	{
		closestIIndex.resize(closestIIndex.size() + 1);
		closestJIndex.resize(closestJIndex.size() + 1);
		/*test only the tiles within the 0 and min tiles on the current axis*/
		for (int j = 54; j >= maxCurrentAxis; j--)
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

		/*check if the type of the tile*/
		switch (map->getType(closestIIndex[i], closestJIndex[i]))
		{
		case 'X':
			/*empty tile so do nothing*/
			break;
		case 'B':
			/*check if its is interesting*/
			if (map->getBlock(map->getIndex(closestIIndex[i], closestJIndex[i]))->getX() <= updatedPosition + 32)
			{
				/*block tile so do block collision action*/
				blockAction(map->getIndex(closestIIndex[i], closestJIndex[i]));
			}
			break;
		case 'G':
			/*check if its is interesting*/
			if (map->getGem(map->getIndex(closestIIndex[i], closestJIndex[i]))->getX() <= updatedPosition + 32)
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

/**************************************************************************************************************/

/*performs the tests for when the player goes up*/
void Collision::upTest(float updatedPosition, int minCurrentAxis, int minOppositeAxis, int maxOppositeAxis)
{
	/*for the closest objects*/
	std::vector<int> closestIIndex;
	std::vector<int> closestJIndex;
	closestIIndex.resize(0);
	closestJIndex.resize(0);

	/*test only the tiles within the max and min tiles on the opposite axis*/
	for (int i = minOppositeAxis; i <= maxOppositeAxis; i++)
	{
		closestIIndex.resize(closestIIndex.size() + 1);
		closestJIndex.resize(closestJIndex.size() + 1);
		/*test only the tiles within the 0 and min tiles on the current axis*/
		for (int j = 0; j <= minCurrentAxis; j++)
		{
			/*check if the type of the tile*/
			switch (map->getType(i, j))
			{
			case 'X':
				/*empty tile so do nothing*/
				break;
			default:
				/*set as current closest*/
				closestIIndex[closestIIndex.size() - 1] = i;
				closestJIndex[closestJIndex.size() - 1] = j;
				break;
			}
		}
	}
	/*loop through the closest*/
	for (int i = 0; i < closestIIndex.size(); i++)
	{

		/*check if the type of the tile*/
		switch (map->getType(closestIIndex[i], closestJIndex[i]))
		{
		case 'X':
			/*empty tile so do nothing*/
			break;
		case 'B':
			/*check if its is interesting*/
			if (map->getBlock(map->getIndex(closestIIndex[i], closestJIndex[i]))->getY() + 32 >= updatedPosition)
			{
				/*block tile so do block collision action*/
				blockAction(map->getIndex(closestIIndex[i], closestJIndex[i]));
			}
			break;
		case 'G':
			/*check if its is interesting*/
			if (map->getGem(map->getIndex(closestIIndex[i], closestJIndex[i]))->getY() + 32 >= updatedPosition)
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

/**************************************************************************************************************/

/*performs the tests for when the player goes down*/
void Collision::downTest(float updatedPosition, int maxCurrentAxis, int minOppositeAxis, int maxOppositeAxis)
{
	/*for the closest objects*/
	std::vector<int> closestIIndex;
	std::vector<int> closestJIndex;
	closestIIndex.resize(0);
	closestJIndex.resize(0);

	/*test only the tiles within the max and min tiles on the opposite axis*/
	for (int j = minOppositeAxis; j <= maxOppositeAxis; j++)
	{
		closestIIndex.resize(closestIIndex.size() + 1);
		closestJIndex.resize(closestJIndex.size() + 1);
		/*test only the tiles within the 0 and min tiles on the current axis*/
		for (int i = 14; i >= maxCurrentAxis; i--)
		{
			/*check if the type of the tile*/
			switch (map->getType(i, j))
			{
			case 'X':
				/*empty tile so do nothing*/
				break;
			default:
				/*set as current closest*/
				closestIIndex[closestIIndex.size() - 1] = i;
				closestJIndex[closestJIndex.size() - 1] = j;
				break;
			}
		}
	}
	/*loop through the closest*/
	for (int i = 0; i < closestIIndex.size(); i++)
	{

		/*check if the type of the tile*/
		switch (map->getType(closestIIndex[i], closestJIndex[i]))
		{
		case 'X':
			/*empty tile so do nothing*/
			break;
		case 'B':
			/*check if its is interesting*/
			if (map->getBlock(map->getIndex(closestIIndex[i], closestJIndex[i]))->getY() <= updatedPosition + 32)
			{
				/*block tile so do block collision action*/
				blockAction(map->getIndex(closestIIndex[i], closestJIndex[i]));
			}
			break;
		case 'G':
			/*check if its is interesting*/
			if (map->getGem(map->getIndex(closestIIndex[i], closestJIndex[i]))->getY() <= updatedPosition + 32)
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
	/*stop the player*/
	player->setVelocityX(0.0f);
	/*stop the scenery*/
	background->setVelocity(0.0f);
	/*loop for the number of blocks*/
	for (int i = 0; i < map->getNumberOfBlocks(); i++)
	{
		/*set the blocks velocity*/
		map->getBlock(i)->setVelocity(0.0f);
	}
	/*loop for the number of gems*/
	for (int i = 0; i < map->getNumberofGems(); i++)
	{
		/*set the gems velocity*/
		map->getGem(i)->setVelocity(0.0f);
	}
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


/*tmp to help with debugging*/
//tex->pushSpriteToScreen(tmp, (closestJIndex[i] * 32) + backgroundPos, (closestIIndex[i] * 32), 232, 94, 21, 21, 32, 32);
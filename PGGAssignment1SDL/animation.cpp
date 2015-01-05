#include "animation.h"

/**************************************************************************************************************/

/*Constructs the animation object*/
Animation::Animation(float inLength)
{
	/*initialise variables*/
	timer = 0.0f;
	timerLength = inLength;
}

/**************************************************************************************************************/

/*destructs the animation object*/
Animation::~Animation()
{
	
}

/**************************************************************************************************************/

/*updates the timer*/
void Animation::upadateTimer(float deltaTime)
{
	/*update the timer*/
	timer += deltaTime;
	/*if the timer is 1 then activate the animation*/
	if (timer >= timerLength)
	{
		/*reset the timer*/
		timer = 0.0f;
	}
}

/**************************************************************************************************************/

/*updates the animation*/
void Animation::upadateAnimation(char type, Entity * entity)
{
	/*if the timer is 0 then activate the animation*/
	if (timer == 0.0)
	{
		/*check the type of animation*/
		switch (type)
		{
		/*worm animation*/
		case 'W':
			wormAnimation(entity);
			break;
		/*end goal animation*/
		case 'E':
			endGoalAnimation(entity);
			break;
		}
	}
	/*check the type of animation*/
	switch (type)
	{
		/*snail animation*/
	case 'S':
		snailAnimation(entity);
		break;
	}
}

/**************************************************************************************************************/

/*performs the snail animation*/
void Animation::snailAnimation(Entity * entity)
{
	/*switch sprite*/
	if (entity->getSrcX() == 554 && entity->getSrcY() == 301)
	{
		entity->setSrcX(600);
		entity->setSrcY(301);
	}
	else
	{
		entity->setSrcX(554);
		entity->setSrcY(301);
	}
}

/**************************************************************************************************************/

/*performs the worm animation*/
void Animation::wormAnimation(Entity * entity)
{
	/*switch sprite*/
	if (entity->getSrcX() == 669 && entity->getSrcY() == 324)
	{
		entity->setSrcX(646);
		entity->setSrcY(531);
	}
	else
	{
		entity->setSrcX(669);
		entity->setSrcY(324);
	}
}

/**************************************************************************************************************/

/*performs the end goal animation*/
void Animation::endGoalAnimation(Entity * entity)
{
	/*switch sprite*/
	if (entity->getSrcX() == 232 && entity->getSrcY() == 232)
	{
		entity->setSrcX(232);
		entity->setSrcY(255);
	}
	else
	{
		entity->setSrcX(232);
		entity->setSrcY(232);
	}
}

/**************************************************************************************************************/

/*performs the gem animation*/
void Animation::gemAnimation(int type, Entity * entity)
{
	/*if the timer is 0 then activate the animation*/
	if (timer == 0.0)
	{
		/*switch sprite*/
		if (entity->getSrcX() == 370 + ((type)* 23) && entity->getSrcY() == 278)
		{
			entity->setSrcX((float)(347 + ((type)* 23)));
			entity->setSrcY(209);
		}
		else
		{
			entity->setSrcX((float)(370 + ((type)* 23)));
			entity->setSrcY(278);
		}
	}
}
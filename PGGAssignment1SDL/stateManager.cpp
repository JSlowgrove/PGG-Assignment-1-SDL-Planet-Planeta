#include "stateManager.h"
#include "gameState.h"
#include "menuState.h"

/**************************************************************************************************************/

/*Constructs the state manager object*/
StateManager::StateManager()
{
}

/**************************************************************************************************************/

/*De-constructs the state manager object*/
StateManager::~StateManager()
{
	/*loops thorough all of the states in the vector and deletes them all*/
	for (unsigned int i = 0; i < currentStates.size(); i++)
	{
		delete currentStates.at(i);
	}
}

/**************************************************************************************************************/

/*adds a state to the current states vector, for when we have multiple states at once*/
void StateManager::AddState(State* state)
{
	currentStates.push_back(state);
}

/**************************************************************************************************************/

/*changes the current state to the new state*/
void StateManager::ChangeState(State* state) 
{

	/*loops thorough all of the states in the vector and deletes them all*/
	for (unsigned int i = 0; i < currentStates.size(); i++)
	{
		delete currentStates.at(i);
	}
	
	/*clear the vector of current states*/
	currentStates.clear();
	/*add the new state that will be being run*/
	AddState(state);
}

/**************************************************************************************************************/

/*removes the last state that was added, for use when wanting to return to the previous state without resetting it*/
void StateManager::RemoveLastState()
{
	/*delete the last state in the vector*/
	delete currentStates.back();
	/*remove the last state from the vector*/
	currentStates.pop_back();
}

/**************************************************************************************************************/

/* SDL event handler function that will allow the equivalent SDL event handler function to run in the current State */
bool StateManager::HandleSDLEvents() 
{
	return currentStates.back()->HandleSDLEvents();
}

/**************************************************************************************************************/

/*update function that will allow the equivalent update function to run in the current state */
void StateManager::Update(float deltaTime) 
{
	/*updates the state on the top of the stack so the lower state are unaltered*/
	currentStates.back()->Update(deltaTime);
}

/**************************************************************************************************************/

/* draw function that will allow the equivalent draw function to run in the current state */
void StateManager::Draw() 
{
	/*loops through the running stacks and draws them all, with the latest added state on top*/
	for (unsigned int i = 0; i < currentStates.size(); i++)
	{
		currentStates.at(i)->Draw();
	}
}

/**************************************************************************************************************/

/*getter for the current states name */
std::string StateManager::getName()
{
	/*returns the name of the current state*/
	return currentStates.back()->GetStateName();
}
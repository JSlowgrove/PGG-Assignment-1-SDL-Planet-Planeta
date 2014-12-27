#include "state.h"

/**************************************************************************************************************/

/*Constructs the state object*/
State::State(StateManager * inStateManager, SDL_Renderer* inRenderer)
{
	/*sets the pointer to the state manager*/
	stateManager = inStateManager;
	/*sets the pointer to the renderer*/
	renderer = inRenderer;

}

/**************************************************************************************************************/

/*De-constructs the state object*/
State::~State() 
{
}

/**************************************************************************************************************/

/*returns the name of the state*/
std::string State::GetStateName() {
	/*returns the name*/
	return name;
}
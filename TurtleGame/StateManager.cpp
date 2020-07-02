#include "StateManager.hpp"

void StateManager::AddState(StateRef NewState, bool IsReplacing)
{
	this->IsAdding = true; //Adding to stack
	this->IsReplacing = IsReplacing; //Replace the current state or not
	this->NewState = std::move(NewState); //Moving the unique pointer to this pointer.
}
//------------------------------------------------------------------------//
void StateManager::RemoveState() //Removing the current state
{
	this->IsRemoving = true;
}
//------------------------------------------------------------------------//
void StateManager::StateChanges() //Make the changes
{
	if (this->IsRemoving && !this->States.empty()) //if there is a state running and we need to remove him
	{
		this->States.pop(); //removing the current state

		if (!this->States.empty())// If we have another state in the queue waiting
		{
			this->States.top()->Resume();
		}

		this->IsRemoving = false;
	}
//------------------------------------------------------------------------//
	if (this->IsAdding) //If we need to add state to stack
	{
		if (!this->States.empty())
		{
			if (this->IsReplacing) //If the new replace the current
			{
				this->States.pop();
			}
			else
			{
				this->States.top()->Pause(); //Stop the current from running
			}
		}

		this->States.push(std::move(this->NewState)); //insert the new state to stack
		this->States.top()->InitState();
		this->IsAdding = false;
	}

}
//------------------------------------------------------------------------//
StateRef& StateManager::getActiveState()
{
	return this->States.top();
}
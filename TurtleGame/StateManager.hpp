#pragma once
#include <memory>
#include <stack>
#include "State.hpp"

typedef std::unique_ptr<State> StateRef; //declaring unique_ptr to State.

//Class that will manage the states in some stack.
class StateManager
{
public:
	StateManager() {}; //Constructor
	~StateManager() {}; //Destructor

	void AddState(StateRef,bool IsReplacing=true); //Adding new state to stack
	void RemoveState(); //Removing State from stack
	void StateChanges(); 
	StateRef& getActiveState();
private:
	std::stack<StateRef> States;
	StateRef NewState;
	bool IsRemoving;
	bool IsAdding;
	bool IsReplacing;
};

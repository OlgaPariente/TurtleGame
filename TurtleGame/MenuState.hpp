#pragma once
#include "State.hpp"
#include <SFML/Graphics.hpp>
#include "Game.hpp"
namespace Olga 
{
	class MenuState : public State
	{
	public:
		MenuState(GameManagerPtr d); //Recieving shared pointer to the structure, copy the address of the ptr
		void InitState();
		void HandleInput(float);
		void Update(float fps);
		void Draw(int fps);
	private:
		GameManagerPtr GameManagPtr;
		sf::Sprite Background;	
		sf::Sprite PlayBtn;
	};
}





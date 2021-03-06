#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
namespace Olga {
	class LogoState :public State
	{
	public:
		LogoState(GameManagerPtr); //Recieving shared pointer to the structure, copy the address of the ptr
		void InitState();
		void HandleInput(float);
		void Update(float fps);
		void Draw(int);
	private:
		GameManagerPtr GameManagPtr;
		sf::Clock clock;
		sf::Sprite background;


	};
}
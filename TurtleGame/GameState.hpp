#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Graphics.hpp"
#include "Ground.hpp"
#include "Turtle.hpp"

namespace Olga
{
	class GameState : public State
	{

	public:
		GameState(GameManagerPtr); //Recieving shared pointer to the structure, copy the address of the ptr
		void InitState();
		void HandleInput();
		void Update(float fps);
		void Draw(float fps);
	private:
		GameManagerPtr GameManagPtr;
		sf::Clock clock;
		sf::Sprite background;
		Ground* ground;
		Turtle* turt;
	};

}

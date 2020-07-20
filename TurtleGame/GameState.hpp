#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Graphics.hpp"
#include "Ground.hpp"
#include "Turtle.hpp"
#include "Fruits.hpp"

namespace Olga
{
	class GameState : public State
	{

	public:
		GameState(GameManagerPtr); //Recieving shared pointer to the structure, copy the address of the ptr
		void InitState();
		void HandleInput(float fps);
		void Update(float fps);
		void Draw(int);
		void Drawback();
	private:
		GameManagerPtr GameManagPtr;
		sf::Clock clock;
		sf::Sprite background;
		sf::Sprite background2;
		Ground* ground1;
		Turtle* turt;
		Fruits* Fruit;
		sf::View view;
		sf::Vector2f posi;
	};

}

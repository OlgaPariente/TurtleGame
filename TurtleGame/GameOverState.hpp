#pragma once
#include "GameState.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MenuState.hpp"
#include <windows.h>
#include "Fruits.hpp"

namespace Olga
{

	class GameOverState : public State
	{

	public:
		GameOverState(GameManagerPtr,int); //Recieving shared pointer to the structure, copy the address of the ptr
		void InitState();
		void HandleInput(float fps);
		void Update(float fps);
		void Draw(int);
	private:
		GameManagerPtr GameManagPtr;
		int Score;
		sf::Sprite GameOverScreen;
	};
}
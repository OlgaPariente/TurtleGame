#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class LogoState :public State
{
public:
	LogoState(GameManagerPtr); //Recieving shared pointer to the structure, copy the address of the ptr
	void InitState();
	void HandleInput();
	void Update(float fps);
	void Draw(float fps);
private:
	GameManagerPtr GameManagPtr;
	sf::Clock clock;
	sf::Sprite background;


};

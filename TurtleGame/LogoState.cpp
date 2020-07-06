#include "LogoState.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
namespace Olga {
	LogoState::LogoState(GameManagerPtr p) : GameManagPtr(p) //copy pointer in constructor
	{
	}
	//---------------------------------------------------------------//
	void LogoState::InitState()
	{
		this->GameManagPtr->GraphicManag.LoadTexture("Logo State", "C:/Users/USER/Desktop/MyGame/Logo.png"); //Saving texture
		background.setTexture(this->GameManagPtr->GraphicManag.GetTexture("Logo State"));
	}
	//---------------------------------------------------------------//
	void LogoState::HandleInput()
	{
		sf::Event event; //event to be returned from pollevent. (sending by ref and saving the event in this var)

		while (this->GameManagPtr->WindowGame.pollEvent(event)) //return false when the event queue is empty. else true
		{
			if (sf::Event::Closed == event.type) //Request for closing the window
			{
				this->GameManagPtr->WindowGame.close();
			}
		}
	}
	//---------------------------------------------------------------//
	void LogoState::Update(float fps)
	{
		if (this->clock.getElapsedTime().asSeconds() > 3.0f) //switch to menu
		{
			//this->GameManagPtr->StateManag.AddState(StateRef(new Menu(GameManagPtr, true)));


		}
	}
	//---------------------------------------------------------------//

	void LogoState::Draw(float fps) //Drawing the state
	{
		this->GameManagPtr->WindowGame.clear(sf::Color::Red);
		this->GameManagPtr->WindowGame.draw(this->background);
		this->GameManagPtr->WindowGame.display();
	}
}
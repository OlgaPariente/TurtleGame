#include "GameState.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MenuState.hpp"
#include "GameOver.hpp"
#include <windows.h>
#include "Fruits.hpp"

namespace Olga {

	GameOver::GameOver(GameManagerPtr p)
	{
		this->GameManagPtr = p;
	}
	//------------------------------------------------------//
	void GameOver::InitState()
	{

		this->GameManagPtr->GraphicManag.LoadTexture("k", "MyGameImg/GameOverScreen.png"); //Saving texture
		this->GameOverScreen.setTexture(this->GameManagPtr->GraphicManag.GetTexture("k"));
		this->GameOverScreen.setPosition(90,-280);
		this->GameOverScreen.setScale(1.,1.3);
		this->view.setCenter(300,200);
	}
	//------------------------------------------------------//
	void GameOver::Draw(int k)
	{
		this->GameManagPtr->WindowGame.clear(sf::Color::White);
		this->GameManagPtr->WindowGame.setView(view);
		this->GameManagPtr->WindowGame.draw(this->GameOverScreen);
		this->GameManagPtr->WindowGame.display();
	}
	//------------------------------------------------------//
	void GameOver::HandleInput(float fps)
	{

	}
	//------------------------------------------------------//
	void GameOver::Update(float fps)
	{


	}
	//------------------------------------------------------//
}
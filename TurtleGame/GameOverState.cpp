#include "GameState.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MenuState.hpp"
#include "GameOverState.hpp"
#include <windows.h>
#include "Fruits.hpp"

namespace Olga {

	GameOverState::GameOverState(GameManagerPtr p, int Score)
	{
		this->GameManagPtr = p;
		this->Score = Score;
	}
	//------------------------------------------------------//
	void GameOverState::InitState()
	{
	
		//this->GameManagPtr->GraphicManag.LoadTexture("GOver", "MyGameImg/GameOverScreen.png");
		//this->GameOverScreen.setTexture(this->GameManagPtr->GraphicManag.GetTexture("GOver"));
	
	}
	//------------------------------------------------------//
	void GameOverState::Draw(int k)
	{
		this->GameManagPtr->WindowGame.clear(sf::Color::Green);
		this->GameManagPtr->WindowGame.draw(GameOverScreen);
	}
	//------------------------------------------------------//
	void GameOverState::HandleInput(float fps)
	{
		
	}
	//------------------------------------------------------//
	void GameOverState::Update(float fps)
	{
	
	
	}
	//------------------------------------------------------//
	










}
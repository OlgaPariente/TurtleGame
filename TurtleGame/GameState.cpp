#include "GameState.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MenuState.hpp"
#include <windows.h>
#include "Fruits.hpp"


namespace Olga {
	GameState::GameState(GameManagerPtr p) : GameManagPtr(p) //copy pointer in constructor
	{
	}
	//---------------------------------------------------------------//
	void GameState::InitState()
	{

		this->Score = 1;
		this->indxFruit = 0;
		//-----------------------Background---------------------------------------//
		this->GameManagPtr->GraphicManag.LoadTexture("back", "MyGameImg/background.jpg"); //Saving texture
		background.setTexture(this->GameManagPtr->GraphicManag.GetTexture("back"));
		this->GameManagPtr->GraphicManag.GetTexture("back").setRepeated(true);
		//this->background.setScale(1., 1.);
		
		background.setTextureRect(sf::IntRect(0,0,3072,468));
		
		//-----------------------------------------------------------------------//
		//-----------------------Ground-----------------------------------------//
		this->GameManagPtr->GraphicManag.LoadTexture("ground3", "MyGameImg/ground3.png"); //Saving texture
		this->GameManagPtr->GraphicManag.LoadTexture("ground2", "MyGameImg/ground2.png"); //Saving texture
		this->GameManagPtr->GraphicManag.LoadTexture("ground1", "MyGameImg/ground1.png"); //Saving texture
		this->ground1 = new Ground(GameManagPtr);
		ground1->CreateGround();
		//-----------------------------------------------------------------------//
		//-----------------------Turtle-----------------------------------------//
		this->GameManagPtr->GraphicManag.LoadTexture("Turtle", "MyGameImg/Turtle.png"); //Saving texture
		this->turt = new Turtle(GameManagPtr);
		//---------------------------------------------------------------------//
		//-------------------------Fruits:------------------------------------//
		this->GameManagPtr->GraphicManag.LoadTexture("Fruits", "MyGameImg/Fruits.png");
		this->GameManagPtr->GraphicManag.LoadTexture("Fruits2", "MyGameImg/FruitsTwo.png");

		this->Fruit = new Fruits(GameManagPtr);
		//---------------------------------------------------------------------//
		//-------------------------Scrolling background------------------------//
		view.reset(sf::FloatRect(0, 0, 697, 468)); //Screen

		view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); //Full screen rectangle
		this->posi.x = 697 / 2;
		this->posi.y = 468 / 2;
	}
	//---------------------------------------------------------------//
	void GameState::HandleInput(float fps)
	{

		sf::Event event; //event to be returned from pollevent. (sending by ref and saving the event in this var)

		while (this->GameManagPtr->WindowGame.pollEvent(event)) //return false when the event queue is empty. else true
		{
			if (sf::Event::Closed == event.type) //Request for closing the window
			{
				this->GameManagPtr->WindowGame.close();
			}
			//--------------------------------------------//
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //If we pressed * Right *
			{
				if (this->turt->GetTurtleState() == 3 || this->turt->GetTurtleState() == 2) //if the turtle is falling
				{
					this->turt->SetHorizontalFlag(1); //right pressed in turtle falling
				}
				this->turt->MoveTurtleSprite();
				this->turt->AnimateTurtleForward();
				this->turt->SetForwardState(1);
			}
			//--------------------------------------------//
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //If we pressed * up *
			{
				this->turt->SetTurtleState(2);
				this->turt->JumpUpdate(fps);
			}
			//--------------------------------------------//
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //If we pressed * Left *
			{

				//this->turt->ReturnTurtleSprite().move(-5, 0);
				this->turt->SetLocation(this->turt->ReturnLocation().x - 5, this->turt->ReturnLocation().y);
				this->turt->AnimateTurtleBack();
				this->turt->SetForwardState(0);
			}
		}
	}
	//---------------------------------------------------------------//
	void GameState::Update(float fps) //Automatically updates of the game
	{
		this->turt->JumpUpdate(fps);
		//std::cout << "x" << this->turt->ReturnLocation().x;
		//----------------------------------------------------------------------//
		//------------Erase the fruits that we collect-------------------------//
		if (this->turt->ReturnLocation().x == 220 && this->turt->GetTurtleState() == 1) //If the turtle touch the banana 
		{
			this->Score += 10;
			this->indxFruit = 1; //clear the banana from the screen
		}
		//-----------------------------------------//
		if (this->turt->ReturnLocation().x <= 600 && this->turt->ReturnLocation().x >= 500 && this->turt->ReturnLocation().y >= 180 && this->turt->ReturnLocation().y <= 300) //If the turtle touch the Coconut
		{
			this->Score += 10;
			this->indxFruit = 2; //clear the coconut from the screen
		}
		//-----------------------------------------//
		if (this->turt->ReturnLocation().x <= 810 && this->turt->ReturnLocation().x >= 800 && this->turt->GetTurtleState() == 1) //If the turtle touch the Ananas
		{
			this->Score += 10;
			this->indxFruit = 3; //clear the Ananas from the screen
		}
		//-----------------------------------------//
		if (this->turt->ReturnLocation().x <= 810 && this->turt->ReturnLocation().x >= 800 && this->turt->GetTurtleState() == 1) //If the turtle touch the Peach
		{
			this->Score += 10;
			this->indxFruit = 4; //clear the Peach from the screen
		}
		//-----------------------------------------//
		//if (this->turt->ReturnLocation().x >=3000)
		//{
			//this->GameManagPtr->StateManag.AddState(StateRef(new GameOverState(GameManagPtr,this->Score)), true);
		//}

	}
	//---------------------------------------------------------------//

	void GameState::Draw(int index) //Drawing the state
	{

		if (this->turt->ReturnTurtleSprite().getPosition().x + 80 > 697 / 2) //If the turtle go right and get closer to the end of the screen
		{
			this->posi.x = this->turt->ReturnTurtleSprite().getPosition().x + 80;
			
		}
		else
		{
			this->posi.x = 697 / 2;
			
		}

		view.setCenter(posi);
		this->GameManagPtr->WindowGame.setView(view);
		this->GameManagPtr->WindowGame.clear(sf::Color::Green);
		this->GameManagPtr->WindowGame.draw(this->background);
		this->ground1->DrawGround();
		this->Fruit->DrawFruit(indxFruit);
		this->turt->DrawTurtle();
		this->GameManagPtr->WindowGame.display();

	}
}
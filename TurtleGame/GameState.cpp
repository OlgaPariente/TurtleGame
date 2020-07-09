#include "GameState.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MenuState.hpp"
#include <windows.h>


namespace Olga {
	GameState::GameState(GameManagerPtr p) : GameManagPtr(p) //copy pointer in constructor
	{
	}
	//---------------------------------------------------------------//
	void GameState::InitState()
	{
		//-----------------------Background---------------------------------------//
		this->GameManagPtr->GraphicManag.LoadTexture("back", "C:/Users/USER/Desktop/MyGame/background.jpg"); //Saving texture
		background.setTexture(this->GameManagPtr->GraphicManag.GetTexture("back"));
		this->background.setScale(0.98, 1.);
		//-----------------------------------------------------------------------//
		//-----------------------Ground-----------------------------------------//
		this->GameManagPtr->GraphicManag.LoadTexture("ground3", "C:/Users/USER/Desktop/MyGame/ground3.png"); //Saving texture
		this->GameManagPtr->GraphicManag.LoadTexture("ground2", "C:/Users/USER/Desktop/MyGame/ground2.png"); //Saving texture
		this->GameManagPtr->GraphicManag.LoadTexture("ground1", "C:/Users/USER/Desktop/MyGame/ground1.png"); //Saving texture
		this->ground = new Ground(GameManagPtr);
		//-----------------------------------------------------------------------//
		//-----------------------Turtle-----------------------------------------//
		//this->GameManagPtr->GraphicManag.LoadTexture("Turtle1", "C:/Users/USER/Desktop/MyGame/Turtle1.png"); //Saving texture
		this->GameManagPtr->GraphicManag.LoadTexture("Turtle2", "C:/Users/USER/Desktop/MyGame/Turtle2.png"); //Saving texture
		this->GameManagPtr->GraphicManag.LoadTexture("Turtle3", "C:/Users/USER/Desktop/MyGame/Turtle3.png"); //Saving texture
		this->turt = new Turtle(GameManagPtr);
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //If we pressed * ----> *
			{
				
				this->turt->ReturnTurtleSprite().move(5,0);
				this->turt->SetLocation(this->turt->ReturnLocation().x + 5, this->turt->ReturnLocation().y);
				this->turt->AnimateTurtle(fps);
			}
			//--------------------------------------------//
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //If we pressed * up *
			{
				this->turt->SetTurtleState(2);
				this->turt->JumpUpdate(fps);
				this->turt->AnimateTurtle(fps);
			}
			//--------------------------------------------//
		}
	}
	//---------------------------------------------------------------//
	void GameState::Update(float fps) //Automatically updates of the game
	{
		//Choosing randomally ground type
		std::string name;

		/*for (int i = 0; i < 4; i++) 
		{
			switch (rand() % 3) {
			case 0: name = "ground1"; break;
			case 1: name = "ground2"; break;
			case 2: name = "ground3"; break;
			case 3: name = "none"; break;
			}
		}

		if(name!="none")this->ground->CreateGround(name);*/
		//Sleep(50);

		this->turt->JumpUpdate(fps);
		
	}
	//---------------------------------------------------------------//

	void GameState::Draw(float fps) //Drawing the state
	{
		this->GameManagPtr->WindowGame.clear(sf::Color::White);
		this->GameManagPtr->WindowGame.draw(this->background); //printing the background
		this->ground->DrawGround(); //printing the ground
		this->turt->DrawTurtle();
		this->GameManagPtr->WindowGame.display();
	}
}
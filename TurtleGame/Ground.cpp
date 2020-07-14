#include "Ground.hpp"
#include "Game.hpp"
#include "Graphics.hpp"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>

namespace Olga
{
//----------------------------------------------//
Ground::Ground(GameManagerPtr p) :ManagePtr(p)
{
	
}
//----------------------------------------------//
//Taking the texture to the sprite and set position of the ground
void Ground::CreateGround()
{
	
	//Choosing randomally ground type
	std::string name;
	for (int i = 0; i < 2; i++) //8 random grounds in the whole game 0,1,2
	{
		
		switch (rand() % 3) {
		case 0: name = "ground1"; break;
		case 1: name = "ground2"; break;
		case 2: name = "ground3"; break;
		}

		ground.setTexture(this->ManagePtr->GraphicManag.GetTexture(name)); //ground sprite
		int X = (rand() % 2000) + 100;
		ground.setPosition(X, 250);
		this->Grounds.push_back(ground);
	}
	
}
//---------------------------------------------//
void Ground::DrawGround()
{
	for (int i=0;i<this->Grounds.size();i++)
	{
		this->ManagePtr->WindowGame.draw(Grounds.at(i)); //drawing to screen the grounds
	}
}
}

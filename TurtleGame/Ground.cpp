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
	int Locax = 500;
	int Locay = 300;
	srand(time(NULL));
	for (int i = 0; i < 5; i++) //8 random grounds in the whole game 0,1,2
	{
		
		switch (rand() % 3) {
		case 0: name = "ground1"; break;
		case 1: name = "ground2"; break;
		case 2: name = "ground3"; break;
		}
		
		this->Grounds.push_back(ground);
		this->Grounds.at(i).setTexture(this->ManagePtr->GraphicManag.GetTexture(name)); //ground sprite
		this->Grounds.at(i).setPosition(Locax, Locay);
		Locax += 500;
		Locay -= 40;
	
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

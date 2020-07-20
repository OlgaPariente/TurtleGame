#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "Fruits.hpp"


namespace Olga
{
	Fruits::Fruits(GameManagerPtr P) :ManagePtr(P)
	{
		CreateFruit(31,8,100,83,220,320, "Fruits"); //Banana @
		CreateFruit(129, 8,90,85,600,250, "Fruits"); //Coconut @
		CreateFruit(373,267, 87, 98, 1100, 213, "Fruits"); //Strawberry @
		CreateFruit(201, 251, 86, 116, 800, 320, "Fruits"); //Ananas @
		CreateFruit(316, 135, 63, 105,1400, 150, "Fruits"); //Pinaplle @
		CreateFruit(287, 263, 73, 94,900, 100, "Fruits"); //Peach @
		CreateFruit(454, 269, 84, 85, 1250, 320, "Fruits"); //Orange @
		CreateFruit(378, 160, 111, 93,3000, 150, "Fruits"); //Orange slice
		CreateFruit(383, 40, 85, 89,3000, 320, "Fruits2"); //Apple @
		CreateFruit(271, 369, 86,102,2600,90, "Fruits2"); //Berry @
		CreateFruit(142, 131, 99, 123,2000, 320, "Fruits2"); //Berry2 @
	}


	void Fruits::CreateFruit(int left,int top,int width,int height,int X,int Y,std::string str)
	{
		this->MyFruit.setTexture(this->ManagePtr->GraphicManag.GetTexture(str));
		this->RectSprite.left = left;
		this->RectSprite.top = top;
		this->RectSprite.width = width;
		this->RectSprite.height = height;
		this->MyFruit.setTextureRect(RectSprite); //setting the spesific turtle to the sprite
		this->MyFruit.setScale(-0.7, 0.7);
		this->MyFruit.setPosition(X,Y);
		this->AllFruits.push_back(this->MyFruit);
	}
	//--------------------------------------------------------------------//
	void Fruits::DrawFruit()
	{
		for (int i=0;i<this->AllFruits.size();i++)
		{
			this->ManagePtr->WindowGame.draw(AllFruits.at(i));
		}
	}
}

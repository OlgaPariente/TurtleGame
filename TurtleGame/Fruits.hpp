#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Olga
{
	class Fruits
	{

	public:
		Fruits(GameManagerPtr);
		~Fruits();
		void CreateFruit(int,int,int,int,int,int,std::string);
		void DrawFruit(int);



	private:
		sf::Sprite MyFruit;
		std::vector<sf::Sprite> AllFruits;
		GameManagerPtr ManagePtr;
		sf::IntRect RectSprite;
	};

}
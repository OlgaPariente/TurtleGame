#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Olga
{
	class Ground
	{
	public:
		Ground(GameManagerPtr); //Constructor recieving the manager struct ptr
		void CreateGround(std::string); //Taking the texture, position push to vec
		void DrawGround(); //draw from vec

		std::vector<sf::Sprite>& GetSprites(); //returns address of vesctor sprites
		std::vector<sf::Sprite>& GetScoringSprites();//returns address of vesctor sprites
	private:

		GameManagerPtr ManagePtr;
		int GroundHeightY;
		int GroundX;
		sf::Sprite ground;
		std::vector<sf::Sprite>  GroundSprites;
		std::vector<sf::Sprite> Scoring;
	};
}


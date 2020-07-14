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
		void CreateGround(); //Taking the texture, position push to vec
		void DrawGround(); //draw sprites
		
	private:

		GameManagerPtr ManagePtr;
		int GroundHeightY;
		int GroundX;
		sf::Sprite ground;
		std::vector<sf::Sprite>Grounds;
	};
}


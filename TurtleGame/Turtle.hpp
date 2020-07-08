#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Olga
{
	class Turtle
	{
	public:
		Turtle(GameManagerPtr);
		~Turtle();

		void DrawTurtle(); //to screen
		void AnimateTurtle(float);
		void Update();

	private:
		unsigned int AnimationIterator;
		GameManagerPtr ManagePtr;
		sf::Sprite MyTurtSprite;
		std::vector<sf::Texture> AnimationTurtles;
		int TurtleState;
		sf::Vector2f Origin;
		sf::Clock clock;







	};

}

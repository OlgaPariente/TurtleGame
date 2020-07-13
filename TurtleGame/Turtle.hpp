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
		void AnimateTurtleForward();
		void AnimateTurtleBack();
		sf::Sprite& ReturnTurtleSprite();
		sf::Vector2f& ReturnLocation();
		void SetLocation(float x, float y);
		void JumpUpdate(float fps);
		int GetTurtleState();
		void SetTurtleState(int);
		void SetForwardState(int);
		int GetForwardState();
	private:
		int AnimationIteratorFlag;
		int forwardState;
		GameManagerPtr ManagePtr;
		std::vector<sf::Texture> AnimationTurtles;
		sf::Sprite MyTurtSprite;
		sf::Clock clock;
		sf::Vector2f CurrentLocation;
		float Gravity = 5.f;
		sf::Clock JumpClock;
		sf::Vector2f Velocity;
		int TurtleState = 1; //ground=1, jump=2, falling=3
		
	};
}

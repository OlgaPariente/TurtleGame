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
		void MoveTurtleSprite();
		sf::Sprite& ReturnTurtleSprite();
		sf::Vector2f& ReturnLocation();
		void SetLocation(float x, float y);
		void JumpUpdate(float fps);
		int GetTurtleState();
		void SetTurtleState(int);
		void SetForwardState(int);
		int GetForwardState();
		void SetHorizontalFlag(int);
		void CreateTurtle(int,int,int,int);
		void CreateTurtleJump(int, int, int, int);
	private:
		int AnimationIteratorFlag;
		int forwardState;
		GameManagerPtr ManagePtr;
		std::vector<sf::Sprite> AnimationTurtles;
		sf::Sprite MyTurtSprite;
		sf::Clock clock;
		sf::Vector2f CurrentLocation;
		float Gravity = 3.f;
		sf::Clock JumpClock;
		sf::Vector2f Velocity;
		int TurtleState = 1; //ground=1, jump=2, falling=3
		int HorizontalFlag=0;
		sf::IntRect rectSourceSprite;
		sf::Sprite TurtleJump;
	};
}

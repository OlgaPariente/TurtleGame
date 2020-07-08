#include "Turtle.hpp"
#include "Game.hpp"
#include "Graphics.hpp"
#include <SFML/Graphics.hpp>


namespace Olga
{

	Turtle::Turtle(GameManagerPtr p) :ManagePtr(p)
	{
		this->AnimationIterator = 0;

		//-------------Saving turtles in the vector:
		this->AnimationTurtles.push_back(this->ManagePtr->GraphicManag.GetTexture("Turtle1"));
		this->AnimationTurtles.push_back(this->ManagePtr->GraphicManag.GetTexture("Turtle2"));
		this->AnimationTurtles.push_back(this->ManagePtr->GraphicManag.GetTexture("Turtle3"));
		//-----------------------------Putting different turtle any time---------------------//
		this->MyTurtSprite.setTexture(this->AnimationTurtles.at(AnimationIterator));
		//----------------------------------------------------------------------------------//
		this->MyTurtSprite.setPosition(50,100);
		//----------------------------------------------------------------------------------//
		this->TurtleState = 1;
		//---------------------------------------------------------------------------------//
		this->Origin = sf::Vector2f(MyTurtSprite.getGlobalBounds().width / 2, MyTurtSprite.getGlobalBounds().height / 2);
		MyTurtSprite.setOrigin(Origin);
	}
	//--------------------------------------------------------------------------------------//
	void Turtle::DrawTurtle()
	{
			this->ManagePtr->WindowGame.draw(this->MyTurtSprite); //drawing to screen
	}
	//-------------------------------------------------------------------------------------//
	void Turtle::AnimateTurtle(float fps)
	{
		if (this->clock.getElapsedTime().asSeconds() > 0.4f/AnimationTurtles.size())
		{
			if (AnimationIterator < AnimationTurtles.size() - 1)
			{
				AnimationIterator++;
			}
			else
			{
				AnimationIterator = 0;
			}

			MyTurtSprite.setTexture(AnimationTurtles.at(AnimationIterator));
			clock.restart();

		}
	}




}

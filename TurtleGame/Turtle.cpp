#include "Turtle.hpp"
#include "Game.hpp"
#include "Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


namespace Olga
{

	Turtle::Turtle(GameManagerPtr p) :ManagePtr(p)
	{
		this->AnimationIteratorFlag = 0;

		//-------------Saving turtles in the vector:
		
		this->AnimationTurtles.push_back(this->ManagePtr->GraphicManag.GetTexture("Turtle2"));
		this->AnimationTurtles.push_back(this->ManagePtr->GraphicManag.GetTexture("Turtle3"));
		this->AnimationTurtles.push_back(this->ManagePtr->GraphicManag.GetTexture("Turtle2Reverse"));
		this->AnimationTurtles.push_back(this->ManagePtr->GraphicManag.GetTexture("Turtle3Reverse"));
		//-----------------------------Putting different turtle any time---------------------//
		this->MyTurtSprite.setTexture(this->AnimationTurtles.at(AnimationIteratorFlag)); //First turtle
		//----------------------------------------------------------------------------------//
		this->CurrentLocation.x = 15;
		this->CurrentLocation.y = 250;
		this->MyTurtSprite.setPosition(this->CurrentLocation);
		this->Velocity.x = 0;
		this->Velocity.y = 5;
		//----------------------------------------------------------------------------------//
	
		//---------------------------------------------------------------------------------//
	
	}
	//--------------------------------------------------------------------------------------//
	void Turtle::DrawTurtle()
	{
			this->ManagePtr->WindowGame.draw(this->MyTurtSprite); //drawing to screen
	}
	//-------------------------------------------------------------------------------------//
	void Turtle::AnimateTurtleForward() //flag=0,1,2,3
	{
		
		if (this->clock.getElapsedTime().asSeconds() > 0.6f/AnimationTurtles.size()) //Each frame we have the same time
		{
			if (AnimationIteratorFlag < 1) //if we have more frames in the array
			{
				AnimationIteratorFlag++; //Moving to the next frame
			}
			else
			{
				AnimationIteratorFlag = 0; //else we go back to the first turtle
			}

			MyTurtSprite.setTexture(AnimationTurtles.at(AnimationIteratorFlag));
			clock.restart(); //for each frame new clock measure

		}
	}
	//-----------------------------------------------------------------------------------//
	void Turtle::AnimateTurtleBack() //flag=0,1,2,3
	{
		
		if (this->clock.getElapsedTime().asSeconds() > 0.6f / AnimationTurtles.size()) //Each frame we have the same time
		{
			if (AnimationIteratorFlag < 3) //if we have more frames in the array
			{
				AnimationIteratorFlag++; //Moving to the next frame
			}
			else
			{
				AnimationIteratorFlag = 2; //else we go back to the first turtle
			}

			MyTurtSprite.setTexture(AnimationTurtles.at(AnimationIteratorFlag));
			clock.restart(); //for each frame new clock measure

		}
	}
	//-----------------------------------------------------------------------------------//
	sf::Sprite& Turtle::ReturnTurtleSprite()
	{
		return this->MyTurtSprite;

	}
	//----------------------------------------------------------------------------------//
	sf::Vector2f& Turtle::ReturnLocation()
	{
		return this->CurrentLocation;
	}
	//---------------------------------------------------------------------------------//
	void Turtle::SetLocation(float x, float y)
	{
		this->CurrentLocation.x = x;
		this->CurrentLocation.y = y;
	}
	//--------------------------------------------------------------------------------//
	void Turtle::JumpUpdate(float fps)
	{	
		if (this->TurtleState == 2 && this->CurrentLocation.y==250)//Jump pressed first time
		{
			//std::cout << "pos:\n" << this->MyTurtSprite.getPosition().y; //250
			this->Velocity.y = -40;
			this->MyTurtSprite.move(0, Velocity.y); //going to 40 neg
			this->CurrentLocation.y = this->CurrentLocation.y - this->Velocity.y;
		}
		
		if (this->JumpClock.getElapsedTime().asSeconds() > 0.40 && this->TurtleState==2)
		{
			this->JumpClock.restart();
			this->TurtleState = 3;//falling
		}
			
		if (this->TurtleState == 3) //falling now
		{
		
			this->MyTurtSprite.move(0,this->Velocity.y); //going to 50 positive
			if (this->MyTurtSprite.getPosition().y < 250) //If im up
			{
				this->Velocity.y += Gravity; //starting falling down
		
			}
			else // if im on the ground
			{
				//this->MyTurtSprite.setPosition(MyTurtSprite.getPosition().x, 250);
				
				this->CurrentLocation.x = MyTurtSprite.getPosition().x;
				this->CurrentLocation.y = 250;
				this->MyTurtSprite.setPosition(MyTurtSprite.getPosition().x,250);
				this->TurtleState = 1;//ground
			}
		
		
		}
		
	}
	//--------------------------------------------------------------------------------//
	int Turtle::GetTurtleState()
	{
		return this->TurtleState;
	
	}
	//--------------------------------------------------------------------------------//
	void Turtle::SetTurtleState(int state)
	{
		 this->TurtleState=state;

	}
	//--------------------------------------------------------------------------------//
	void Turtle::SetForwardState(int s)
	{
		this->forwardState = s;
	
	}

	//--------------------------------------------------------------------------------//
	int Turtle::GetForwardState()
	{
		return this->forwardState;

	}
}

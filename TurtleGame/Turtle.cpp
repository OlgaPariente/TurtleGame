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
		this->TurtleState = 1; //ground
		//-------------Saving turtles in the vector:
		this->CurrentLocation.x = 100;
		this->CurrentLocation.y = 250;
		//-------------------------First Turtle--------------------------------//
		this->CreateTurtle(2325, 1700, 213, 293);
		//-------------------------Second Turtle--------------------------------//
		this->CreateTurtle(2764, 1700, 213, 293);
		//-------------------------Third Turtle--------------------------------//
		this->CreateTurtle(2977,1700,213,293);
		//-------------------------Jump Turtle--------------------------------//
		this->CreateTurtleJump(1729, 2000, 230, 330);
		//-----------------------------Putting different turtle any time---------------------//
		this->MyTurtSprite=this->AnimationTurtles.at(AnimationIteratorFlag); //First turtle
		//----------------------------------------------------------------------------------//
		this->Velocity.x = 0;
		this->Velocity.y = 5;
		//----------------------------------------------------------------------------------//
	}
	//--------------------------------------------------------------------------------------//
	void Turtle::CreateTurtle(int left, int top,int width, int height)
	{
		this->MyTurtSprite.setTexture(this->ManagePtr->GraphicManag.GetTexture("Turtle")); //Turtles sheet
		this->rectSourceSprite.left = left;
		this->rectSourceSprite.top = top;
		this->rectSourceSprite.width = width;
		this->rectSourceSprite.height = height;
		this->MyTurtSprite.setTextureRect(rectSourceSprite); //setting the spesific turtle to the sprite
		this->MyTurtSprite.setScale(-0.4, 0.4);
		this->MyTurtSprite.setPosition(CurrentLocation);
		this->AnimationTurtles.push_back(this->MyTurtSprite);
	}
	//--------------------------------------------------------------------------------------//
	void Turtle::CreateTurtleJump(int left, int top, int width, int height)
	{
		this->TurtleJump.setTexture(this->ManagePtr->GraphicManag.GetTexture("Turtle")); //Turtles sheet
		this->rectSourceSprite.left = left;
		this->rectSourceSprite.top = top;
		this->rectSourceSprite.width = width;
		this->rectSourceSprite.height = height;
		this->TurtleJump.setTextureRect(rectSourceSprite); //setting the spesific turtle to the sprite
		this->TurtleJump.setScale(-0.4, 0.4);
		this->TurtleJump.setPosition(CurrentLocation);
	
	}
	//--------------------------------------------------------------------------------------//
	void Turtle::DrawTurtle()
	{
		if (this->TurtleState == 1)
		{
			AnimateTurtleForward();
			this->ManagePtr->WindowGame.draw(MyTurtSprite); //drawing to screen
		}
			else this->ManagePtr->WindowGame.draw(this->TurtleJump);
			
	}
	//-------------------------------------------------------------------------------------//
	void Turtle::AnimateTurtleForward() //flag=0,1,2
	{
		
		if (this->clock.getElapsedTime().asSeconds() > 0.4f/AnimationTurtles.size()) //Each frame we have the same time
		{
			if (AnimationIteratorFlag <2) //if we have more frames in the array
			{
				AnimationIteratorFlag++; //Moving to the next frame
			}
			else
			{
				AnimationIteratorFlag = 0; //else we go back to the first turtle
			}

			this->MyTurtSprite=this->AnimationTurtles.at(AnimationIteratorFlag);
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

			MyTurtSprite=AnimationTurtles.at(AnimationIteratorFlag);
			clock.restart(); //for each frame new clock measure

		}
	}
	//-----------------------------------------------------------------------------------//
	void Turtle::MoveTurtleSprite()
	{
		for (int i = 0; i < AnimationTurtles.size(); i++)
		{
			AnimationTurtles.at(i).move(2,0);
		}
		TurtleJump.move(2,0);
		SetLocation(CurrentLocation.x+=2,CurrentLocation.y);

	}
	//----------------------------------------------------------------------------------//
	sf::Sprite& Turtle::ReturnTurtleSprite()
	{
		return AnimationTurtles.at(AnimationIteratorFlag);
	}
	//--------------------------------------------------------------------------------//
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
		//std::cout << "x:" << this->CurrentLocation.x;

		if (this->TurtleState == 2 && this->CurrentLocation.y==250)//Jump pressed first time
		{
			Velocity.x = 10;
			this->Velocity.y = -200;
			//---------------------------------------------------//
			for (int i = 0; i < AnimationTurtles.size(); i++)
			{
				AnimationTurtles.at(i).move(0,Velocity.y);
			}
			this->TurtleJump.move(0, Velocity.y);
			//---------------------------------------------------//
			this->CurrentLocation.y = this->CurrentLocation.y - 200;
			this->Velocity.y = 0;
			
		}
		
		if (this->JumpClock.getElapsedTime().asSeconds() > 1.0 && this->TurtleState==2)//when starts falling
		{
			this->JumpClock.restart();
			this->TurtleState = 3;//falling
			
		}
			
		if (this->TurtleState == 3) //falling now
		{
			
			//----------------X part:------------------------------------------//
			if (this->HorizontalFlag == 1) //Falling horizontally
			{
				for (int i = 0; i < AnimationTurtles.size(); i++)
				{
					AnimationTurtles.at(i).move(Velocity.x,0);
				}
				this->TurtleJump.move(Velocity.x,0);
				//std::cout << "x:" << this->CurrentLocation.x;
				//--------------------------------------------------------------//
				this->Velocity.x += 4.2; //starting falling down
				//----------------Y part:-------------------------------------//
				for (int i = 0; i < AnimationTurtles.size(); i++)
				{
					AnimationTurtles.at(i).move(0, Velocity.y);
				}
				this->TurtleJump.move(0, Velocity.y);
				//--------------------------------------------------//
				if (this->TurtleJump.getPosition().y < 200) //If im up
				{
					this->Velocity.y += 5; //starting falling down
				}
				else // if im on the ground
				{
					this->CurrentLocation.x = TurtleJump.getPosition().x;
					if ((this->CurrentLocation.x <= 600 && this->CurrentLocation.x >= 500) || (this->CurrentLocation.x <= 1200 && this->CurrentLocation.x >= 1000)
						|| (this->CurrentLocation.x <= 1700 && this->CurrentLocation.x >= 1500) || (this->CurrentLocation.x <= 2200 && this->CurrentLocation.x >= 2000)) //platform
					{
						
						this->CurrentLocation.y = 200;
					}
					else this->CurrentLocation.y = 250;

					TurtleJump.setPosition(TurtleJump.getPosition().x, this->CurrentLocation.y);
					HorizontalFlag = 0;
					this->TurtleState = 1;//ground
				}
			}
			//----------------Y part:------------------------------------------//
			else
			{
				//std::cout << "x" << this->TurtleJump.getPosition().x;
				for (int i = 0; i < AnimationTurtles.size(); i++) //Jump up
				{
					AnimationTurtles.at(i).move(0, Velocity.y);
				}
				this->TurtleJump.move(0, Velocity.y);
				
				//--------------------------------------------------//
				if (this->TurtleJump.getPosition().y < 200) //If im up
				{
					this->Velocity.y += 5; //starting falling down
				}
				else // if im on the ground
				{
					this->CurrentLocation.x = TurtleJump.getPosition().x;
					if ((this->CurrentLocation.x <= 600 && this->CurrentLocation.x >= 500) || (this->CurrentLocation.x <= 1200 && this->CurrentLocation.x >= 1000)
						|| (this->CurrentLocation.x <= 1700 && this->CurrentLocation.x >= 1500) || (this->CurrentLocation.x <= 2200 && this->CurrentLocation.x >= 2000)) //platform					{
					{	
						//std::cout << "x:" << this->CurrentLocation.x;
						this->CurrentLocation.y =200;
					}
					else this->CurrentLocation.y = 250;
				
					TurtleJump.setPosition(TurtleJump.getPosition().x, CurrentLocation.y);
					for (int i = 0; i < AnimationTurtles.size(); i++)
					{
						AnimationTurtles.at(i).setPosition(TurtleJump.getPosition().x, this->CurrentLocation.y);
					}
					this->TurtleState = 1;//ground
				}

			}
		} //Falling
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
	//--------------------------------------------------------------------------------//
	void Turtle::SetHorizontalFlag(int flag)
	{
		this->HorizontalFlag = flag;
	}
}

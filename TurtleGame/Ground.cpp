#include "Ground.hpp"
#include "Game.hpp"
#include "Graphics.hpp"
#include <SFML/Graphics.hpp>

namespace Olga
{
//----------------------------------------------//
Ground::Ground(GameManagerPtr p) :ManagePtr(p)
{
	
}
//----------------------------------------------//
//Taking the texture to the sprite and set position of the ground
void Ground::CreateGround(std::string str)
{
	ground.setTexture(this->ManagePtr->GraphicManag.GetTexture(str));
	ground.setPosition(100,300);
	GroundSprites.push_back(ground);
}
//---------------------------------------------//
void Ground::DrawGround()
{
	for (int i=0;i< GroundSprites.size();i++)
	{
		this->ManagePtr->WindowGame.draw(GroundSprites.at(i)); //drawing to screen the grounds
	}
}





}

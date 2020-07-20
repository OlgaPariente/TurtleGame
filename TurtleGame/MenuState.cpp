#include "MenuState.hpp"
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include <sstream>
#include "GameState.hpp"

namespace Olga {

	MenuState::MenuState(GameManagerPtr p) : GameManagPtr(p)
	{
	
	}
	//------------------------------------------------------------//
	void MenuState::InitState()
	{
		//Loading the textures to the map
		this->GameManagPtr->GraphicManag.LoadTexture("Menu Background", "MyGameImg/menu.png");
		this->GameManagPtr->GraphicManag.LoadTexture("Play Btn", "MyGameImg/play.png");
		//Setting the textures to the variables
		this->Background.setTexture(this->GameManagPtr->GraphicManag.GetTexture("Menu Background"));
		this->PlayBtn.setTexture(this->GameManagPtr->GraphicManag.GetTexture("Play Btn"));
		this->PlayBtn.setScale(1.2,1.);

		PlayBtn.setPosition((697 / 2) - (PlayBtn.getGlobalBounds().width / 2), (550 / 2) - (PlayBtn.getGlobalBounds().height / 2));
	}
	//------------------------------------------------------------//
	void MenuState::HandleInput(float fps)
	{
		sf::Event event;
		while (this->GameManagPtr->WindowGame.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) //If we click on close btn
			{
				this->GameManagPtr->WindowGame.close();
			}
			//--------------------------------------------//
			if (this->GameManagPtr->GraphicManag.IsItemClicked(this->PlayBtn,sf::Mouse::Left,this->GameManagPtr->WindowGame)) //If start clicked
			{
				this->GameManagPtr->StateManag.AddState(StateRef(new GameState(GameManagPtr)), true);
			}
			//-------------------------------------------//
		}
	}

	//------------------------------------------------------------//

	void MenuState::Update(float) //Nothing to implement but pure virtual
	{
	
	}
	//------------------------------------------------------------//
	void MenuState::Draw(int)
	{
		this->GameManagPtr->WindowGame.clear(sf::Color::Green);
		this->GameManagPtr->WindowGame.draw(this->Background);
		this->GameManagPtr->WindowGame.draw(this->PlayBtn);
		this->GameManagPtr->WindowGame.display();
	}
}
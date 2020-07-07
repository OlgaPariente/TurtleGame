#include "MenuState.hpp"
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include <sstream>
#include "LogoState.hpp"

namespace Olga {

	MenuState::MenuState(GameManagerPtr p) : GameManagPtr(p)
	{
	
	}
	//------------------------------------------------------------//
	void MenuState::InitState()
	{
		//Loading the textures to the map
		this->GameManagPtr->GraphicManag.LoadTexture("Menu Background", "C:/Users/USER/Desktop/MyGame/menu.png");
		this->GameManagPtr->GraphicManag.LoadTexture("Play Btn", "C:/Users/USER/Desktop/MyGame/play.png");
		//Setting the textures to the variables
		this->Background.setTexture(this->GameManagPtr->GraphicManag.GetTexture("Menu Background"));
		this->PlayBtn.setTexture(this->GameManagPtr->GraphicManag.GetTexture("Play Btn"));
		this->PlayBtn.setScale(1.2,1.);

		PlayBtn.setPosition((697 / 2) - (PlayBtn.getGlobalBounds().width / 2), (550 / 2) - (PlayBtn.getGlobalBounds().height / 2));
	}
	//------------------------------------------------------------//
	void MenuState::HandleInput()
	{
		sf::Event event;
		while (this->GameManagPtr->WindowGame.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) //If we click on close btn
			{
				this->GameManagPtr->WindowGame.close();
			}
			if (this->GameManagPtr->GraphicManag.IsItemClicked(this->PlayBtn,sf::Mouse::Left,this->GameManagPtr->WindowGame))
			{
				this->GameManagPtr->StateManag.AddState(StateRef(new LogoState(GameManagPtr)), true);
			}
		}
	}

	//------------------------------------------------------------//

	void MenuState::Update(float) //Nothing to implement but pure virtual
	{
	
	}
	//------------------------------------------------------------//
	void MenuState::Draw(float)
	{
		this->GameManagPtr->WindowGame.clear(sf::Color::Green);
		this->GameManagPtr->WindowGame.draw(this->Background);
		this->GameManagPtr->WindowGame.draw(this->PlayBtn);
		this->GameManagPtr->WindowGame.display();
	}
}
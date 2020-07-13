#include "Game.hpp"
#include "LogoState.hpp"
#include <Windows.h>

namespace Olga {
	Game::Game(int width, int height, std::string title)
	{
		GamePtr->WindowGame.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		GamePtr->StateManag.AddState(StateRef(new LogoState(this->GamePtr)));
		this->Run();
	}

	void Game::Run() //Run the game, frames
	{

		float NewTime;
		float FrameTime;
		float CurrentTime = this->clock.getElapsedTime().asSeconds();
		float Accumulator = 0.0f;
		int counter = 0;

		while (this->GamePtr->WindowGame.isOpen())
		{
			this->GamePtr->StateManag.StateChanges();
			NewTime = this->clock.getElapsedTime().asSeconds();
			FrameTime = NewTime - CurrentTime;

			if (FrameTime > 0.25f)
			{
				FrameTime = 0.25f;
			}

			CurrentTime = NewTime;
			Accumulator += FrameTime;

			while (Accumulator >= fps)
			{
				this->GamePtr->StateManag.getActiveState()->HandleInput(fps);
				this->GamePtr->StateManag.getActiveState()->Update(fps);
				Accumulator -= fps;
			}
			
			this->GamePtr->StateManag.getActiveState()->Draw(counter); //drawing state
			
		}
	}
}
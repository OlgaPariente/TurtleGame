#pragma once
#include "StateManager.hpp"
#include "Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace Olga
{
	typedef struct ManagerStruct
	{
		sf::RenderWindow WindowGame;
		StateManager StateManag;
		Graphics GraphicManag;

	};

	typedef std::shared_ptr<ManagerStruct> GameManagerPtr; //points to the struct

	class Game
	{
	public:
		Game(int width, int height, std::string title);
	private:
		float fps = 1.0f / 60.0f;
		sf::Clock clock;
		GameManagerPtr GamePtr = std::make_shared<ManagerStruct>();
		void Run();
	};
}

#pragma once
#include <map>
#include <SFML/Graphics.hpp>


namespace Olga {
	class Graphics
	{
	public:
		Graphics() {};
		~Graphics() {};
		std::map<std::string, sf::Texture> TexturesMap;
		void LoadTexture(std::string Name, std::string FileName); //Load texture from file
		sf::Texture& GetTexture(std::string Name); //return refernce to texture from the map

		void LoadFont(std::string Name, std::string FileName); //Load Font from file
		sf::Font& GetFont(std::string Name); //return refernce to texture from the map

		bool IsItemClicked(sf::Sprite, sf::Mouse::Button, sf::RenderWindow&); //checking if we clicked on screen button
		//bool IsRightArrowClicked(sf::Sprite,sf::RenderWindow&);
		//sf::Vector2i GetMousePosition(sf::RenderWindow& window); //Returning vector (x,y) with location
	private:
		//std::map<std::string, sf::Texture> TexturesMap;
		std::map<std::string, sf::Font> FontMap;
	};
}
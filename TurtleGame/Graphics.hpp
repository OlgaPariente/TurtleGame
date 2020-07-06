#pragma once
#include <map>
#include <SFML/Graphics.hpp>
namespace Olga {
	class Graphics
	{
	public:
		Graphics() {};
		~Graphics() {};

		void LoadTexture(std::string Name, std::string FileName); //Load texture from file
		sf::Texture& GetTexture(std::string Name); //return refernce to texture from the map

		void LoadFont(std::string Name, std::string FileName); //Load Font from file
		sf::Font& GetFont(std::string Name); //return refernce to texture from the map
	private:
		std::map<std::string, sf::Texture> TexturesMap;
		std::map<std::string, sf::Font> FontMap;
	};
}
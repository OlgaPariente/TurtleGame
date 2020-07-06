#include <SFML/Graphics.hpp>
#include "Graphics.hpp"

void Graphics::LoadTexture(std::string name, std::string file)
{
	sf::Texture t;
	if (t.loadFromFile(file))
	{
		this->TexturesMap[name] = t;
	}
}
//--------------------------------------------------------------//
sf::Texture& Graphics::GetTexture(std::string name)
{
	return this->TexturesMap.at(name);
}
//--------------------------------------------------------------//
void Graphics::LoadFont(std::string name, std::string file)
{
	sf::Font f;
	if (f.loadFromFile(file))
	{
		this->FontMap[name] = f;
	}
}
//--------------------------------------------------------------//
sf::Font& Graphics::GetFont(std::string name)
{
	return this->FontMap.at(name);
}
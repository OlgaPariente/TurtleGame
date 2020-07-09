#include <SFML/Graphics.hpp>
#include "Graphics.hpp"


namespace Olga {
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
	//--------------------------------------------------------------//
	bool Graphics::IsItemClicked(sf::Sprite Item, sf::Mouse::Button b, sf::RenderWindow& w) //PlayB,Left mouse B, window
	{
		if (sf::Mouse::isButtonPressed(b)) //we mouse was pressed left Btn
		{
			sf::IntRect PlayB(Item.getPosition().x, Item.getPosition().y, Item.getGlobalBounds().width, Item.getGlobalBounds().height);//creating rect for btn representation
			if (PlayB.contains(sf::Mouse::getPosition(w))) //If the rectangle contains the mouse position point than was pressed
			{
				return true;
			}
		}
		return false;

	}
	//--------------------------------------------------------------//

	//--------------------------------------------------------------//
	/*sf::Vector2i GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}*/
}
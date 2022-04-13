#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class MainMenu
{
public:
	MainMenu(sf::RenderWindow* window, sf::Vector2u center);
public:
	// returns winType code
	WINCODE Render();
private:
	sf::RenderWindow* window;
	sf::Vector2u center;

	// BACKGROUND OF MAIN MENU
	sf::Sprite mainMenuSprite;
	sf::Texture mainMenuTexture;

	// NEW GAME BUTTON
	sf::Sprite newGameButtonSprite;
	sf::Texture newGameButtonTexture;

	// LOAD GAME BUTTON
	sf::Sprite loadGameButtonSprite;
	sf::Texture loadGameButtonTexture;

	// SETTINGS BUTTON
	sf::Sprite settingsButtonSprite;
	sf::Texture settingsButtonTexture;

	// EXIT BUTTON
	sf::Sprite exitButtonSprite;
	sf::Texture exitButtonTexture;
};


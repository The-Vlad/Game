#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class App
{
public:
	App(float width, float height, std::string title);

	int Go();
private:
	sf::RenderWindow* window;

	// Central coordinates in window
	sf::Vector2u center;
	
	// WinCode is for switching windows: Game Window, Menu etc
	WINCODE winCode;
};


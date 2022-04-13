#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <vector>
#include "Entity.h"

class GameWindow
{
public:
	GameWindow(sf::RenderWindow* window, sf::Vector2u center);
public:
	void Render();
	WINCODE RunLogic();
private:
	void spawn_en( ENTITY_TYPE en_type, sf::Vector2f coords = sf::Vector2f(0.0f, 0.0f));
	void remove_en( int ID );
private:
	sf::RenderWindow* window;
	sf::Vector2u center;
	std::vector<Entity*> en_vect;
	WINCODE winCode;
	Entity* Player1;
	sf::Clock clock;
	float time;
};


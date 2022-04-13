#pragma once
#include "SFML/Graphics.hpp"
#include "Macros.h"

class Entity {
public:
	Entity( ENTITY_TYPE en_type, sf::Vector2f coords, int ID );
public:
	int ID;
	sf::Sprite sprite;
	unsigned short health_points;
	short reputation;
	// next fields may be variables of char type [edited: MACRO DEFINITIONS]
	unsigned short type_of_weapon;
	unsigned short fraction;
	float velocity;
private:
	ENTITY_TYPE en_type;
	sf::Texture texture;
	bool unbreakable;
};
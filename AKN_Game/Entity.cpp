#include "Entity.h"

Entity::Entity(ENTITY_TYPE en_type, sf::Vector2f coords, int ID)
{
	this->en_type = en_type;
	this->ID = ID;
	health_points = 100;
	reputation = 100;
	velocity = 0.5f;

	switch (en_type)
	{
	case PLAYER:
		texture.loadFromFile( "Textures/player.png" );
		sprite.setTexture( texture );
		sprite.setPosition(coords);
		unbreakable = false;
		break;
	case BLOCK:
		texture.loadFromFile( "Textures/block.png" );
		sprite.setTexture( texture );
		sprite.setPosition( coords );
		unbreakable = false;
		break;
	case BRICKS:
		texture.loadFromFile( "Textures/bricks.png" );
		sprite.setTexture( texture );
		sprite.setPosition( coords );
		unbreakable = false;
		break;
	case ENEMY:
		texture.loadFromFile( "Textures/enemy.png" );
		sprite.setTexture( texture );
		sprite.setPosition( coords );
		unbreakable = false;
		break;
	case GRASS:
		texture.loadFromFile( "Textures/grass.png" );
		sprite.setTexture( texture );
		sprite.setPosition( coords );
		unbreakable = true;
		break;
	case METAL:
		texture.loadFromFile( "Textures/metal.png" );
		sprite.setTexture( texture );
		sprite.setPosition( coords );
		unbreakable = false;
		break;
	case PATH:
		texture.loadFromFile( "Textures/path.png" );
		sprite.setTexture( texture );
		sprite.setPosition( coords );
		unbreakable = true;
		break;
	case WATER:
		texture.loadFromFile( "Textures/water.png" );
		sprite.setTexture( texture );
		sprite.setPosition( coords );
		unbreakable = true;
		break;
	default:
		Entity::~Entity();
		break;
	}
}

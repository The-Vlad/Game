#include "GameWindow.h"

GameWindow::GameWindow( sf::RenderWindow* window, sf::Vector2u center )
{
	this->window = window;
	this->center = center;
	winCode = GAMEWND;

	Player1 = new Entity( PLAYER, sf::Vector2f( center ), NULL );
}

void GameWindow::Render()
{
	// activate the window's context
	window->setActive( true );

	// for drawing multiple entities
	int iterator;

	while (window->isOpen())
	{
		switch (winCode)
		{
		case MENUWND:
			window->setActive( false );
			return;
		case PAUSEWND:
			// will be not the window but will be drawn as a object
			break;
		case SETTINGSWND:
			// will be not the window but will be drawn as a object
			break;
		case LOADWND:
			// will be not the window but will be drawn as a object
			break;
		case EXITWND:
			window->close();
			break;
		default:
			break;
		}

		window->clear();
		window->draw( Player1->sprite );
		for (iterator = 0; iterator < en_vect.size(); iterator++)
		{
			window->draw( en_vect[iterator]->sprite );
		}
		window->display();
	}
}

WINCODE GameWindow::RunLogic()
{
	while (window->isOpen() && winCode > 0)
	{
		sf::Event event;
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		while (window->pollEvent( event ))
		{
			if (event.type == sf::Event::Closed)
			{
				winCode = EXITWND;
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Enter)
				{
					spawn_en( BRICKS, sf::Vector2f( center ) );
				}
				if (event.key.code == sf::Keyboard::BackSpace)
				{
					remove_en( en_vect.size() - 1 );
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					winCode = MENUWND;
					return winCode;
				}
				if (event.key.code == sf::Keyboard::Num0)
				{
					winCode = EXITWND;
				}
			}

			if (event.type == sf::Event::MouseMoved)
			{
				
			}
		}

		if (sf::Keyboard::isKeyPressed( sf::Keyboard::W )) Player1->sprite.move( 0.0f, -Player1->velocity * time );
		if (sf::Keyboard::isKeyPressed( sf::Keyboard::A )) Player1->sprite.move( -Player1->velocity * time, 0.0f );
		if (sf::Keyboard::isKeyPressed( sf::Keyboard::S )) Player1->sprite.move( 0.0f, Player1->velocity * time );
		if (sf::Keyboard::isKeyPressed( sf::Keyboard::D )) Player1->sprite.move( Player1->velocity * time, 0.0f );		
	}

	//return MENUWND;
	return winCode;
}

void GameWindow::spawn_en( ENTITY_TYPE en_type, sf::Vector2f coords )
{
	en_vect.push_back( new Entity( en_type, coords, en_vect.size() ) );
}

void GameWindow::remove_en( int ID )
{
	if (en_vect.size() > 0) en_vect.erase( en_vect.begin() + ID );
}
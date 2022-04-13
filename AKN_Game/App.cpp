#include "App.h"
#include "MainMenu.h"
#include "GameWindow.h"
#include <SFML/System.hpp>

App::App(float width, float height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	center.x = window->getSize().x / 2;
	center.y = window->getSize().y / 2;

	winCode = MENUWND;
}

int App::Go()
{
	while (winCode > 0)
	{
		switch (winCode)
		{
		case GAMEWND:
		{
			window->setActive( false );

			GameWindow GW(window, center);
			sf::Thread thread( &GameWindow::Render, &GW);

			// Render() and RunLogic()
			thread.launch();
			winCode = GW.RunLogic();
			break;
		}
		case MENUWND:
		{
			window->setActive( false );
			MainMenu MM(window, center);
			winCode = MM.Render();
			break;
		}
		/*case PAUSEWND:
		* will be not the window but will be drawn as a object
			break;*/
		/*case SETTINGSWND:
		* will be not the window but will be drawn as a object
			break;*/
		/*case LOADWND:
		* will be not the window but will be drawn as a object
			break;*/
		case EXITWND:
			return EXITWND;
		case ERRORWND:
			return ERRORWND;
		default:
			return DEFAULTWNDCODE;
		}
	}
	return DEFAULTWNDCODE;
}

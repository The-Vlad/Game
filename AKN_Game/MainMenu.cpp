#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, sf::Vector2u center)
{
	this->window = window;
	this->center = center;

	mainMenuTexture.loadFromFile("Textures/mainMenuBackground.png");
	mainMenuSprite.setTexture(mainMenuTexture);
	mainMenuSprite.setPosition(
		(float)center.x - mainMenuSprite.getGlobalBounds().width / 2,
		(float)center.y - mainMenuSprite.getGlobalBounds().height / 2);

	// Initialising New Game Button and variables with the size of button
	newGameButtonTexture.loadFromFile("Textures/newGameButton.png");
	newGameButtonSprite.setTexture(newGameButtonTexture);
	float ButtonHeight = newGameButtonSprite.getGlobalBounds().height;
	float LeftCoord = (float)center.x - newGameButtonSprite.getGlobalBounds().width / 2;
	float TopCoord = center.y - mainMenuSprite.getGlobalBounds().height / 2;
	float FreeSpaceY = (mainMenuSprite.getGlobalBounds().height - 4 * ButtonHeight) / 5;
	newGameButtonSprite.setPosition(LeftCoord, TopCoord + FreeSpaceY);

	loadGameButtonTexture.loadFromFile("Textures/loadGameButton.png");
	loadGameButtonSprite.setTexture(loadGameButtonTexture);
	loadGameButtonSprite.setPosition(LeftCoord,TopCoord + 2 * FreeSpaceY + ButtonHeight);

	settingsButtonTexture.loadFromFile("Textures/settingsButton.png");
	settingsButtonSprite.setTexture(settingsButtonTexture);
	settingsButtonSprite.setPosition( LeftCoord, TopCoord + 3 * FreeSpaceY + 2 * ButtonHeight);

	exitButtonTexture.loadFromFile("Textures/exitButton.png");
	exitButtonSprite.setTexture(exitButtonTexture);
	exitButtonSprite.setPosition(LeftCoord, TopCoord + 4 * FreeSpaceY + 3 * ButtonHeight);
}

WINCODE MainMenu::Render()
{
	// activate the window's context
	window->setActive( true );

	while (window->isOpen()) {
		sf::Event event;

		while (window->pollEvent( event ))
		{
			if (event.type == sf::Event::Closed) window->close();
			if (event.type == sf::Event::KeyReleased)
			{
				// "CLICK-BUTTONS" LOGIC
				if (event.key.code == sf::Keyboard::Num1)
				{
					// Call function startNewGame()
					return GAMEWND;
				}
			}
		}
		window->clear();
		window->draw(mainMenuSprite);
		window->draw(newGameButtonSprite);
		window->draw(loadGameButtonSprite);
		window->draw(settingsButtonSprite);
		window->draw(exitButtonSprite);
		window->display();

		// "CLICK-BUTTONS" LOGIC
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
		//{
		//	// Call function startNewGame()
		//	return GAMEWND;
		//}
		//if (newGameButtonSprite.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition()) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		//	// Call function startNewGame()
		//	return GAMEWND;
		//}
		//if (loadGameButtonSprite.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		//	// Call function loadGame()
		//	// no return LOADWND;
		//}
		//if (settingsButtonSprite.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		//	// Call function settings()
		//	// no return SETTINGSWND;
		//}
		//if (exitButtonSprite.getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		//	// Call function exit
		//	return EXITWND;
		//}
	}

	return EXITWND;
}

#include "PauseMenu.h"

void showPauseMenu(sf::RenderWindow& window) {
	sf::Sprite pauseMenuSprite;
	sf::Texture pauseMenuTexture;

	pauseMenuTexture.loadFromFile("Textures/menuBackground.png");
	pauseMenuSprite.setTexture(pauseMenuTexture);
	pauseMenuSprite.setPosition(20.f, 20.f);

	sf::Sprite newGameButtonSprite;
	sf::Texture newGameButtonTexture;

	newGameButtonTexture.loadFromFile("Textures/newGameButton.png");
	newGameButtonSprite.setTexture(newGameButtonTexture);
	newGameButtonSprite.setPosition(70.f, 50.f);


	while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			//Sleep(250); // Delay the siganl to work out
			break;
		}

		window.clear();
		window.draw(pauseMenuSprite);
		window.draw(newGameButtonSprite);
		window.display();
	}
}
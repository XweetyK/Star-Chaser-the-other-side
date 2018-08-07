#include "Game.h"
Game::Game(){
	gameState = MENU;
	init();
}
Game::~Game(){
}
void Game::init() {
	window.create(VideoMode(800, 500), "Star Chaser 2: The Other Side");
	select = 1;
	update();
}
void Game::update() {
	switch (gameState)
	{
	case MENU:
		menu();
		break;
	case PLAY:
		play();
		break;
	case SCORES:
		score();
		break;
	case RESULT:
		result();
	case EXIT:
		window.close();
		break;
	}
}
void Game::menu() {
	menuBg.loadFromFile("../Assets/BG/bg.png");
	mBG.setTexture(menuBg);
	menuLogo.loadFromFile("../Assets/menu/logo.png");
	mLogo.setTexture(menuLogo);
	mLogo.setPosition(210, 80);
	menuSelect1.loadFromFile("../Assets/menu/button0.png");
	menuSelect2.loadFromFile("../Assets/menu/button1.png");
	menuSelect3.loadFromFile("../Assets/menu/button2.png");
	mSelect.setPosition(295, 400);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		switch (select)
		{
		case 1:
			mSelect.setTexture(menuSelect1);
			break;
		case 2:
			mSelect.setTexture(menuSelect2);
			break;
		case 3:
			mSelect.setTexture(menuSelect3);
			break;
		}
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case Keyboard::Left:
				if (select>1)
					select--;
				break;
			case Keyboard::Right:
				if (select<3)
					select++;
				break;
			case Keyboard::Space:
				switch (select)
				{
				case 1:
					gameState = PLAY;
					break;
				case 2:
					gameState = SCORES;
					break;
				case 3:
					gameState = EXIT;
					break;
				}
			}
			break;
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			switch (select)
			{
			case 1:
				gameState = PLAY;
				break;
			case 2:
				gameState = SCORES;
				break;
			case 3:
				gameState = EXIT;
				break;
			}
		}
		cout << gameState;
		window.clear();
		window.draw(mBG);
		window.draw(mLogo);
		window.draw(mSelect);
		window.display();
		sleep(seconds(0.1f));
		update();
	}
}

void Game::play() {
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
}
void Game::result() {}
void Game::score() {}
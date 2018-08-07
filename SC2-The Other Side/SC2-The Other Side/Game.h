#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Game{
	enum GameState {MENU, PLAY, RESULT, SCORES, EXIT};
	GameState gameState;
	RenderWindow window;
	Font font;
	//Menu---------------
	Texture menuBg;
	Texture menuLogo;
	Texture menuSelect1;
	Texture menuSelect2;
	Texture menuSelect3;
	Sprite mBG;
	Sprite mLogo;
	Sprite mSelect;
	int select;
	//-------------------
	
public:
	Game();
	~Game();
	void init();
	void update();
	void menu();
	void play();
	void result();
	void score();
};
#endif

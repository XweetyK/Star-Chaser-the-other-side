#ifndef GAME_H
#define GAME_H
#define DSL1_CANT 3
#define DSL3_CANT 5
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Game{
	enum GameState {MENU, PLAY, SELECT, RESULT, SCORES, EXIT};
	GameState gameState;
	RenderWindow window;
	Font font;
	bool _init;
	//Menu---------------
	Texture menuBg;
	Texture menuLogo;
	Texture menuSelect1;
	Texture menuSelect2;
	Texture menuSelect3;
	Sprite mBG;
	Sprite mLogo;
	Sprite mSelect;
	int selectM;
	//SELECT-------------
	Texture selectCH1;
	Texture selectCH2;
	Texture selectCH3;
	Texture selectCS1;
	Texture selectCS2;
	Texture selectCS3;
	Texture selectCS1s;
	Texture selectCS2s;
	Texture selectCS3s;
	Texture selectBack;
	Texture selectBackH;
	Sprite sCHead1;
	Sprite sCHead2;
	Sprite sCHead3;
	Sprite sCStats1;
	Sprite sCStats2;
	Sprite sCStats3;
	Sprite sBack;
	int selectC;
	enum CharaSelect { DS1, DS2, DS3 };
	CharaSelect charaSelect;
	//PLAY---------------
	Texture playBG;
	Texture playScore;
	Texture playLife;
	Texture playHead1;
	Texture playHead2;
	Texture playHead3;
	Texture playHead1L;
	Texture playHead2L;
	Texture playHead3L;
	Texture playDB1;
	Texture playDB2;
	Texture playDB3;
	Texture playChara1;
	Texture playChara2;
	Texture playChara3;
	Sprite pBG;
	Sprite pDB;
	Sprite pScore;
	Sprite pLife;
	Sprite DS1L[DSL1_CANT];
	Sprite DS2L;
	Sprite DS3L[DSL3_CANT];
	Sprite pChara1;
	Sprite pChara2;
	Sprite pChara3;
	int playSpeed;
	int bgpos;
	int playCPos_X;
	int playCPos_Y;
	
public:
	Game();
	~Game();
	void init();
	void update();
	void menu();
	void select();
	void play();
	void result();
	void score();
};
#endif

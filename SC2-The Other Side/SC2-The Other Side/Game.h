#ifndef GAME_H
#define GAME_H
#define DSL1_CANT 3
#define DSL3_CANT 5
#define BOX_CANT 5
#define GEM_CANT 10
#define BOX_MAX 450
#define BOX_MIN 75
#define GEM_MAX 450
#define GEM_MIN 80
#define DS1_L 3
#define DS2_L 1
#define DS3_L 5
#define NODE_CANT 10
#include <iostream>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SSM/Scoreboard.h>
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
	Texture playBox1;
	Texture playBox2;
	Texture playBox3;
	Texture playBox4;
	Texture playBox5;
	Texture playGem;
	Sprite pBG1;
	Sprite pBG2;
	Sprite pDB;
	Sprite pScore;
	Sprite pLife;
	Sprite DS1L[DSL1_CANT];
	Sprite DS2L;
	Sprite DS3L[DSL3_CANT];
	Sprite pChara1;
	Sprite pChara2;
	Sprite pChara3;
	struct PGem {
		Sprite sprite;
		Vector2f pos;
	};
	struct PBox{
		Sprite sprite;
		Vector2f pos;
	};
	PBox pBox[BOX_CANT];
	PGem pGem[GEM_CANT];
	Text scoreText;
	ostringstream ss;
	int playSpeed;
	int bgpos;
	int bgpos2;
	int playCPos_X;
	int playCPos_Y;
	int box_Y;
	int gem_y;
	int DS1Life;
	int DS2Life;
	int DS3Life;
	int playScoreCant;
	//SCORE-------------------
	Texture scoreBG;
	Sprite sBG;
	Scoreboard scoreBoard;
	Nodo node[NODE_CANT];
	Text scoreName[NODE_CANT];
	Text scorePoint[NODE_CANT];
	//RESULT------------------
	Texture resBG;
	Sprite rBG;
	Text resScore;
	char name[3];
	
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

#include "Game.h"
Game::Game(){
	gameState = MENU;
	charaSelect = DS1;
	_init = false;
	init();
}
Game::~Game(){
}
void Game::init() {
	if (!_init) {
		window.create(VideoMode(800, 500), "Star Chaser 2: The Other Side");
		_init = true;
	}
	selectM = 1;
	selectC = 1;
	bgpos = 0;
	bgpos2 = 1520;
	playCPos_X = 20;
	playCPos_Y = 250;
	srand(time(0));
	box_Y = 0;
	DS1Life = DS1_L;
	DS2Life = DS2_L;
	DS3Life = DS3_L;
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
	case SELECT:
		select();
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
	mSelect.setTexture(menuSelect1);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		switch (selectM)
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
				if (selectM>1)
					selectM--;
				break;
			case Keyboard::Right:
				if (selectM<3)
					selectM++;
				break;
			}
			break;
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			switch (selectM)
			{
			case 1:
				gameState = SELECT;
				break;
			case 2:
				gameState = SCORES;
				break;
			case 3:
				gameState = EXIT;
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			gameState = EXIT;
		}
		cout << selectM;
		window.clear();
		window.draw(mBG);
		window.draw(mLogo);
		window.draw(mSelect);
		window.display();
		sf::sleep(seconds(0.1f));
		update();
	}
}
void Game::select() {
	menuBg.loadFromFile("../Assets/BG/bg.png");
	mBG.setTexture(menuBg);
	selectCH1.loadFromFile("../Assets/Menu/head0.png");
	selectCH2.loadFromFile("../Assets/Menu/head1.png");
	selectCH3.loadFromFile("../Assets/Menu/head2.png");
	selectCS1.loadFromFile("../Assets/Menu/data0.png");
	selectCS2.loadFromFile("../Assets/Menu/data1.png");
	selectCS3.loadFromFile("../Assets/Menu/data2.png");
	selectCS1s.loadFromFile("../Assets/Menu/dataS0.png");
	selectCS2s.loadFromFile("../Assets/Menu/dataS1.png");
	selectCS3s.loadFromFile("../Assets/Menu/dataS2.png");
	selectBack.loadFromFile("../Assets/Menu/button3.png");
	selectBackH.loadFromFile("../Assets/Menu/button3S.png");
	sCHead1.setTexture(selectCH1);
	sCHead2.setTexture(selectCH2);
	sCHead3.setTexture(selectCH3);
	sCStats1.setTexture(selectCS1);
	sCStats2.setTexture(selectCS2);
	sCStats3.setTexture(selectCS3);
	sBack.setTexture(selectBack);
	sCHead1.setPosition(100, 100);
	sCHead2.setPosition(340, 100);
	sCHead3.setPosition(570, 100);
	sCStats1.setPosition(65, 300);
	sCStats2.setPosition(305, 300);
	sCStats3.setPosition(535, 300);
	sBack.setPosition(577, 425);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		switch (selectC)
		{
		case 1:
			sCStats1.setTexture(selectCS1s);
			sCStats2.setTexture(selectCS2);
			sCStats3.setTexture(selectCS3);
			sBack.setTexture(selectBack);
			break;
		case 2:
			sCStats1.setTexture(selectCS1);
			sCStats2.setTexture(selectCS2s);
			sCStats3.setTexture(selectCS3);
			sBack.setTexture(selectBack);
			break;
		case 3:
			sCStats1.setTexture(selectCS1);
			sCStats2.setTexture(selectCS2);
			sCStats3.setTexture(selectCS3s);
			sBack.setTexture(selectBack);
			break;
		case 4:
			sCStats1.setTexture(selectCS1);
			sCStats2.setTexture(selectCS2);
			sCStats3.setTexture(selectCS3);
			sBack.setTexture(selectBackH);
			break;
		}
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case Keyboard::Left:
				if (selectC > 1)
					selectC--;
				break;
			case Keyboard::Right:
				if (selectC < 4)
					selectC++;
				break;
			case Keyboard::Down:
					selectC=4;
				break;
			case Keyboard::Up:
				selectC = 1;
				break;
			}
			break;
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			switch (selectC)
			{
			case 1:
				charaSelect = DS1;
				gameState = PLAY;
				break;
			case 2:
				charaSelect = DS2;
				gameState = PLAY;
				break;
			case 3:
				charaSelect = DS3;
				gameState = PLAY;
				break;
			case 4:
				gameState = MENU;
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			gameState = MENU;
		}
		window.clear();
		window.draw(mBG);
		window.draw(sCHead1);
		window.draw(sCHead2);
		window.draw(sCHead3);
		window.draw(sCStats1);
		window.draw(sCStats2);
		window.draw(sCStats3);
		window.draw(sBack);
		window.display();
		sf::sleep(seconds(0.1f));
		update();
	}
}
void Game::play() {
	//ASSETS--------------------------------------------------------------------------------------------
	{
		playBG.loadFromFile("../Assets/BG/bgGame.png");
		playDB1.loadFromFile("../Assets/Menu/dataBar0.png");
		playDB2.loadFromFile("../Assets/Menu/dataBar1.png");
		playDB3.loadFromFile("../Assets/Menu/dataBar2.png");
		playScore.loadFromFile("../Assets/Menu/button5.png");
		playLife.loadFromFile("../Assets/Menu/button4.png");
		playHead1.loadFromFile("../Assets/Menu/icon0.png");
		playHead2.loadFromFile("../Assets/Menu/icon1.png");
		playHead3.loadFromFile("../Assets/Menu/icon2.png");
		playHead1L.loadFromFile("../Assets/Menu/icon0L.png");
		playHead2L.loadFromFile("../Assets/Menu/icon1L.png");
		playHead3L.loadFromFile("../Assets/Menu/icon2L.png");
		playChara1.loadFromFile("../Assets/BG/Level/DS-1.png");
		playChara2.loadFromFile("../Assets/BG/Level/DS-2.png");
		playChara3.loadFromFile("../Assets/BG/Level/DS-3.png");
		playBox1.loadFromFile("../Assets/BG/Items/obs0.png");
		playBox2.loadFromFile("../Assets/BG/Items/obs1.png");
		playBox3.loadFromFile("../Assets/BG/Items/obs2.png");
		playBox4.loadFromFile("../Assets/BG/Items/obs3.png");
		playBox5.loadFromFile("../Assets/BG/Items/obs5.png");
		pChara1.setTexture(playChara1);
		pChara2.setTexture(playChara2);
		pChara3.setTexture(playChara3);
		pBG1.setTexture(playBG);
		pBG2.setTexture(playBG);
		pDB.setTexture(playDB1);
		pScore.setTexture(playScore);
		pLife.setTexture(playLife);
		pBox[0].sprite.setTexture(playBox1);
		pBox[1].sprite.setTexture(playBox2);
		pBox[2].sprite.setTexture(playBox3);
		pBox[3].sprite.setTexture(playBox4);
		pBox[4].sprite.setTexture(playBox5);
		pScore.setPosition(300, 10);
		pLife.setPosition(-30, 10);
		pBG2.setPosition(bgpos2, 0);
		pChara1.setPosition(playCPos_X, playCPos_Y);
		pChara2.setPosition(playCPos_X, playCPos_Y);
		pChara3.setPosition(playCPos_X, playCPos_Y);
		for (int i = 0; i < BOX_CANT; i++) {
			box_Y = ((rand() % (BOX_MIN - BOX_MAX + 1) + BOX_MIN));
			pBox[i].sprite.setPosition((i * 160) + 820, box_Y);
		}
	}
	switch (charaSelect)
	{
	case DS1:
		pDB.setTexture(playDB1);
		for (int i = 0; i < DSL1_CANT; i++){
			DS1L[i].setTexture(playHead1);}
		for (int i = 0; i < DSL1_CANT; i++) {
			DS1L[i].setPosition((i * 40) + 120, 8);}
		playSpeed = 10;
		break;
	case DS2:
		pDB.setTexture(playDB2);
		DS2L.setTexture(playHead2);
		DS2L.setPosition(120, 8);
		playSpeed = 20;
		break;
	case DS3:
		pDB.setTexture(playDB3);
		for (int i = 0; i < DSL3_CANT; i++){
			DS3L[i].setTexture(playHead3);}
		for (int i = 0; i < DSL3_CANT; i++) {
			DS3L[i].setPosition((i * 40) + 120, 8);}
		playSpeed = 5;
		break;
	}
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//CONTROL---------------------------------------------------------------------------------------
		{
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				if (playCPos_Y > 75)
					playCPos_Y -= 1 * playSpeed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				if (charaSelect == DS3) {
					if (playCPos_Y < 360)
						playCPos_Y += 1 * playSpeed;
				}
				else {
					if (playCPos_Y < 420)
						playCPos_Y += 1 * playSpeed;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				if (playCPos_X > 10)
					playCPos_X -= 1 * playSpeed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				if (playCPos_X < 700)
					playCPos_X += 1 * playSpeed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				gameState = SELECT;
				init();
			}
		}
		//UPDATE POS------------------------------------------------------------------------------------
		{
			switch (charaSelect)
			{
			case DS1:
				pChara1.setPosition(playCPos_X, playCPos_Y);
				break;
			case DS2:
				pChara2.setPosition(playCPos_X, playCPos_Y);
				break;
			case DS3:
				pChara3.setPosition(playCPos_X, playCPos_Y);
				break;
			}
		}
		//BACKGROUND------------------------------------------------------------------------------------
		{
			pBG1.setPosition(bgpos, 0);
			pBG2.setPosition(bgpos2, 0);
			bgpos -= 1 * playSpeed;
			bgpos2 -= 1 * playSpeed;
			if (bgpos < -1530) { bgpos = bgpos2 + 1520; }
			if (bgpos2 < -1530) { bgpos2 = bgpos + 1520; }
		}
		//OBSTACLES-------------------------------------------------------------------------------------
		{
			
			for (int i = 0; i < BOX_CANT; i++) { //why do I need this? idk, but without it the game don't work
				pBox[i].pos = pBox[i].sprite.getPosition();
			}
			for (int i = 0; i < BOX_CANT; i++) {
				pBox[i].sprite.move(-playSpeed, 0);
				if (pBox[i].pos.x < -50) {
					box_Y = ((rand() % (BOX_MIN - BOX_MAX + 1) + BOX_MIN));
					pBox[i].sprite.setPosition(900, box_Y);
				}
			}
		}
		//LIFE------------------------------------------------------------------------------------------
		switch (charaSelect)
		{
		case DS1:
			switch (DS1Life)
			{
			case 2:
				DS1L[2].setTexture(playHead1L);
				break;
			case 1:
				DS1L[2].setTexture(playHead1L);
				DS1L[1].setTexture(playHead1L);
				break;
			case 0:
				result();
				break;
			}
			break;
		case DS3:
			switch (DS3Life)
			{
			case 4:
				DS3L[4].setTexture(playHead3L);
				break;
			case 3:
				DS3L[4].setTexture(playHead3L);
				DS3L[3].setTexture(playHead3L);
				break;
			case 2:
				DS3L[4].setTexture(playHead3L);
				DS3L[3].setTexture(playHead3L);
				DS3L[2].setTexture(playHead3L);
				break;
			case 1:
				DS3L[4].setTexture(playHead3L);
				DS3L[3].setTexture(playHead3L);
				DS3L[2].setTexture(playHead3L);
				DS3L[1].setTexture(playHead3L);
				break;
			case 0:
				result();
				break;
			}
			break;
		}
		window.clear();
		window.draw(pBG1);
		window.draw(pBG2);
		window.draw(pDB);
		window.draw(pScore);
		window.draw(pLife);
		for (int i = 0; i < BOX_CANT; i++) {
			window.draw(pBox[i].sprite);
		}
		switch (charaSelect)
		{
		case DS1:
			for (int i = 0; i < DSL1_CANT; i++) {
				window.draw(DS1L[i]);}
			window.draw(pChara1);
			break;
		case DS2:
			window.draw(DS2L);
			window.draw(pChara2);
			break;
		case DS3:
			for (int i = 0; i < DSL3_CANT; i++) {
				window.draw(DS3L[i]);}
			window.draw(pChara3);
			break;
		}			
		window.display();
		sf::sleep(seconds(0.05f));
	}
}
void Game::result() {}
void Game::score() {}
using namespace std;
#define INIT 3
#define NODOL 10
struct Nodo {
	char name[INIT]{ 'A','A','A' };
	int score = 000000000;
};
class Scoreboard
{
private:
	Nodo sBoard[NODOL];
	Nodo _nodo;
	Nodo aux;
public:
	Scoreboard();
	~Scoreboard();
	void insertScr(char _name[INIT], int _score);
	void sortScr();
	Nodo showScr(int _pos);
	void resetScr();
};


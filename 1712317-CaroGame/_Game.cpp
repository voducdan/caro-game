#include"_Game.h"
_Game::_Game(int size, int left, int top) {
	_b = new _Board(size, left, top);
	_loop = _turn = true;
	_command = -1;
	_x = left;
	_y = top;
}
_Game::~_Game() {
	delete _b;
}
int _Game::getCommand() {
	return _command;
}
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard() {
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue() {
	_Common::gotoXY(_b->getLeft()+5, _b->getTop()-2);
	cout << "Do you want to play again? ";
	_Common::gotoXY(_b->getLeft()+5, _b->getTop() - 1);
	waitKeyBoard();
	return getCommand();
}

void _Game::startGame() {
	system("cls");
	_b->resetData();
	_b->drawBoard();
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
}
void _Game::exitGame() {
	//system("cls");
	_loop = false;
}
char _Game::askSave() {
	_Common::gotoXY(_b->getLeft() + 5, _b->getTop() - 1);
	cout << "Save this game for the next visit, press l to save";
	waitKeyBoard();
	return getCommand();
}
void _Game::saveGame() {
	char name[30];
	_Common::gotoXY(_b->getLeft() + _b->getSize()*4+2, _b->getTop()+2);
	cout << "Your name: ";
	gets_s(name);
	char fileName[40] = ".txt";
	strcat(name, fileName);
	FILE *f = fopen(name, "w");
	for (int i = 0; i < _b->getSize(); i++) {
		for (int j = 0; j < _b->getSize(); j++)
		{
			fprintf(f, "%d",_b->getCheckAt(i,j));
			fprintf(f,"\n");
		}
	}
	fclose(f);
}

void _Game::loadGame() {
	char name[30];
	_b->drawBoard();
	cout << "Your name: ";
	gets_s(name);
	char fileName[10] = ".txt";
	strcat(name, fileName);
	cout << name << endl;
	FILE *f = fopen(name, "rb");
	if (f == NULL) { cout << "Khong tim thay ten nguoi choi"; return; }
	int j = 0;
	int a;
	for (int i = 0; i < _b->getSize(); i++)
	{
		while(!feof(f)&&j<_b->getSize()){
			fscanf(f, "%d", &a);
			_Common::gotoXY(_b->getXAt(i, j), _b->getYAt(i, j));
			_b->setCheckAt(i, j, a);
			processCheckBoard();
			j++;
		}
	}
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
}
bool _Game::processCheckBoard() {
	switch (_b->checkBoard(_x, _y, _turn)){
	case -1:
		_Board::TextColor(12);
		cout << "X";
		break;
	case 1:
		_Board::TextColor(2);
		cout << "O";
		break;
	case 0:
		return false;
	}
	return true;
}
int _Game::processFinish() {

	_Common::gotoXY(_b->getLeft()*4+5,_b->getTop());
	int pWhoWin = _b->testBoard(_x,_y);
	int i = 1;
	switch (pWhoWin) {
	case -1:
		do {
			_Board::TextColor(i++);
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 5); _cprintf("####     ####");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 4); _cprintf("  ###  ###   ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 3); _cprintf("    #####    ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 2); _cprintf("    #####    ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 1); _cprintf("  #### ####  ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop());     _cprintf("####     ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 2); _cprintf("####       #### ##### #### ##     ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 3); _cprintf("####       ####  ###  ####  ##    ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 4); _cprintf("####       ####  ###  ####   ##   ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 5); _cprintf("####  ###  ####  ###  ####    ##  ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 6); _cprintf("#### ## ## #### ##### ####     ## ####");
			Sleep(60);
		} while (i<15);
		PlaySound(TEXT("votay.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;
	case 1:
		do {
			_Board::TextColor(i++);
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop()-5); _cprintf("    #########    ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop()-4); _cprintf(" ####       #### ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop()-3); _cprintf("####         ####");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop()-2); _cprintf("####         ####");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop()-1); _cprintf(" ####       #### ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop());   _cprintf("    #########    ");
			_Common::gotoXY(_b->getLeft() * 4 +1, _b->getTop() + 2);  _cprintf("####       #### ##### #### ##     ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 3); _cprintf("####       ####  ###  ####  ##    ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 4); _cprintf("####       ####  ###  ####   ##   ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 5); _cprintf("####  ###  ####  ###  ####    ##  ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 6); _cprintf("#### ## ## #### ##### ####     ## ####");
			Sleep(60);
		} while (i<15);
		PlaySound(TEXT("votay.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;
	case 0:
		do {
			_Board::TextColor(i++);
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 2); _cprintf("####      ####    #####       #### ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 3); _cprintf("####      ####  #### ####    ####   #### ");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 4); _cprintf("#### #### #### ####   ####  #### ### ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 5); _cprintf("####      ####  #### ####  ####       ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 6); _cprintf("####      ####    #####   ####         ####");
			Sleep(60);
		} while (i<15);
		PlaySound(TEXT("votay.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;	
	case 2:
		_turn = !_turn;
		break;
	}
	_Common::gotoXY(_x, _y);
	return pWhoWin;
}

void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize()-1,_b->getSize()-1)) {
		_x += 4;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_y += 2;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::play() {
	switch (_b->drawInterface()) {
	case 13:
		startGame();
		while (isContinue()) {
			waitKeyBoard();
			if (getCommand() == 27) {
				if (askSave() == 'Y') {
					saveGame();
					exitGame();
				}
				else exitGame();
			}
			else {
				switch (getCommand()) {
				case 65:
					moveLeft();
					break;
				case 87:
					moveUp();
					break;
				case 68:
					moveRight();
					break;
				case 83:
					moveDown();
					break;
				case 13:
					if (processCheckBoard()) {
						switch (processFinish()) {
						case 1: case -1: case 0:
							if (askContinue() != 'Y') exitGame();
							else startGame();
							break;
						}
					}
					break;
				}
			}
		}
	case 14:
		loadGame();
		break;
	}
}
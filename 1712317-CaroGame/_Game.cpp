#include"pch.h"
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
	_command = toupper(_getwch());
	return _command;
}
char _Game::askContinue() {
	_Common::gotoXY(_b->getLeft()-8, _b->getTop() - 1);
	cout << "Press 1 to play again, 2 to return main control, else to exit ";
	_Common::gotoXY(_b->getLeft() + 54, _b->getTop() - 1);
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
	_Common::gotoXY(_b->getLeft(), _b->getTop() - 1);
	cout << "Save this game for the next visit, press Y to save";
	waitKeyBoard();
	return getCommand();
}

void _Game::saveGame() {
	char name[30];
	_Common::gotoXY(_b->getLeft() + _b->getSize() * 4 + 2, _b->getTop() + 2);
	cout << "Your name: ";
	gets_s(name);
	char fileName[40] = ".txt";
	strcat(name, fileName);
	FILE *f = fopen(name, "w");
	for (int i = 0; i < _b->getSize(); i++) {
		for (int j = 0; j < _b->getSize(); j++)
		{
			fprintf(f, "%d", _b->getCheckAt(i, j));
			fprintf(f, "\n");
		}
	}
	fclose(f);
}
int countX = 0;
int countO = 0;
void _Game::loadGame() {
	vector<int> data;
	char name[30];
	_Board::TextColor(14);
	cout << "Your name: ";
	gets_s(name);
	char fileName[10] = ".txt";
	strcat(name, fileName);
	cout << name << endl;
	system("cls");
	FILE *f = fopen(name, "rb");
	if (f == NULL) {
		cout << "Khong tim thay ten nguoi choi";
		Sleep(2000);
		system("cls");
		play();
	}
	int j = 0;
	int i = 0;
	int a;
	while (!feof(f)) {
		fscanf(f, "%d", &a);
		data.push_back(a);
	}
	_b->resetData();
	_b->drawBoard();
	int getdata = 0;
	for (int i = 0; i < _b->getSize(); i++)
	{
		for (int j = 0; j < _b->getSize(); j++)
		{
			int x = _b->getXAt(i, j);
			int y = _b->getYAt(i, j);
			_Common::gotoXY(x, y);
			if (data[getdata] == -1) {
				_b->TextColor(12);
				cout << "X";
				countX++;
				_Common::_Common::gotoXY(7, 3);
				cout << countX;
				_Common::_Common::gotoXY(71, 3);
				cout << "O";
				_b->setCheckAt(i, j, data[getdata]);
			}
			if (data[getdata] == 1) {
				_b->TextColor(10);
				cout << "O";
				countO++;
				_Common::_Common::gotoXY(15, 3);
				cout << countO;
				_Common::_Common::gotoXY(71, 3);
				cout << "X";
				_b->setCheckAt(i, j, data[getdata]);
			}
			getdata++;
		}
	}
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
	_Common::gotoXY(_x, _y);
}
int _Board::countO = 0;
int _Board::countX = 0;
void _Game::playAfterLoad() {
	loadGame();
	_Board::countO = countO;
	_Board::countX = countX;
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
			case 65:case 75:
				moveLeft();
				break;
			case 87:case 72:
				moveUp();
				break;
			case 68: case 77:
				moveRight();
				break;
			case 83:case 80:
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
}
void _Game::playafterloadvsbot() {
	loadGame();
	while (isContinue()) {
		botPlay();
		humanPlay();
		while (getCommand() != 13) {
			humanPlay();
		}
		if (getCommand() == 13)
		{
			if (processCheckBoard()) {
				switch (processFinish()) {
				case 1: case -1: case 0:
					if (askContinue() != 'Y') exitGame();
					else {
						_Board::countO = 0;
						_Board::countX = 0;
						startGame();
					}
					break;
				}
			}
		}
	}
}
bool _Game::processCheckBoard() {
	switch (_b->checkBoard(_x, _y, _turn)) {
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

	_Common::gotoXY(_b->getLeft() * 4 + 5, _b->getTop());
	int pWhoWin = _b->testBoard(_x, _y);
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
		} while (i < 15);
		PlaySound(TEXT("votay.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;
	case 1:
		do {
			_Board::TextColor(i++);
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 5); _cprintf("    #########    ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 4); _cprintf(" ####       #### ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 3); _cprintf("####         ####");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 2); _cprintf("####         ####");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop() - 1); _cprintf(" ####       #### ");
			_Common::gotoXY(_b->getLeft() * 4 + 12, _b->getTop());   _cprintf("    #########    ");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 2);  _cprintf("####       #### ##### #### ##     ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 3); _cprintf("####       ####  ###  ####  ##    ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 4); _cprintf("####       ####  ###  ####   ##   ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 5); _cprintf("####  ###  ####  ###  ####    ##  ####");
			_Common::gotoXY(_b->getLeft() * 4 + 1, _b->getTop() + 6); _cprintf("#### ## ## #### ##### ####     ## ####");
			Sleep(60);
		} while (i < 15);
		PlaySound(TEXT("votay.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;
	case 0:
		do {
			_Board::TextColor(i++);
			_Common::gotoXY(_b->getLeft() * 4 , _b->getTop() + 2); _cprintf("####    ####    #####      ### ###");
			_Common::gotoXY(_b->getLeft() * 4 , _b->getTop() + 3); _cprintf("####    ####  #### ####   ###   ### ");
			_Common::gotoXY(_b->getLeft() * 4 , _b->getTop() + 4); _cprintf("#### ## #### ####   #### ### ### ###");
			_Common::gotoXY(_b->getLeft() * 4 , _b->getTop() + 5); _cprintf("####    ####  #### #### ###       ###");
			_Common::gotoXY(_b->getLeft() * 4 , _b->getTop() + 6); _cprintf("####    ####    #####  ###         ###");
			Sleep(60);
		} while (i < 15);
		PlaySound(TEXT("votay.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;
	case 2:
		_turn = !_turn;
		break;
	}
	_Common::gotoXY(_x, _y);
	return pWhoWin;
}
void _Game::help() {
	_b->drawFrames();
	_Common::gotoXY(_b->getLeft() + 30, _b->getTop());
	cout << "Instruction";
	_Common::gotoXY(_b->getLeft() + 20, _b->getTop() + 2);
	cout << "w: Move up";
	_Common::gotoXY(_b->getLeft() + 20, _b->getTop() + 3);
	cout << "s: Move down";
	_Common::gotoXY(_b->getLeft() + 20, _b->getTop() + 4);
	cout << "a: Move left";
	_Common::gotoXY(_b->getLeft() + 20, _b->getTop() + 5);
	cout << "d: Move right";
	_Common::gotoXY(_b->getLeft() + 40, _b->getTop() + 2);
	cout << "arrow up: Move up";
	_Common::gotoXY(_b->getLeft() + 40, _b->getTop() + 3);
	cout << "arrow down: Move down";
	_Common::gotoXY(_b->getLeft() + 40, _b->getTop() + 4);
	cout << "arrow left: Move left";
	_Common::gotoXY(_b->getLeft() + 40, _b->getTop() + 5);
	cout << "arrow right: Move right";
	_Common::gotoXY(_b->getLeft() + 30, _b->getTop() + 7);
	cout << "enter: choose";
	_Common::gotoXY(_b->getLeft() + 20, _b->getTop() + 9);
	cout << "Rule:";
	_Common::gotoXY(_b->getLeft() + 22, _b->getTop() + 10);
	cout << "- Move and choose the position you want then take turn";
	_Common::gotoXY(_b->getLeft() + 22, _b->getTop() + 11);
	cout << "- The game end if appear five similar continuous point ";
	_Common::gotoXY(_b->getLeft() + 20, _b->getTop() + 12);
	cout << "Note: Press Esc if you want to leave the game";
	_Common::gotoXY(_b->getLeft() + 20, _b->getTop() + 14);
	cout << "Press any key to continue";
	_getwch();
	system("cls");
	play();
}
void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1)) {
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

void _Game::botPlay() {
	_Board::move nextMove;
	if (_b->sonuocdadi() == 0) {
		_x= _b->getLeft() + _b->getSize() * 4 / 2 + 2;
		_y = _b->getTop() + _b->getSize() * 2 / 2 + 1;
		//_x = 22;
		//_y = 7;
	}
	else {
		nextMove = _b->timkiemnuocdi();
		//board[ai_move.second.first][ai_move.second.second] = AI_MARKER;
		//_Board::move nextMove = _b->findBestMove();
		_x = nextMove.x;
		_y = nextMove.y;
	}
	_Common::gotoXY(_x,_y);
	_command = 13;
	if (getCommand() == 13) {
		if (processCheckBoard()) {
			switch (processFinish()) {
			case 1: case -1: case 0:
				char ask = askContinue();
				if (ask == '2') play();
				else if (ask == '1') {
					_Board::countO = 0;
					_Board::countX = 0;
					playvsbot();
				}
				else exitGame();
				break;
			}
		}
	}
}
void _Game::moveAndChoose() {
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
		case 65:case 75:
			moveLeft();
			break;
		case 87:case 72:
			moveUp();
			break;
		case 68:case 77:
			moveRight();
			break;
		case 83:case 80:
			moveDown();
			break;
		case 13:
			if (processCheckBoard()) {
				switch (processFinish()) {
				case 1: case -1: case 0:
					if (askContinue() != 'Y') exitGame();
					else {
						_Board::countO = 0;
						_Board::countX = 0;
						startGame();
					}
					break;
				}
			}
			break;
		}
	}
}
void _Game::humanPlay() {
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
		case 65:case 75:
			moveLeft();
			break;
		case 87:case 72:
			moveUp();
			break;
		case 68:case 77:
			moveRight();
			break;
		case 83:case 80:
			moveDown();
			break;
		}
	}
}


mutex mtx;
condition_variable cv;
int result = -1;
void _Game::Timer() {

	// Do something
	// ....
	// ....
	int x = 0;
	int sec = 0;
	int min = 0;
	int hour = 0;
	while (x == 0) {
		_b->TextColor(11);
		_Common::gotoXY(35, 5);
		cout << hour << ":" << min << ":" << sec;
		sec++;
		if (sec == 60)
		{
			x = 0;
			min++;
			if (min == 60) {
				min = 0;
				hour++;
			}
		}
		Sleep(1000);
	}
	// got a result? publish it!
	unique_lock<mutex> lck(mtx);
	if (result != -1)
		return; // there is already a result!

	result = 0; // my result
	cv.notify_one(); // say I am ready
	
}
void _Game::playvsbot() {
	system("cls");
	startGame();
	while (isContinue()) {
		botPlay();
		humanPlay();
		while (getCommand() != 13) {
			humanPlay();
		}
		if (getCommand() == 13)
		{
			if (processCheckBoard()) {
				switch (processFinish()) {
				case 1: case -1: case 0:
					char ask = askContinue();
					if (ask == '2') play();
					else if (ask == '1') {
						_Board::countO = 0;
						_Board::countX = 0;
						playvsbot();
					}
					else exitGame();
					break;
				}
			}
		}
	}
	unique_lock<mutex> lck(mtx);
	if (result != -1)
		return; // there is already a result!

	result = 1; // my result
	cv.notify_one(); // say I am ready
}
void _Game::play() {
	system("cls");
	switch (_b->drawInterface()) {
	case 13:
		//_b->TextColor(12);
		switch (_b->chooseMode()) {
		case 13:
		{
			playvsbot();
			break;
		}
		case 14: {
			startGame();
			//int flag = 0;
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
					case 65:case 75:
						moveLeft();
						break;
					case 87:case 72:
						moveUp();
						break;
					case 68:case 77:
						moveRight();
						break;
					case 83:case 80:
						moveDown();
						break;
					case 13:
						if (processCheckBoard()) {
							switch (processFinish()) {
							case 1: case -1: case 0:
								//flag = 1;
								char ask = askContinue();
								if (ask == '2') play();
								else if(ask=='1'){
									_Board::countO = 0;
									_Board::countX = 0;
									startGame();
								}
								else exitGame();
								break;
							}
						}
						break;
					}
				}
				
			}
			
			break;
		}
		}
		break;
	case 14:
		playAfterLoad();
		break;
	case 15:
		help();
		break;
	case 16:
		exitGame();
		break;
	}
}
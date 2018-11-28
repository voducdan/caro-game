#include"pch.h"
#include"_Board.h"
int _Board::getSize() { return _size; }
int _Board::getLeft() { return _left; }
int _Board::getTop() { return _top; }
int _Board::getXAt(int i, int j) {
	return _pArr[i][j].GetX();
}
int _Board::getYAt(int i, int j) {
	return _pArr[i][j].GetY();
}
int _Board::getCheckAt(int i, int j) {
	return _pArr[i][j].GetCheck();
}
void _Board::setCheckAt(int i, int j, int value) {
	_pArr[i][j].setCheck(value);
}
_Board::_Board(int size, int x, int y) {
	_size = size;
	_left = x;
	_top = y;
	_pArr = new _Point*[size];
	for (int i = 0; i < size; i++) {
		_pArr[i] = new _Point[size];
	}
}
_Board::~_Board() {
	for (int i = 0; i < _size; i++) {
		delete[] _pArr[i];
	}
	delete[] _pArr;
}

void _Board::resetData() {
	if (_size == 0) return;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].SetX(4 * j + _left + 2);
			_pArr[i][j].SetY(2 * i + _top + 1);
			_pArr[i][j].setCheck(0);
		}
	}
}
void _Board::drawBoard() {
	if (_pArr == NULL) return;
	//for (int i = 0; i < _size; i++) {
	//	for (int j = 0; j < _size; j++) {
	//		_Common::_Common::_Common::gotoXY(_left + 4 * i, _top + 2 * j);
	//		cout << ".";
	//	}
	//}

	_Common::gotoXY(_pArr[0][0].GetX(), _pArr[0][0].GetY());

	//ban co
	//ngang
	for (int i = _left + 1; i <= _left + 4 * _size; i++)
	{
		TextColor(15);
		_Common::_Common::gotoXY(i, _top); printf("%c", 196);
		Sleep(1);
	}
	for (int i = _left + 1; i <= _left + 4 * _size; i++)
	{
		TextColor(15);
		_Common::_Common::gotoXY(i, _top + 2 * _size); printf("%c", 196);
		Sleep(1);
	}
	for (int j = 2; j < 2 * _size; j = j + 2) {

		for (int i = _left; i <= _left + 4 * _size; i++)
		{
			TextColor(15);
			_Common::_Common::gotoXY(i, _top + j); printf("%c", 196);
			Sleep(1);
		}

	}

	//doc
	for (int i = _top + 1; i <= _top + 2 * _size - 1; i++)
	{
		TextColor(15);
		_Common::_Common::gotoXY(_left, i); printf("%c", 179);
		Sleep(1);

	}
	for (int i = _top + 1; i <= _top + 2 * _size - 1; i++)
	{
		TextColor(15);
		_Common::_Common::gotoXY(_left + 4 * _size, i); printf("%c", 179);
		Sleep(1);
	}
	for (size_t j = 4; j < 4 * _size; j = j + 4)
	{
		for (int i = _top + 1; i <= _top + 2 * _size - 1; i++)
		{
			TextColor(15);
			_Common::_Common::gotoXY(_left + j, i); printf("%c", 179);
			Sleep(1);
		}
	}
	_Common::_Common::gotoXY(_left, _top); printf("%c", 218);
	_Common::_Common::gotoXY(_left, _top + 2 * _size); printf("%c", 192);
	_Common::_Common::gotoXY(_left + 4 * _size, _top); printf("%c", 191);
	_Common::_Common::gotoXY(_left + 4 * _size, _top + 2 * _size); printf("%c", 217);


	//khung 
	TextColor(11);
	for (int i = 0; i <= _left*2+_size*4; i++)
	{
		_Common::_Common::gotoXY(i, 0); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 0; i <= _left * 2 + _size * 4; i++)
	{
		_Common::_Common::gotoXY(i, _top*2+_size*2); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 0; i <= _top * 2 + _size * 2 - 1; i++)
	{
		_Common::_Common::gotoXY(0, i); printf("%c", 186);
		Sleep(1);
	}
	for (int i = 0; i <= _top * 2 + _size * 2; i++)
	{
		_Common::_Common::gotoXY(_left * 2 + _size * 4, i); printf("%c", 186);
		Sleep(1);
	}
	_Common::_Common::gotoXY(0, 0); printf("%c", 201);
	_Common::_Common::gotoXY(0, _top * 2 + _size * 2); printf("%c", 200);
	_Common::_Common::gotoXY(_left * 2 + _size * 4 , 0); printf("%c", 187);
	_Common::_Common::gotoXY(_left * 2 + _size * 4 , _top * 2 + _size * 2); printf("%c", 188);

	TextColor(11);
	for (int i = 2; i <= _left * 2 + _size * 4 -1; i++)
	{
		_Common::_Common::gotoXY(i, 1); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 1; i <= _left * 2 + _size * 4 - 1; i++)
	{
		_Common::_Common::gotoXY(i, _top * 2 + _size * 2 - 1); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 1; i <= _top * 2 + _size * 2 -1; i++)
	{
		_Common::_Common::gotoXY(1, i); printf("%c", 186);
		Sleep(1);
	}
	for (int i = 1; i <= _top * 2 + _size * 2 - 1; i++)
	{
		_Common::_Common::gotoXY(_left * 2 + _size * 4 - 1, i); printf("%c", 186);
		Sleep(1);
	}
	_Common::_Common::gotoXY(1, 1); printf("%c", 201);
	_Common::_Common::gotoXY(1, _top * 2 + _size * 2-1); printf("%c", 200);
	_Common::_Common::gotoXY(_left * 2 + _size * 4 - 1, 1); printf("%c", 187);
	_Common::_Common::gotoXY(_left * 2 + _size * 4 - 1, _top * 2 + _size * 2-1); printf("%c", 188);
	for (int i = 0; i < 15; i++)
	{
		_Common::_Common::gotoXY(63 + i, 4); printf("%c", 205);
	}
	for (int i = 0; i < 2; i++)
	{
		_Common::_Common::gotoXY(63, i + 2); printf("%c", 186);
	}
	_Common::_Common::gotoXY(63, 4); printf("%c", 200);
	_Common::_Common::gotoXY(67, 2); TextColor(12); printf("Luot Choi");
	TextColor(15); _Common::_Common::gotoXY(71, 3); printf("X");
	TextColor(11);
	for (int i = 0; i < 15; i++)
	{
		_Common::_Common::gotoXY(2 + i, 4); printf("%c", 205);
	}
	for (int i = 0; i < 2; i++)
	{
		_Common::_Common::gotoXY(17, i + 2); printf("%c", 186);
	}
	/*for (int i = 0; i < 43; i++)
	{
		_Common::_Common::gotoXY(19 + i, 2); printf("_");
	}*/
	_Common::_Common::gotoXY(17, 4); printf("%c", 188);

	_Common::gotoXY(34, 0); TextColor(160); printf(" GAME CO CARO ");
	_Common::gotoXY(20, 2); TextColor(9); printf("## ##      ##    ##    ##   ##   ##   ###\n");
	_Common::gotoXY(20, 3); TextColor(9); printf("##   ##  ## ##   ## ## ##    ## ##  ##   ##\n");
	_Common::gotoXY(20, 4); TextColor(9); printf("## ##   ##   ##  ##    ##     ##      ###\n");
	_Common::gotoXY(5, 2); TextColor(12); printf("So Quan Co");
	TextColor(15);
	_Common::gotoXY(3, 3); printf("  -   |   -   ");
	_Common::gotoXY(3, 3); TextColor(14); printf("X");
	_Common::gotoXY(11, 3); TextColor(14); printf("O");
	_Common::gotoXY(_pArr[0][0].GetX(), _pArr[0][0].GetY());
	//cout << _pArr[0][0].GetX() << " " << _pArr[0][0].GetY();
}

int _Board::checkBoard(int x, int y, int turn) {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {

			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y && _pArr[i][j].GetCheck() == 0) {
				if (turn)
				{
					countX++;
					_Common::_Common::gotoXY(7, 3);
					cout << countX;
					_Common::_Common::gotoXY(71, 3);
					cout << "O";
					_pArr[i][j].setCheck(-1);
				}
				else {
					countO++;
					_Common::_Common::gotoXY(15, 3);
					cout << countO;
					_Common::_Common::gotoXY(71, 3);
					cout << "X";
					_pArr[i][j].setCheck(1);
				}
				_Common::_Common::gotoXY(_pArr[i][j].GetX(), _pArr[i][j].GetY());
				return _pArr[i][j].GetCheck();
			}
		}
	}
	return 0;
}
int _Board::testBoard(int x, int y) {
	int count = 1;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				// an doc
				for (int t = i - 1; t >= 0; t--) {
					if (_pArr[t][j].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
				for (int t = i + 1; t < _size; t++) {
					if (_pArr[t][j].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
				//an ngang
				count = 1;
				for (int t = j - 1; t >= 0; t--) {
					if (_pArr[i][t].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
				for (int t = j + 1; t < _size; t++) {
					if (_pArr[i][t].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
				// an cheo xuoi
				count = 1;
				for (int t = 1; t <= i && t + j < _size; t++) {
					if (_pArr[i - t][j + t].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
				for (int t = 1; t <= j && t + i < _size; t++) {
					if (_pArr[i + t][j - t].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
				// an cheo nguoc
				count = 1;
				for (int t = 1; t <= i && t <= j; t++) {
					if (_pArr[i - t][j - t].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
				for (int t = 1; t + i < _size&&t + j < _size; t++) {
					if (_pArr[i + t][j + t].GetCheck() == _pArr[i][j].GetCheck()) {
						count++;
						if (count == 5) {
							if (_pArr[i][j].GetCheck() == -1) return -1;
							if (_pArr[i][j].GetCheck() == 1) return 1;
						}
					}
					else {
						break;
					};
				}
			}
		}
	}
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetCheck() == 0) return 2;
		}
	}
	return 0;
}


void _Board::drawFrames() {
	TextColor(12);
	for (int i = 2; i <= 117; i++)
	{
		_Common::_Common::gotoXY(i, 0); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 2; i <= 117; i++)
	{
		_Common::_Common::gotoXY(i, 26); printf("%c", 205);
		Sleep(1);
	}
	for (int i = 1; i <= 25; i++)
	{
		_Common::_Common::gotoXY(1, i); printf("%c", 186);
		Sleep(1);
	}
	for (int i = 1; i <= 25; i++)
	{
		_Common::_Common::gotoXY(118, i); printf("%c", 186);
		Sleep(1);
	}
	_Common::_Common::gotoXY(1, 0); printf("%c", 201);
	_Common::_Common::gotoXY(1, 26); printf("%c", 200);
	_Common::_Common::gotoXY(118, 0); printf("%c", 187);
	_Common::_Common::gotoXY(118, 26); printf("%c", 188);
}

int _Board::drawInterface() {
	drawFrames();
	TextColor(9);
	_Common::gotoXY(2, 2); printf("  #########      ### ###      ##########     ########      ##########      ### ###      ### ##   ## ### ##########");
	_Common::gotoXY(2, 3); printf(" ##########     ###   ###     ####    ###  ####    ####   ###########     ###   ###     ###  ## ##  ### #####");
	_Common::gotoXY(2, 4); printf("#####          ### ### ###    ####    ### ####      #### ####            ### ### ###    ###   ###   ### ##########");
	_Common::gotoXY(2, 5); printf("#####         ###  ###  ###   #########   ####      #### ####    ####   ###  ###  ###   ###         ### ##########");
	_Common::gotoXY(2, 6); printf(" ##########  ###         ###  ####   ####  ####    ####   ###########  ###         ###  ###         ### #####     ");
	_Common::gotoXY(2, 7); printf("  ######### ###           ### ####    ####   ########      ########## ###           ### ###         ### ##########");
	TextColor(14);
	_Common::gotoXY(47, 20); printf("VO DUC DAN - 1712317 - 17CTT2");
	_Common::gotoXY(47, 22); printf("    University of Science");
	TextColor(14);
	TextColor(202);
	_Common::gotoXY(56, 13); printf("%c PLAY GAME  ", 175);
	TextColor(14);
	_Common::gotoXY(58, 14); printf("CONTINUE");
	_Common::gotoXY(58, 15); printf("HELP");
	_Common::gotoXY(58, 16); printf("EXIT");
	int chon = 0;
	int toado = 13;
	do {
		char a = _getch();
		if (a == 80 || a == 's' || a == 'S' || a == '2') chon = 1;
		else if (a == 72 || a == 'w' || a == 'W' || a == '8') chon = 2;
		else if (a == 13 || a == 'e' || a == 'e' || a == '5') chon = 3;
		else chon = 0;
		if (chon == 1 && toado <= 16) toado++;
		if (chon == 2 && toado >= 13) toado--;
		if (chon == 1 && toado > 16) toado = 13;
		if (chon == 2 && toado < 13) toado = 16;
		if (toado == 13)
		{
			TextColor(202);
			_Common::gotoXY(56, 13); printf("%c PLAY GAME  ", 175);
			TextColor(14);
			_Common::gotoXY(56, 14); printf("  CONTINUE         ");
			_Common::gotoXY(56, 15); printf("  HELP        ");
			_Common::gotoXY(56, 16); printf("  EXIT         ");
			TextColor(0);
		}
		if (toado == 14)
		{
			TextColor(14);
			_Common::gotoXY(56, 13); printf("  PLAY GAME    ");
			TextColor(202);
			_Common::gotoXY(56, 14); printf("%c CONTINUE       ", 175);
			TextColor(14);
			_Common::gotoXY(56, 15); printf("  HELP        ");
			_Common::gotoXY(56, 16); printf("  EXIT         ");
			TextColor(0);
		}
		if (toado == 15)
		{
			TextColor(15);
			_Common::gotoXY(56, 13); printf("  PLAY GAME  ", 175);
			_Common::gotoXY(56, 14); printf("  CONTINUE       ");
			TextColor(202);
			_Common::gotoXY(56, 15); printf("%c HELP      ", 175);
			TextColor(14);
			_Common::gotoXY(56, 16); printf("  EXIT       ");
			TextColor(0);
		}
		if (toado == 16)
		{
			TextColor(15);
			_Common::gotoXY(56, 13); printf("  PLAY GAME    ", 175);
			_Common::gotoXY(56, 14); printf("  CONTINUE         ");
			_Common::gotoXY(56, 15); printf("  HELP        ");
			TextColor(202);
			_Common::gotoXY(56, 16); printf("%c EXIT       ", 175);
		}
	} while (chon != 3);
	system("cls");
	return toado;
}


bool _Board::isMoveLetf() {
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetCheck() == 0)
				return false;
		}
	}
	return true;
}
int _Board::evaluate() {
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			//cout << _pArr[i][j].GetX() << "," << _pArr[i][j].GetY() << endl;
			if (testBoard(_pArr[i][j].GetX(), _pArr[i][j].GetY()) == -1) {
				return +10;
			}
			if (testBoard(_pArr[i][j].GetX(), _pArr[i][j].GetY()) == 1)
				return  -10;
		}
	}
	return 0;
}
int _Board::findmax(int a, int b) {
	return a > b ? a : b;
}
int _Board::findmin(int a, int b) {
	return a < b ? a : b;
}
int _Board::minimax(_Point p, int depth, bool isMax, int alpha, int beta) {
	int score = evaluate();
	if (score == 10)
		return score - depth;
	if (score == -10)
		return score + depth;
	if (isMoveLetf())
		return 0;
	if (isMax) {
		int bestVal = -1000;
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				if (_pArr[i][j].GetCheck() == 0) {
					_pArr[i][j].setCheck(-1);
					int val = minimax(_pArr[i][j], depth + 1, false, alpha, beta);
					bestVal = findmax(bestVal, val);
					alpha = findmax(bestVal, alpha);
					//cout<<"In Max "<<bestVal<<endl;
					//printBoard(board);
					_pArr[i][j].setCheck(0);
					if (beta <= alpha)
						break;
				}
				if (beta <= alpha)
					break;
			}
		}
		return bestVal;
	}
	else {
		int bestVal = 1000;
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				if (_pArr[i][j].GetCheck() == 0) {
					_pArr[i][j].setCheck(1);
					int val = minimax(_pArr[i][j], depth + 1, true, alpha, beta);
					bestVal = findmin(bestVal, val);
					beta = findmin(bestVal, beta);
					_pArr[i][j].setCheck(0);
					//cout<<"In Min "<<bestVal<<endl;
					//printBoard(board);
					if (beta <= alpha)
						break;
				}
				if (beta <= alpha)
					break;
			}
		}
		return bestVal;
	}
}

double mangdiemtancong[7] = { 0,1,9,81,729,6561,59049 };
//double mangdiemtancong[7] = { 0,9,72,432,2589,15552 ,93312};
double mangdiemphongngu[7] = { 0, 3, 24, 192, 1536, 12288, 98034 };
//double mangdiemphongngu[7] = { 0, 1, 8, 64, 512, 4096, 32768 };
double _Board::tancongdoc(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				// an doc
				for (int t = 1; t < 7 && i - t >= 0; t++) {
					if (_pArr[i - t][j].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i - t][j].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < _size; t++) {
					if (_pArr[i + t][j].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i + t][j].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double _Board::tancongngang(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				// an doc
				for (int t = 1; t < 7 && j - t >= 0; t++) {
					if (_pArr[i][j-t].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i][j-t].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && j + t < _size; t++) {
					if (_pArr[i][j+t].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i][j+t].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double _Board::tancongcheoxuoi(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				for (int t = 1; t < 7 && j - t >= 0&&i-t>=0; t++) {
					if (_pArr[i - t][j-t].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i - t][j-t].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < _size&&j+t<_size; t++) {
					if (_pArr[i + t][j+t].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i + t][j+t].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
			
		}
		if (flag == 1) break;
	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double _Board::tancongcheonguoc(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				for (int t = 1; t < 7 && j + t < _size && i - t >= 0; t++) {
					if (_pArr[i - t][j + t].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i - t][j + t].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < _size&&j - t >=0; t++) {
					if (_pArr[i + t][j - t].GetCheck() == -1) {
						soquanta++;
					}
					else if (_pArr[i + t][j - t].GetCheck() == 1)
					{
						soquandich++;
						break;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquandich == 2)
		return 0;
	diemtong -= mangdiemphongngu[soquandich + 1];
	diemtong += mangdiemtancong[soquanta];
	return diemtong;
}

double _Board::phongngudoc(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				// an doc
				for (int t = 1; t < 7 && i - t >= 0; t++) {
					if (_pArr[i - t][j].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i - t][j].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < _size; t++) {
					if (_pArr[i + t][j].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i + t][j].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	//diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double _Board::phongngungang(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				// an doc
				for (int t = 1; t < 7 && j - t >= 0; t++) {
					if (_pArr[i][j - t].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i][j - t].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && j + t < _size; t++) {
					if (_pArr[i][j + t].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i][j + t].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	//diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double _Board::phongngucheoxuoi(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				for (int t = 1; t < 7 && j - t >= 0 && i - t >= 0; t++) {
					if (_pArr[i - t][j - t].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i - t][j - t].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < _size&&j + t < _size; t++) {
					if (_pArr[i + t][j + t].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i + t][j + t].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

	}
	if (soquanta == 2)
		return 0;
	//diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}

double _Board::phongngucheonguoc(int x, int y) {
	int soquanta = 0;
	int soquandich = 0;
	double diemtong = 0;
	int flag = 0;
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetX() == x && _pArr[i][j].GetY() == y)
			{
				for (int t = 1; t < 7 && j + t < _size && i - t >= 0; t++) {
					if (_pArr[i - t][j + t].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i - t][j + t].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				for (int t = 1; t < 7 && i + t < _size&&j - t >= 0; t++) {
					if (_pArr[i + t][j - t].GetCheck() == -1) {
						soquanta++;
						break;
					}
					else if (_pArr[i + t][j - t].GetCheck() == 1)
					{
						soquandich++;
					}
					else
						break;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if (soquanta == 2)
		return 0;
	//diemtong -= mangdiemtancong[soquanta];
	diemtong += mangdiemphongngu[soquandich];
	return diemtong;
}
int _Board::sonuocdadi() {
	int count = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetCheck() != 0)
				count++;
		}
	}
	return count;
}
_Board::move _Board::timkiemnuocdi() {
	move wayresult;
	wayresult.x = -1;
	wayresult.y = -1;
	double diemMax = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].GetCheck() == 0) {

				int x = _pArr[i][j].GetX();
				int y = _pArr[i][j].GetY();
				double diemtancong = tancongdoc(x, y) + tancongngang(x, y) + tancongcheoxuoi(x, y) + tancongcheonguoc(x, y);
				double diemphongngu = phongngudoc(x, y) + phongngungang(x, y) + phongngucheoxuoi(x, y) + phongngucheonguoc(x, y);
				double temp = diemtancong > diemphongngu ? diemtancong : diemphongngu;
				if (diemMax < temp)
				{
					diemMax = temp;
					wayresult.x = x;
					wayresult.y = y;
					//wayresult->setCheck(_pArr[i][j].GetCheck());
				}
			}
		}
	}
	return wayresult;
}

_Board::move  _Board::findBestMove() {
	move p;
	p = timkiemnuocdi();
	return p;
	//int bestVal = -1000;
	//int alpha = -1000;
	//int beta = 1000;
	//for (int i = 0; i < _size; i++) {
	//	for (int j = 0; j < _size; j++) {
	//		if (_pArr[i][j].GetCheck() == 0) {
	//			_pArr[i][j].setCheck(-1);
	//			int moveVal = minimax(_pArr[i][j],0, false, alpha, beta);
	//			_pArr[i][j].setCheck(0);
	//			//cout <<i<<" "<<j<<" "<<moveVal<<endl;
	//			if (moveVal > bestVal) {
	//				bestMove.x = _pArr[i][j].GetX();
	//				bestMove.y = _pArr[i][j].GetY();
	//				bestVal = moveVal;
	//			}
	//		}
	//	}
	//}
	//return bestMove;
}

int _Board::chooseMode() {
	TextColor(14);
	TextColor(202);
	_Common::gotoXY(56, 13); printf("%c PLAYER vs BOT  ", 175);
	TextColor(14);
	_Common::gotoXY(58, 14); printf("PLAYER vs PLAYER");
	int chon = 0;
	int toado = 13;
	do {
		char a = _getch();
		if (a == 80 || a == 's' || a == 'S' || a == '2') chon = 1;
		else if (a == 72 || a == 'w' || a == 'W' || a == '8') chon = 2;
		else if (a == 13 || a == 'e' || a == 'e' || a == '5') chon = 3;
		else chon = 0;
		if (chon == 1 && toado <= 14) toado++;
		if (chon == 2 && toado >= 13) toado--;
		if (chon == 1 && toado > 14) toado = 13;
		if (chon == 2 && toado < 13) toado = 16;
		if (toado == 13)
		{
			TextColor(202);
			_Common::gotoXY(56, 13); printf("%c PLAYER VS BOT  ", 175);
			TextColor(14);
			_Common::gotoXY(56, 14); printf("  PLAYER VS PLAYER         ");
			TextColor(0);
		}

		if (toado == 14)
		{
			TextColor(14);
			_Common::gotoXY(56, 13); printf("  PLAYER VS BOT    ");
			TextColor(202);
			_Common::gotoXY(56, 14); printf("%c PLAYER VS PLAYER       ", 175);
			TextColor(14);
			TextColor(0);
		}
	} while (chon != 3);
	system("cls");
	return toado;
}



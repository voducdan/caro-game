#pragma once
#include "pch.h"
#include"_Point.h"
#include"_Common.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include<string>
using namespace std;

class _Board {
private:
	int _size;
	int _left;
	int _top;
	_Point** _pArr;
public:
	struct move {
		int x;
		int y;
	};
	int getCheckAt(int, int);
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void setCheckAt(int, int, int);
	static int countX;
	static int countO;
	_Board(int,int,int);
	~_Board();
	void resetData();
	void drawBoard();
	int checkBoard(int, int, int);
	int testBoard(int,int);
	static void TextColor(int x)
	{
		HANDLE mau = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(mau, x);
	}
	int findmax(int, int);
	int findmin(int, int);
	void drawFrames();
	int drawInterface();
	bool isMoveLetf();
	int evaluate();
	int minimax(int, bool);
	move findBestMove();
	//void botPlay();
};
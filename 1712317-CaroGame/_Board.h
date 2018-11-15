#pragma once
#include "pch.h"
#include"_Point.h"
#include"_Common.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
class _Board {
private:
	int _size;
	int _left;
	int _top;
	_Point** _pArr;
public:
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
	void drawFrames();
	int drawInterface();
};
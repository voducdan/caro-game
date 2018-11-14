#pragma once
#include "pch.h"
#include"_Board.h"
#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#include<stdio.h>
#include <dos.h>
#include<conio.h>
#include<string>
using namespace std;

class _Game {
	_Board* _b;
	bool _turn;
	int _x;
	int _y;
	int _command;
	bool _loop;
public:
	_Game(int, int, int);
	~_Game();
	int GetX() { return _x; }
	int GetY() { return _y; }
	int getCommand();
	bool isContinue();
	char waitKeyBoard();
	char askContinue();
	void startGame();
	void exitGame();
	char askSave();
	void saveGame();
	void loadGame();
	void play();
public:
	int processFinish();
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
};
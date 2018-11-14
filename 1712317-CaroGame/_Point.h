#pragma once
#include "pch.h"
#include<iostream>
#include<Windows.h>
using namespace std;

class _Point {
	int _x;
	int _y;
	int _check;
public:
	_Point();
	_Point(int, int);
	bool setCheck(int value);
	int GetX() { return _x; }
	int GetY() { return _y; }
	int GetCheck() { return _check; }
	void SetX(int value) { _x = value; }
	void SetY(int value) { _y = value; }
};
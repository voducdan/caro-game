// 1712317-CaroGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<conio.h>
#include<time.h>
#include"_Game.h"
using namespace std;
const int BOARD_SIZE =10;
const int LEFT = 20;
const int TOP = 6;




int main(){

	_Common::fixConsoleWindown();
	_Game g(BOARD_SIZE, LEFT, TOP);
	g.play();
	return 0;
	/*for (size_t i = 0; i < 255; i++)
	{
		printf("%d\n%c\n", i, i);
	}*/
}



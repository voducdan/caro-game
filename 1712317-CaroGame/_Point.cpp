#include"pch.h"
#include"_Point.h"

_Point::_Point() {
	_x = 0;
	_y = 0;
	_check = 0;
}
_Point::_Point(int x, int y) {
	_x = x;
	_y = y;
	_check = 0;
}
bool _Point::setCheck(int value) {
	if (value == -1 || value == 1 || value == 0) {
		_check = value;
		return true;
	}
	return false;
}
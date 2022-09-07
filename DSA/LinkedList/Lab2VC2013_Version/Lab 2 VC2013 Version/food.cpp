#include "food.h"
#include <iostream>
using namespace std;

Food::Food(string s, int cal)
{
	_name = s;
	_cal = cal;
}

Food Food::operator+(const Food &f)
{
	// modify this function

	Food food;

	food._cal = this->_cal + f._cal; 
	food._name = this->_name + " " + f._name; 

	return food;
	return Food();
}

bool Food::operator>(const Food &f)
{
	return _cal > f._cal;
}

bool Food::operator==(const Food &f)
{
	return true;
}

ostream &operator<<(ostream &os, const Food &f)
{
	os << f._name << " with " << f._cal << " calories";
	return os;
}
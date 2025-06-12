#ifndef MISCCOST_H
#define MISCCOST_H
#include "MyString.h"
#include <iostream>
using namespace std;


class misccost
{
	MyString costtype;
	float amount;

public:
	misccost();
	misccost(MyString _costtype, float _amount);
	~misccost();
	MyString get_costtype()const;
	float get_cost()const;
	void set_cost(float _cost);
};


#endif 

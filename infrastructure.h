#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H
#include "MyString.h"
#include <iostream>
using namespace std;

class infrastructure
{
	MyString name;
	MyString type;
	float area_covered;

public:
	infrastructure();
	infrastructure(MyString _name, MyString _type, float _area_covered);
	~infrastructure();
	void display_info()const;

};

#endif 

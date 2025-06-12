#ifndef  SMARTCITY_H
#define SMARTCITY_H
#include <iostream>
#include "MyString.h"
#include "cityzone.h"
#include <vector>
using namespace std;

class smartcity
{
	MyString city_name;
	vector<cityzone*>zones;

public:
	smartcity();
	smartcity(MyString _city_name, vector<cityzone*>_zones);
	~smartcity();
	void add_zone(cityzone *_zone);
	void display_smart_city()const;
	

};

#endif // ! SMARTCITY_H

#ifndef  LABOR_H
#define LABOR_H
#include "MyString.h"
#include <iostream>
using namespace std;


class labor
{
	MyString labor_type;
	float cost_per_hour;

public:
	labor();
	labor(MyString _labor_type, float cost_per_hour);
	~labor();
	void display_labor_info()const;
	MyString get_labor_type()const;
	float get_cost()const;

};

#endif 

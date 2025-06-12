#ifndef  MATERIAL_H
#define MATERIAL_H
#include "MyString.h"
#include <iostream>
using namespace std;


class material
{
	MyString material_name;
	float cost_per_sqft;

public:
	material();
	material(MyString _material_name,float _cost_per_sqft);
	~material();
	void display_material_info()const;
	MyString get_material_name()const;
	float get_cost()const;
	void set_cost(float _cost);
};

#endif 
#ifndef  BUILDING_H
#define BUILDING_H
#include <iostream>
#include "floors.h"
#include "room.h"
#include "bedroom.h"
#include "kitchen.h"
#include "MyString.h"
#include <vector>

class building
{
	MyString building_name;
	MyString building_type;
	MyString location;
	vector<floors*>floorlist;

public:
	building();
	building(MyString _building_name, MyString _building_type, MyString _location, vector<floors*>&_floorlist);
	~building();
	void display_building_info()const;
	void add_floor(floors* f);
	int get_floor_count()const;
	float get_building_cost();
	
};

#endif

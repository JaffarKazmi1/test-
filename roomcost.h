#ifndef  ROOMCOST_H
#define ROOMCOST_H
#include "MyString.h"
#include "room.h"
#include <iostream>
using namespace std;

class roomcost
{
	room* associated_room;
	float material_cost_per_sqft;
	float labor_cost_per_sqft;
	float room_total_cost;

public:
	roomcost();
	roomcost(room* _associated_room, float _material_cost_per_sqft, float _labor_cost_per_sqft, float _room_total_cost);
	~roomcost();
	void calculate_room_cost();
	float get_room_total_cost()const;
	void display_room_cost()const;

};


#endif

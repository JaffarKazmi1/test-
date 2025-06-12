#ifndef COSTESTIMATOR_H
#define COSTESTIMATOR_H
#include "roomcost.h"
#include "utilityservice.h"
#include "roomcost.h"
#include "material.h"
#include "labor.h"
#include "misccost.h"
#include <vector>
#include <iostream>
using namespace std;


class costestimator
{
	utilityservice utility_cost;
	roomcost room_cost;
	material material_cost;
	labor labor_cost;
	misccost miscellaneous_cost;
	vector<roomcost*> rooms;

public:
	costestimator();
	costestimator(utilityservice _utility_cost,roomcost _room_cost,material _material_cost,labor _labor_cost,misccost _miscellaneous_cost, vector<roomcost*> _rooms);
	~costestimator();
	void calculate_total_cost();
	void display_cost_breakdown() const;
	float get_total_cost() const;
	void add_room_cost(roomcost* _room_cost);
	void set_utility_cost(float cost);
	void set_miscellaneous_cost(float cost);

};

#endif

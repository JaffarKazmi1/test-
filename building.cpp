#include "building.h"


building::building():building_name(),building_type(),location(),floorlist()
{
}
building::building(MyString _building_name, MyString _building_type, MyString _location, vector<floors*>& _floorlist)
	: building_name(_building_name), building_type(_building_type), location(_location), floorlist(_floorlist)
{
}
building::~building()
{
	for (floors* f : floorlist)
	{
		delete f;
	}
}
void building::display_building_info()const
{
	cout << "Building name : " << building_name << endl;
	cout << "Building type : " << building_type << endl;
	cout << "Building location : " << location << endl;

	for (int i = 0; i < floorlist.size(); i++)
	{
		cout << "--- Floor " << i + 1 << " ---" << endl;
		floorlist[i]->display_floor_info();
		cout << endl;
	}
}
void building::add_floor(floors* f)
{
	floorlist.push_back(f);
}
int building::get_floor_count()const
{
	return floorlist.size();
}
float building::get_building_cost()
{
	float total_cost = 0;
	float rate_per_sqft = 100.0f; 

	for (int i = 0; i < floorlist.size(); i++)
	{
		vector<room*> room_list = floorlist[i]->get_rooms();

		for (int j = 0; j < room_list.size(); j++)
		{
			total_cost += room_list[j]->get_area() * rate_per_sqft;
		}
	}

	return total_cost;
}

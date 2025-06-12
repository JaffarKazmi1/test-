#ifndef FLOORS_H
#define FLOORS_H
#include "MyString.h"
#include "room.h"
#include <vector>

class floors
{
	int num_of_floors;
	vector<room*> rooms;

public:
	floors();
	floors( int _num_of_floors, vector<room*>&_rooms);
	~floors();
	void add_room(room*_room);
	float floor_area()const;
	void display_floor_info()const;
	int get_floor_count()const;
	void input();
	int get_room_count()const;
	vector<room*> get_rooms() const;


};


#endif
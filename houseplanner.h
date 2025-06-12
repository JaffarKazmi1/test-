#ifndef  HOUSEPLANNER_H
#define HOUSEPLANNER_H
#include "MyString.h"
#include "room.h"
#include "roomplanner.h"
#include "furniture.h"
#include <vector>
#include <iostream>
using namespace std;


class houseplanner
{
	MyString housename;
	vector<room*>room_list;
	vector<roomplanner*>roomplanners;
	float total_area;
	float total_occupied_area;

public:
	houseplanner();
	houseplanner(MyString _housename, vector<room*>_room_list, vector<roomplanner*>_roomplanners, float _total_area, float _total_occupied_area);
	~houseplanner();
	void add_room(room* _room);
	void remove_room(const MyString& room_name);
	room* get_room(const MyString& room_name) const;
	void display_all_rooms() const;
	void add_furniture_from_room(const MyString& room_name, furniture*item);
	void display_furniture_in_room(const MyString& room_name) const;
	float get_total_area() const;
	float get_total_occupied_area() const;
	float get_overall_free_area() const;
	void display_house_summary() const;
	vector<room*> get_all_rooms() const;


};


#endif 
#ifndef  ROOMPLANNER_H
#define ROOMPLANNER_H
#include "MyString.h"
#include "room.h"
#include <vector>
#include "furniture.h"
#include <iostream>

class roomplanner
{
	room* room_reference;
	vector<furniture*> furniture_list;
	float occupied_area;
	float free_area;
	bool is_overcrowded;

public:
	roomplanner(room* _room);
	roomplanner();
	roomplanner(room* _room_reference,vector<furniture*>_furniture_list,float _occupied_area,float _free_area,bool _is_overcrowded);
	~roomplanner();
	void add_furniture(furniture* item);
	bool check_space_availability(float item_area);
	bool get_overcrowded_status() const;
	float get_free_area() const;
	float get_occupied_area();
	float get_area()const;
	room* get_room();
	void display_furniture()const;
};

#endif

#ifndef KITCHEN_H
#define KITCHEN_H
#include "room.h"
#include <iostream>
#include "MyString.h"
using namespace std;


class kitchen :public room
{
	int num_of_stoves;

public:
	kitchen();
	kitchen(MyString _name, float _width, float _height, float _length, int _doors, int _windows, bool _attached_bath, float _area, int _num_of_stoves);
	~kitchen();
	int get_stove_count()const;
	void display_room_info()const override;
	void input();

};

#endif 

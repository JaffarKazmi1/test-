#ifndef BEDROOM_H
#define BEDROOM_H
#include "room.h"
#include <iostream>
#include "MyString.h"
using namespace std;


class bedroom:public room
{
	int num_of_beds;

public:
	bedroom();
	bedroom(MyString _name, float _width, float _height, float _length, int _doors, int _windows, bool _attached_bath, float _area, int _num_of_beds);
	~bedroom();
	int get_num_of_beds()const;
	void display_room_info()const override;
	void input();

};

#endif 

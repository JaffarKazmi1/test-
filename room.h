#ifndef  ROOM_H
#define ROOM_H
#include <iostream>
#include "MyString.h"
using namespace std;


class room
{	
	MyString name;
	float width;
	float height;
	float length;
	int doors;
	int windows;
	bool attached_bath;
	float area;

public:
	room();
	room(MyString _name, float _width, float _height, float _length, int _doors, int _windows,bool _attached_bath,float _area);
	virtual ~room();
	float get_length()const;
	float get_width()const;
	virtual void display_room_info()const;
	void input();
	float get_area();
	MyString get_name()const;
	MyString get_room_name()const;

};

#endif 

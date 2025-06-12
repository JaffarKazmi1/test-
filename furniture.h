#ifndef  FURNITURE_H
#define FURNITURE_H
#include "MyString.h"

class furniture
{
	MyString type;
	float length;
	float height;
	float width;
	MyString room_assigned_to;
	bool movable;

public:
	furniture();
	furniture(MyString _type, float _length, float _height, float _width, MyString _room_assigned_to, bool _movable);
	~furniture();
	void display_furniture_info();
	float get_area()const;
	MyString get_name()const;

};

#endif 

#include "furniture.h"

MyString type;
float length;
float height;
float width;
MyString room_assigned_to;
bool movable;

furniture::furniture() :type(), length(), height(), width(), room_assigned_to(), movable()
{
}
furniture::furniture(MyString _type, float _length, float _height, float _width, MyString _room_assigned_to, bool _movable):type(_type),length(_length),
height(_height),width(_width),room_assigned_to(_room_assigned_to),movable(_movable)
{
}
furniture::~furniture()
{
}
void furniture::display_furniture_info()
{
	cout << "Furniture type : " << type << endl;
	cout << "Length : " << length << endl;
	cout << "height : " << height << endl;
	cout << "Length : " << length << endl;
	cout << "This furniture is assigned to " << room_assigned_to << endl;
	if (movable == 1)
	{
		cout << "This furniture is movable " << endl;
	}
	else
	{
		cout << "This furniture is not movable " << endl;
	}
}
float furniture::get_area()const
{
	return length * width;
}
MyString furniture::get_name()const
{
	return type;
}
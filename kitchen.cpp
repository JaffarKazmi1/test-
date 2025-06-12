#include "kitchen.h"

kitchen::kitchen() :room(), num_of_stoves()
{
}
kitchen::kitchen(MyString _name, float _width, float _height, float _length, int _doors, int _windows, bool _attached_bath, float _area, int _num_of_stoves) :
	room(_name, _width, _height, _length, _doors, _windows, _attached_bath, _area), num_of_stoves(_num_of_stoves)
{
}
kitchen::~kitchen()
{
}
int kitchen::get_stove_count()const
{
	return num_of_stoves;
}
void kitchen::display_room_info()const
{
	room::display_room_info();
	cout << "Number of stoves : " << num_of_stoves << endl;
}
void kitchen::input()
{
	room::input();
	cout << "Number of beds: ";
	cin >> num_of_stoves;
}

#include "bedroom.h"

bedroom::bedroom():room(),num_of_beds()
{
}
bedroom::bedroom(MyString _name, float _width, float _height, float _length, int _doors, int _windows, bool _attached_bath, float _area, int _num_of_beds):
	room(_name,_width,_height,_length,_doors,_windows,_attached_bath,_area),num_of_beds(_num_of_beds)
{
}
bedroom::~bedroom()
{
}
int bedroom::get_num_of_beds()const
{
	return num_of_beds;
}
void bedroom::display_room_info()const
{
	room::display_room_info();
	cout << "Number of beds : " << num_of_beds << endl;
}
void bedroom::input()
{
	room::input(); 
	cout << "Number of beds: ";
	cin >> num_of_beds;
}

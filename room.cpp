#include "room.h"


room::room():name(),width(),height(),length(),doors(),windows(),attached_bath('F'),area(length*width)
{
}
room::room(MyString _name, float _width, float _height, float _length, int _doors, int _windows,bool _attached_bath, float _area):name(_name),width(_width),height(_height),length(_length),
doors(_doors),windows(_windows),attached_bath(_attached_bath),area(_area)
{
}
room::~room()
{
}
float room::get_width()const
{
	return width;
}
float room::get_length()const
{
	return length;
}
void room:: display_room_info()const
{
	cout << "Room name : " << name << endl;
	cout << "Width : " << width << endl;
	cout << "Length : " << length << endl;
	cout << "Number of doors : " << doors << endl;
	cout << "Number of windows : " << windows << endl;
	cout << "Area : " << area << endl;

}
void room::input()
{
    MyString name;
    float length = 0;
    float width = 0;
    float height = 0;
    int windows = 0;
    int  doors = 0;
    bool hasAC = 0;

    cout << "Enter room name: " << endl;
    cin >> name;
    cout << "Enter dimensions (length width height): " << endl;
    cin >> length >> width >> height;
    cout << "Enter number of windows and doors: " << endl;
    cin >> windows >> doors;
    cout << "Has AC (1 for Yes, 0 for No): " << endl;
    cin >> hasAC;

    float area = length * width;
   
}
float room::get_area()
{
    return length * width;
}
MyString room::get_name()const
{
    return name;
}
MyString room::get_room_name()const
{
    return name;
}
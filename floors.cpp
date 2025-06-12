#include "floors.h"
#include "bedroom.h"
#include "kitchen.h"

floors::floors() :num_of_floors(),rooms()
{
}
floors::floors( int _num_of_floors, vector<room*>&_rooms) : num_of_floors(_num_of_floors), rooms(_rooms)
{
}
floors::~floors()
{
	for (auto r : rooms) 
	{
		delete r; 
	}
}
void floors::add_room(room* _room)
{
	rooms.push_back(_room);
}
float floors::floor_area()const
{
	float total_area = 0;

	for (int i = 0; i < rooms.size(); i++)
	{
		float length = rooms[i]->get_length();
		float width = rooms[i]->get_width();

		total_area = total_area + (length * width);
	}

	return total_area;
}
void floors::display_floor_info()const          
{
    for (int i = 0; i < rooms.size(); i++)
    {
        cout << "Information for Room # " << i + 1 << " : " << endl;
        if (rooms[i] != nullptr)
        {
            rooms[i]->display_room_info();
            cout << endl;
        }
        else
        {
            cout << "Warning: Room #" << i + 1 << " is null (possibly uninitialized or deleted)." << endl;
        }
    }
}
int floors::get_floor_count()const
{
	return num_of_floors;
}
void floors::input()
{

    cout << "Enter Floor Number: " << endl;
    cin >> num_of_floors;  

    int num_rooms;
    cout << "Enter Number of Rooms on this Floor: " << endl;
    cin >> num_rooms;

    for (int i = 0; i < num_rooms; ++i) 
    {
        cout << "Select Room Type (1. General Room, 2. Bedroom, 3. Kitchen): ";
        int choice = 0;
        cin >> choice;

        MyString name = 0;
        float length = 0;
        float width = 0;
        float height = 0;
        int windows = 0;
        int doors = 0;
        bool ac = 0;

        cout << "Enter Room Name: " << endl;
        cin >> name;
        cout << "Enter Dimensions (Length Width Height): " << endl;
        cin >> length >> width >> height;
        cout << "Enter Windows and Doors count: " << endl;
        cin >> windows >> doors;
        cout << "Has AC? (1/0): " << endl;
        cin >> ac;

        float area = length * width;

        room* r = nullptr;

        if (choice == 1)
        {
            r = new room(name, length, width, height, windows, doors, ac, area);
        }
        else if (choice == 2)
        {
            int beds;
            cout << "Enter number of beds: ";
            cin >> beds;
            r = new bedroom(name, length, width, height, windows, doors, ac, area, beds);
        }
        else if (choice == 3) 
        {
            bool stove;
            cout << "Has Stove? (1/0): ";
            cin >> stove;
            r = new kitchen(name, length, width, height, windows, doors, ac, area, stove);
        }

        if (r != nullptr)
        {
            add_room(r);
        }
    }
}
int floors::get_room_count()const
{
    return rooms.size();
}
vector<room*> floors::get_rooms() const
{
    return rooms;
}

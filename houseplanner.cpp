#include "houseplanner.h"


houseplanner::houseplanner():housename(),room_list(),roomplanners(),total_area(),total_occupied_area()
{
}
houseplanner::houseplanner(MyString _housename, vector<room*>_room_list, vector<roomplanner*>_roomplanners, float _total_area, float _total_occupied_area) :
	housename(_housename), room_list(_room_list), roomplanners(_roomplanners), total_area(_total_area), total_occupied_area(_total_occupied_area)
{
}
houseplanner::~houseplanner()
{
	for (room* r : room_list)
		delete r;

	for (roomplanner* rp : roomplanners)
		delete rp;
}
void houseplanner::add_room(room* _room)
{
	room_list.push_back(_room);
	roomplanners.push_back(new roomplanner(_room));
}
void houseplanner::remove_room(const MyString& room_name)
{
	for (int i = 0; i < room_list.size(); i++)
	{
		if (room_list[i]->get_room_name() ==(room_name))
		{
			delete room_list[i];
			room_list.erase(room_list.begin() + i);
			cout << "Room " << room_name << " is removed" << endl;
			return;
		}
	}
	cout << "room not found" << endl;
}
room* houseplanner::get_room(const MyString& room_name) const
{
	for (int i = 0; i < room_list.size(); i++)
	{
		if (room_list[i]->get_room_name()==(room_name))
		{
			return room_list[i];
		}
	}
	cout << "room not found" << endl;
	return nullptr;
}
void houseplanner::display_all_rooms() const
{
	if (room_list.empty())
	{
		cout << "No rooms have been added yet." << endl;
		return;
	}
	cout << "--- Room List ---" << endl;
	for (int i = 0; i < room_list.size(); i++)
	{
		cout << endl;
		cout << "Room #" << i + 1 << ":" << endl;

		room_list[i]->display_room_info();


		cout << endl;
	}
}
void houseplanner::add_furniture_from_room(const MyString& room_name, furniture*item)
{
	for (int i = 0; i < room_list.size(); i++)
	{
		if (room_list[i]->get_room_name()==(room_name))
		{
			roomplanners[i]->add_furniture(item);
			return;
		}
	}
	cout << "Furniture not found" << endl;
}
void houseplanner::display_furniture_in_room(const MyString& room_name) const
{
	for (int i = 0; i < room_list.size(); i++)
	{
		if (room_list[i]->get_room_name()==(room_name))
		{
			for (int j = 0; j < roomplanners.size(); j++)
			{
				if (roomplanners[j]->get_room()->get_room_name()==(room_name))
				{
					roomplanners[j]->display_furniture();
					return;
				}
			}
		}
	}
	cout << "room not found" << endl;
}
float houseplanner::get_total_area() const
{
	return total_area;
}
float  houseplanner::get_total_occupied_area() const
{
	return total_occupied_area;
}
float houseplanner::get_overall_free_area() const
{
	return total_area - total_occupied_area;
}
void houseplanner::display_house_summary() const
{
	cout << endl;
	cout << "===== House Summary =====" << endl;
	cout << "House name: " << housename << endl;

	if (room_list.empty())
	{
		cout << "No rooms added yet." << endl;
	}
	else
	{
		for (int i = 0; i < room_list.size(); i++)
		{
			cout << endl;
			cout << "Room #" << i + 1 << " Information:" << endl;
			room_list[i]->display_room_info();

			if (i < roomplanners.size() && roomplanners[i] != nullptr)
			{
				cout << "Furniture in this room:" << endl;
				roomplanners[i]->display_furniture();
			}
			else
			{
				cout << "No room planner data available for this room." << endl;
			}
			cout << "----------------------------" << endl;
		}
	}

	cout << endl;
	cout << "Total house area: " << total_area << " sqft" << endl;
	cout << "Total occupied area: " << total_occupied_area << " sqft" << endl;
	cout << "Free area available: " << (total_area - total_occupied_area) << " sqft" << endl;
	cout << "==============================" << endl;
	cout << endl;

}
vector<room*> houseplanner::get_all_rooms() const {
	return room_list;
}

#include "roomplanner.h"

roomplanner::roomplanner():room_reference(nullptr),furniture_list(),occupied_area(),free_area(),is_overcrowded()
{
}
roomplanner::roomplanner(room* _room_reference, vector<furniture*>_furniture_list, float _occupied_area, float _free_area, bool _is_overcrowded) :
	room_reference(_room_reference), furniture_list(_furniture_list), occupied_area(_occupied_area), free_area(_free_area), is_overcrowded(_is_overcrowded)
{
}
roomplanner::~roomplanner()
{
}
float roomplanner::get_area()const
{
    return occupied_area + free_area;
}
void roomplanner::add_furniture(furniture* item)
{
    if (check_space_availability(item->get_area())) 
    {
        furniture_list.push_back(item);

        occupied_area = occupied_area + item->get_area();

        free_area = free_area - item->get_area();

        is_overcrowded = occupied_area > (room_reference->get_length() * room_reference->get_width()) * 0.8; 
    }
    else
    {
        cout << "Not enough space to add this furniture item: " << item->get_name() << endl;
        delete item; 
    }
}
bool roomplanner::check_space_availability(float item_area) 
{
    return item_area <= free_area;
}
bool roomplanner::get_overcrowded_status() const 
{
    return is_overcrowded;
}
float roomplanner::get_free_area() const
{
    return free_area;
}
float roomplanner::get_occupied_area()
{
    return occupied_area;
}
room* roomplanner::get_room()
{
    return room_reference;
}
void roomplanner::display_furniture()const
{
    for (int i = 0; i < furniture_list.size(); i++)
    {
        furniture_list[i]->display_furniture_info();
    }
}
roomplanner::roomplanner(room* _room) : room_reference(_room) {}

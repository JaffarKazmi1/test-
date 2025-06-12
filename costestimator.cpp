#include "costestimator.h"


costestimator::costestimator() :utility_cost(),room_cost(),material_cost(),labor_cost(),miscellaneous_cost(),rooms()
{
}
costestimator::costestimator(utilityservice _utility_cost, roomcost _room_cost, material _material_cost, labor _labor_cost, misccost _miscellaneous_cost, vector<roomcost*> _rooms):
	utility_cost(_utility_cost), room_cost(_room_cost),material_cost(_material_cost),labor_cost(_labor_cost),miscellaneous_cost(_miscellaneous_cost),rooms(_rooms)
{
}
costestimator::~costestimator()
{
    for (roomcost* rc : rooms)
    {
        delete rc;
    }
}
void costestimator::calculate_total_cost()
{
    float total = 0;

    for (int i = 0; i < rooms.size(); i++) 
    {
        if (rooms[i]) 
        {
            rooms[i]->calculate_room_cost();
            total += rooms[i]->get_room_total_cost();
        }
    }

    
    total = total + utility_cost.get_cost();       
    total = total + material_cost.get_cost();
    total = total + labor_cost.get_cost();
    total = total + miscellaneous_cost.get_cost();

    
    cout << "Total Estimated Construction Cost: " << total << endl;
}
void costestimator::display_cost_breakdown() const
{
    cout << "--- Room-wise Cost Breakdown ---" << endl;
    for (int i = 0; i < rooms.size(); i++) 
    {
        if (rooms[i]) 
        {
            rooms[i]->display_room_cost();
            cout << endl;
        }
    }

    cout << "--- Additional Cost Breakdown ---" << endl;
    cout << "Utility Cost: " << utility_cost.get_cost() << endl;
    cout << "Material Cost: " << material_cost.get_cost() << endl;
    cout << "Labor Cost: " << labor_cost.get_cost() << endl;
    cout << "Miscellaneous Cost: " << miscellaneous_cost.get_cost() << endl;

}
float costestimator::get_total_cost() const
{
    float total = 0;

    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i])
            total += rooms[i]->get_room_total_cost();
    }

    total += utility_cost.get_cost();
    total += material_cost.get_cost();
    total += labor_cost.get_cost();
    total += miscellaneous_cost.get_cost();

    return total;
}
void costestimator::add_room_cost(roomcost* _room_cost) 
{
	rooms.push_back(_room_cost);
}
void costestimator::set_utility_cost(float cost) 
{
    utility_cost.set_cost(cost);
}
void costestimator::set_miscellaneous_cost(float cost) 
{ 
    miscellaneous_cost.set_cost(cost); 
}

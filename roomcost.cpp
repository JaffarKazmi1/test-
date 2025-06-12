#include "roomcost.h"


roomcost::roomcost():associated_room(),material_cost_per_sqft(),labor_cost_per_sqft(),room_total_cost()
{
}
roomcost::roomcost(room* _associated_room, float _material_cost_per_sqft, float _labor_cost_per_sqft, float _room_total_cost) :
	associated_room(_associated_room), material_cost_per_sqft(_material_cost_per_sqft), labor_cost_per_sqft(_labor_cost_per_sqft), 
	room_total_cost(_room_total_cost)
{
}
roomcost::~roomcost()
{
}
void roomcost::calculate_room_cost()
{
	float room_area = associated_room->get_length() * associated_room->get_width();
	float total_per_sqft = material_cost_per_sqft + labor_cost_per_sqft;

	room_total_cost = room_area * total_per_sqft;
}
float roomcost::get_room_total_cost()const
{
	return room_total_cost;
}
void  roomcost::display_room_cost()const
{
	cout << "Total cost for this room = " << room_total_cost << endl;
}
#include "labor.h"

labor::labor() :labor_type(),cost_per_hour()
{
}
labor::labor(MyString _labor_type, float _cost_per_hour) :labor_type(_labor_type),cost_per_hour(_cost_per_hour)
{
}
labor::~labor()
{
}
void labor:: display_labor_info()const
{
	cout << "Labor type : " << labor_type << endl;
	cout << "Cost per hour : " << cost_per_hour << endl;
}
MyString labor::get_labor_type()const
{
	return labor_type;
}
float labor::get_cost()const
{
	return cost_per_hour;
}
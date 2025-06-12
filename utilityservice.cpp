#include "utilityservice.h"

utilityservice::utilityservice() :service_name(), monthly_cost(), smart_enabled()
{
}
utilityservice::utilityservice(MyString _service_name, float _monthly_cost, bool _smart_enabled) :service_name(_service_name), monthly_cost(_monthly_cost)
, smart_enabled(_smart_enabled)
{
}
utilityservice::~utilityservice()
{
}
void utilityservice::display_info()const
{
	cout << "Service name : " << service_name << endl;
	cout << "Monthly cost : " << monthly_cost << endl;
	if (smart_enabled == true)
	{
		cout << "Smartly enabled" << endl;
	}
	else
	{
		cout << "Not Smartly enabled" << endl;
	}
}
void utilityservice::enable_smart()
{
	smart_enabled = true;
}
float utilityservice::get_cost()const
{
	return monthly_cost;
}
void utilityservice::set_cost(float _cost) 
{
	monthly_cost = _cost;
}
utilityservice::utilityservice(MyString _service_type, float _service_cost)
	: service_name(_service_type), monthly_cost(_service_cost)
{
}
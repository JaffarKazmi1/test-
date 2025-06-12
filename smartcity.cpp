#include "smartcity.h"

smartcity::smartcity():city_name(), zones()
{
}
smartcity::smartcity(MyString _city_name, vector<cityzone*>_zones) :city_name(_city_name), zones(_zones)
{
}
smartcity::~smartcity() 
{
}
void smartcity::add_zone(cityzone *_zone)
{
	zones.push_back(_zone);
}
void smartcity::display_smart_city()const
{
	cout << "City name : " << city_name << endl;
	cout << "Zones information : " << endl;
	for (int i = 0; i < zones.size(); i++)
	{
		zones[i]->display_zone_summary();
		cout << endl;
	}
}
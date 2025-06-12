#include "cityzone.h"

cityzone::cityzone():zone_name(), infrastructures(), utilities_in_zone()
{
}
cityzone::cityzone(MyString _zone_name, vector<infrastructure*> _infrastructures, vector<utilityservice*> _utilities):zone_name(_zone_name),
infrastructures(_infrastructures), utilities_in_zone(_utilities)
{
}
cityzone::~cityzone()
{
	for (int i = 0; i < infrastructures.size(); i++)
	{
		delete infrastructures[i];
	}

	for (int i = 0; i < utilities_in_zone.size(); i++)
	{
		delete utilities_in_zone[i];
	}
}
void cityzone::add_infrastructure(infrastructure* _infrastructures)
{
	infrastructures.push_back(_infrastructures);
}
void cityzone::add_utility(utilityservice* _utilities)
{
	utilities_in_zone.push_back(_utilities);
}
void cityzone ::display_zone_summary()const
{
	cout << "Zone name : " << zone_name << endl;
	cout << "Infrastructure details : " << endl;
	for (int i = 0; i < infrastructures.size(); i++)
	{
		infrastructures[i]->display_info();
		cout << endl;
	}
	cout << "Utilities details : " << endl;
	for (int i = 0; i < utilities_in_zone.size(); i++)
	{
		utilities_in_zone[i]->display_info();
		cout << endl;
	}
}
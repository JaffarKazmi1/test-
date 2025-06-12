#include "trafficsystem.h"

trafficsystem::trafficsystem():num_of_signals(), smart_monitoring_enabled()
{
}
trafficsystem::trafficsystem(int _num_of_signals, bool _smart_monitoring_enabled):num_of_signals(_num_of_signals), 
smart_monitoring_enabled(_smart_monitoring_enabled)
{
}
trafficsystem::~trafficsystem()
{
}
void trafficsystem::display_info()const
{
	cout << "Num of signals : " << num_of_signals << endl;
	if (smart_monitoring_enabled == true)
	{
		cout << "Smart monitoring enabled" << endl;
	}
	else
	{
		cout << "Not Smart monitoring enabled" << endl;
	}
}
void  trafficsystem::toggle_monitoring()
{
	smart_monitoring_enabled = !smart_monitoring_enabled;
	if (smart_monitoring_enabled)
	{
		cout << "Traffic monitoring has been ENABLED." << endl;
	}
	else
	{
		cout << "Traffic monitoring has been DISABLED." << endl;
	}
}
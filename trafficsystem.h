#ifndef  TRAFFICSYSTEM_H
#define TRAFFICSYSTEM_H
#include <iostream>
using namespace std;


class trafficsystem
{
	int num_of_signals;
	bool smart_monitoring_enabled;


public:
	trafficsystem();
	trafficsystem(int _num_of_signals, bool _smart_monitoring_enabled);
	~trafficsystem();
	void display_info()const;
	void toggle_monitoring();

};

#endif 

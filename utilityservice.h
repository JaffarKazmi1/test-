#ifndef UTILITYSERVICE_H
#define UTILITYSERVICE_H
#include "MyString.h"
#include <iostream>
using namespace std;

class utilityservice
{
	MyString service_name;
	float monthly_cost;
	bool smart_enabled;

public:
	utilityservice();
	utilityservice(MyString _service_type, float _service_cost);
	utilityservice(MyString _service_name, float _monthly_cost, bool _smart_enabled);
	~utilityservice();
	void display_info()const;
	void enable_smart();
	float get_cost()const;
	void set_cost(float _cost);
};

#endif

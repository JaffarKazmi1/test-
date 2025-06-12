#ifndef  CITYZONE_H
#define CITYZONE_H
#include "MyString.h"
#include "infrastructure.h"
#include "utilityservice.h"
#include <iostream>
#include <vector>
using namespace std;


class cityzone
{
	MyString zone_name;
	vector<infrastructure*> infrastructures;
	vector<utilityservice*> utilities_in_zone;

public:
	cityzone();
	cityzone(MyString _zone_name, vector<infrastructure*> _infrastructures, vector<utilityservice*> _utilities);
	~cityzone();
	void add_infrastructure(infrastructure* _infrastructures);
	void add_utility(utilityservice* utilities);
	void display_zone_summary()const;

};


#endif

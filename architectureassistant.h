#ifndef  ARCHITECTUREASSISTANT_H
#define ARCHITECTUREASSISTANT_H
#include "building.h"
#include "houseplanner.h"
#include "costestimator.h"
#include "smartcity.h"
#include <iostream>
#include <vector>
using namespace std;

class architectureassistant
{
    building* building_module;
    houseplanner* house_module;
    costestimator* cost_module;
    vector<cityzone*> smartcity_zones;
    houseplanner house;

public:
    architectureassistant();
    ~architectureassistant();
    void manage_building_design();
    void manage_house_planner();
    void manage_smart_city();
    
    void run();


};

#endif 

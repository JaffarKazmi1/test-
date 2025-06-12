#include "building.h"
#include "floors.h"
#include "room.h"
#include "MyString.h"
#include "furniture.h"
#include "roomplanner.h"
#include "person.h"
#include "address.h"
#include "houseplanner.h"
#include "roomcost.h"
#include "material.h"
#include "labor.h"
#include "misccost.h"
#include "costestimator.h"
#include "bedroom.h"
#include "kitchen.h"
#include "utilityservice.h"
#include "smartentity.h"
#include "infrastructure.h"
#include "trafficsystem.h"
#include "cityzone.h"
#include "smartcity.h"
#include "architectureassistant.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    architectureassistant obj;

    obj.run();

    return 0;
}
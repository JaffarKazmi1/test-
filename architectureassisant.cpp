#include "architectureassistant.h"

architectureassistant::architectureassistant():building_module(), house_module(), cost_module(), smartcity_zones(),house()
{
}
architectureassistant::~architectureassistant()
{
}
void architectureassistant::manage_building_design()
{
    try 
    {
        MyString building_name;
        MyString building_type;
        MyString location;
        int total_floors = 0;

        cout << "Enter Building Name: " << endl;
        cin >> building_name;

        cout << "Enter Building Type: " << endl;
        cin >> building_type;

        cout << "Enter Location: " << endl;
        cin >> location;

        cout << "Enter Total Number of Floors: ";
        if (!(cin >> total_floors) || total_floors <= 0)
        {
            throw invalid_argument("Invalid number of floors entered. Please enter a positive integer.");
        }

        vector<floors*> floor_list;

        for (int i = 0; i < total_floors; i++)
        {
            cout << endl;
            cout << "--- Entering Details for Floor " << i + 1 << " ---" << endl;

            floors* fl = new(nothrow) floors;
            if (!fl) 
            {
                throw bad_alloc();
            }

            fl->input();
            floor_list.push_back(fl);
        }

        
        building b(building_name, building_type, location, floor_list);

        cout << endl;
        cout << "--- Building Summary ---" << endl;
        b.display_building_info();

        float cost = b.get_building_cost();
        cout << "Estimated Building Cost (default rate): " << cost << " units" << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Input Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    catch (const bad_alloc& e)
    {
        cout << "Memory Allocation Error: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        cout << "An error occurred: " << e.what() << endl;
    }

}
void architectureassistant::manage_house_planner()
{
    houseplanner planner;
    int choice = 0;

    do 
    {
        cout << endl;
        cout << "--- House Planner Menu ---" << endl;
        cout << "1. Add Room" << endl;
        cout << "2. Remove Room" << endl;
        cout << "3. Display All Rooms" << endl;
        cout << "4. Add Furniture to Room" << endl;
        cout << "5. Display Furniture in Room" << endl;
        cout << "6. Display House Summary" << endl;
        cout << "7. Check house cost estimate " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1) 
        {
            int type = 0;
            cout << "Select Room Type to Add:" << endl;
            cout << "1. General Room" << endl;
            cout << "2. Bedroom" << endl;
            cout << "3. Kitchen" << endl;
            cout << "Enter choice: ";
            cin >> type;

            MyString name;
            float length = 0;
            float width = 0;
            float height = 0;
            int windows = 0;
            int doors = 0;
            bool ac = false;

            cout << "Enter Room Name: ";
            cin >> name;
            cout << "Enter Dimensions (Length Width Height): ";
            cin >> length >> width >> height;
            cout << "Enter Number of Windows and Doors: ";
            cin >> windows >> doors;
            cout << "Has AC? (1 = Yes, 0 = No): ";
            cin >> ac;

            float area = length * width;
            room* r = nullptr;

            if (type == 1)
            {
                r = new room(name, length, width, height, windows, doors, ac, area);
            }
            else if (type == 2)
            {
                int beds = 0;
                cout << "Enter number of beds: ";
                cin >> beds;
                r = new bedroom(name, length, width, height, windows, doors, ac, area, beds);
            }
            else if (type == 3)
            {
                bool stove = false;
                cout << "Has Stove? (1 = Yes, 0 = No): ";
                cin >> stove;
                r = new kitchen(name, length, width, height, windows, doors, ac, area, stove);
            }
            else
            {
                cout << "Invalid room type selected. Room not added." << endl;
            }

            if (r != nullptr)
            {
                planner.add_room(r);
                cout << "Room added successfully." << endl;
            }
        }
        else if (choice == 2)
        {
            MyString room_name;
            cout << "Enter the name of the room to remove: ";
            cin >> room_name;

            planner.remove_room(room_name);
        }
        else if (choice == 3)
        {
            planner.display_all_rooms();
        }
        else if (choice == 4)
        {
            MyString room_name;
            MyString furniture_type;
            float length = 0;
            float width = 0;
            float height = 0;
            bool movable = 0;

            cout << "Enter room name to add furniture to: " << endl;
            cin >> room_name;

            if (planner.get_room(room_name) == nullptr)
            {
                cout << "Room \"" << room_name << "\" not found. Cannot add furniture." << endl;
                return;
            }

            cout << "Enter furniture type: " << endl;
            cin >> furniture_type;
            cout << "Enter dimensions (length width height): " << endl;;
            cin >> length >> width >> height;
            cout << "Is it movable (1/0)? " << endl;;
            cin >> movable;

            furniture* f = new furniture(furniture_type, length, height, width, room_name, movable);
            planner.add_furniture_from_room(room_name, f);

            cout << "Furniture added successfully to room \"" << room_name << "\"." << endl;
        }
        else if (choice == 5) 
        {
            MyString room_name;
            cout << "Enter room name to display furniture: ";
            cin >> room_name;

            if (planner.get_room(room_name) == nullptr)
            {
                cout << "Room \"" << room_name << "\" not found. Please try again." << endl;
            }
            else
            {
                cout << endl;
                cout << "--- Furniture in Room: " << room_name << " ---" << endl;
                planner.display_furniture_in_room(room_name);
            }
        }
        else if (choice == 6)
        {
            planner.display_house_summary();
        }
        else if(choice == 7)
        {
            costestimator estimator;

            planner.display_all_rooms(); 

            for (room* r : planner.get_all_rooms()) 
            {
                float area = r->get_area();
                cout << endl;
                cout << "Room: " << r->get_name() << " (Area: " << area << " sqft)" << endl;

                float material_rate = 0;
                float labor_rate = 0;
                cout << "Enter material cost per sqft: ";
                cin >> material_rate;
                cout << "Enter labor cost per sqft: ";
                cin >> labor_rate;

                float total = area * (material_rate + labor_rate);
                roomcost* rc = new roomcost(r, material_rate, labor_rate, total);
                estimator.add_room_cost(rc);
            }
            float utility = 0;
            float misc = 0;
            cout << endl;
            cout << "Enter total utility cost: " << endl;
            cin >> utility;
            cout << "Enter miscellaneous cost: " << endl;
            cin >> misc;

            estimator.set_utility_cost(utility);
            estimator.set_miscellaneous_cost(misc);

            estimator.calculate_total_cost();
            estimator.display_cost_breakdown();
        }
        else if (choice != 0) 
        {
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 0);

    cout << "Exiting House Planner." << endl;;
}
void architectureassistant::manage_smart_city()
{
    int choice = 0;

    do {
        cout << endl;
        cout << "--- Smart City Planner Menu ---" << endl;
        cout << "1. Add New City Zone" << endl;
        cout << "2. Add Infrastructure to Zone" << endl;
        cout << "3. Add Utility Service to Zone" << endl;
        cout << "4. Display All Zones Summary" << endl;
        cout << "0. Exit Smart City Planner" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            MyString zone_name;
            cout << "Enter name of the new city zone: ";
            cin >> zone_name;

            cityzone* new_zone = new cityzone(zone_name, {}, {});
            smartcity_zones.push_back(new_zone);
            cout << "City zone added successfully." << endl;
        }
        else if (choice == 2)
        {
            if (smartcity_zones.empty())
            {
                cout << "No zones available. Please add a zone first." << endl;
                continue;
            }

            cout << "Select a zone index to add infrastructure (0 to " << smartcity_zones.size() - 1 << "): ";
            int index;
            cin >> index;

            if (index >= 0 && index < smartcity_zones.size())
            {
                int infra_choice = 0;
                cout << "Choose Infrastructure Type to Add:" << endl;
                cout << "1. Manual Infrastructure (Name/Type/Area)" << endl;
                cout << "2. Building Design Simulator" << endl;
                cout << "3. House Planning Assistant" << endl;
                cout << "Enter your choice: ";
                cin >> infra_choice;

                if (infra_choice == 1)
                {
                    MyString name, type;
                    float area;

                    cout << "Enter infrastructure name: ";
                    cin >> name;
                    cout << "Enter infrastructure type: ";
                    cin >> type;
                    cout << "Enter area covered (in sqft): ";
                    cin >> area;

                    infrastructure* infra = new infrastructure(name, type, area);
                    smartcity_zones[index]->add_infrastructure(infra);
                    cout << "Infrastructure added successfully." << endl;
                }
                else if (infra_choice == 2)
                {
                    cout << endl;
                    cout << "Launching Building Design Simulator..." << endl;
                    manage_building_design();

                    MyString name, type;
                    float area;
                    cout << "Enter name of the building added to zone: ";
                    cin >> name;
                    type = "Building";

                    cout << "Enter estimated area (sqft): ";
                    cin >> area;

                    infrastructure* building_infra = new infrastructure(name, type, area);
                    smartcity_zones[index]->add_infrastructure(building_infra);
                    cout << "Building added as infrastructure to the zone." << endl;
                }
                else if (infra_choice == 3)
                {
                    cout << endl;
                    cout << "Launching House Planning Assistant..." << endl;
                    manage_house_planner();

                    MyString name, type = "House";
                    float area;

                    cout << "Enter name of the house added to zone: ";
                    cin >> name;
                    cout << "Enter estimated area (sqft): ";
                    cin >> area;

                    infrastructure* house_infra = new infrastructure(name, type, area);
                    smartcity_zones[index]->add_infrastructure(house_infra);
                    cout << "House added as infrastructure to the zone." << endl;
                }
                else
                {
                    cout << "Invalid infrastructure choice!" << endl;
                }
            }
            else
            {
                cout << "Invalid zone index!" << endl;
            }
        }
        else if (choice == 3)
        {
            if (smartcity_zones.empty())
            {
                cout << "No zones available. Please add a zone first." << endl;
                continue;
            }

            cout << "Select a zone index to add utility (0 to " << smartcity_zones.size() - 1 << "): ";
            int index;
            cin >> index;

            if (index >= 0 && index < smartcity_zones.size())
            {
                MyString utility_type;
                float cost;

                cout << "Enter utility type (e.g., Electricity, Water, Internet): ";
                cin >> utility_type;
                cout << "Enter utility service cost: ";
                cin >> cost;

                utilityservice* utility = new utilityservice(utility_type, cost);
                smartcity_zones[index]->add_utility(utility);
                cout << "Utility service added successfully." << endl;
            }
            else
            {
                cout << "Invalid zone index!" << endl;
            }
        }
        else if (choice == 4)
        {
            if (smartcity_zones.empty())
            {
                cout << "No zones to display." << endl;
            }
            else
            {
                for (int i = 0; i < smartcity_zones.size(); i++)
                {
                    cout << endl;
                    cout << "--- Zone " << i + 1 << " Summary ---" << endl;
                    smartcity_zones[i]->display_zone_summary();
                }
            }
        }
        else if (choice != 0)
        {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    cout << "Exiting Smart City Planner." << endl;
}
void architectureassistant::run()
{
    int choice = 0;
    do
    {
        cout << endl;
        cout << "--- Architecture Assistant Main Menu ---" << endl;
        cout << "1. Building Design Simulator" << endl;
        cout << "2. House Planning Assistant" << endl;
        cout << "3. Smart City Planner" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            manage_building_design();

        }
        else if (choice == 2)
        {
            manage_house_planner();
        }
        else if (choice == 3)
        {
            manage_smart_city();
        }
        else if (choice == 0)
        {
            cout << "Exiting Architecture Assistant." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

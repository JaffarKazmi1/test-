#include "infrastructure.h"

infrastructure::infrastructure() :name(), type(), area_covered()
{
}
infrastructure::infrastructure(MyString _name, MyString _type, float _area_covered) :name(_name), type(_type), area_covered(_area_covered)
{
}
infrastructure::~infrastructure()
{
}
void infrastructure::display_info()const
{
	cout << "Infrastructure name : " << name << endl;
	cout << "Infrastructure type : " << type << endl;
	cout << "Area covered : " << area_covered << endl;
}
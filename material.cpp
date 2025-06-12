#include "material.h"


material::material():material_name(),cost_per_sqft()
{
}
material::material(MyString _material_name, float _cost_per_sqft) :material_name(_material_name), cost_per_sqft(_cost_per_sqft)
{
}
material::~material()
{
}
void material::display_material_info()const
{
	cout << "Material name :" << material_name << endl;
	cout << "Cost per sqft : " << cost_per_sqft << endl;
}
MyString material::get_material_name()const
{
	return material_name;
}
float material::get_cost()const
{
	return cost_per_sqft;
}
void material::set_cost(float _cost)
{
	cost_per_sqft = _cost;
}
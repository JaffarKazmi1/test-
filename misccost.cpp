#include "misccost.h"

MyString costtype;
float amount;

misccost::misccost():costtype(),amount()
{
}
misccost::misccost(MyString _costtype, float _amount):costtype(_costtype),amount(_amount)
{
}
misccost::~misccost()
{
}
float misccost::get_cost()const
{
	return amount;
}
MyString misccost::get_costtype()const
{
	return costtype;
}
void misccost::set_cost(float _cost)
{
	amount = _cost;
}
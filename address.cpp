#include <iostream>
using namespace std;
#include "address.h"
#include "MyString.h"

Address::Address(int _house_number, MyString _city, MyString _society) :house_number(_house_number), city(_city), society(_society)
{
	
}
Address::Address(const Address& obj) :house_number(obj.house_number), city(obj.city), society(obj.society)
{
}
ostream& operator << (ostream& out, const Address& std)
{

	cout << "House number : " << std.house_number << endl;
	cout << "City " << std.city << endl;
	cout << "Society : " << std.society << endl;

	return out;
}
istream& operator >> (istream& in, Address& std)
{

	cout << "Enter House number : " << endl;
	cin >> std.house_number;
	cout << "Enter City " << endl;
	cin >> std.city;
	cout << "Enter Society : " << endl;
	cin >> std.society;

	return in;
}
int Address::getHouseNo() const { return house_number; }
const MyString Address::getCity() const { return city; }
const MyString Address::getSociety() const { return society; }
Address::~Address()
{
	//cout << "Address destructor called" << endl;
}
Address::Address() :house_number(0), city(), society()
{
}
void Address::display()const
{
	cout << "House number : " << house_number << endl;
	cout << "City : " << city << endl;
	cout << "Society : " << society << endl;
}
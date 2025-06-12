#ifndef ADDRESS_H
#define ADDRESS_H
#include "MyString.h"
#include <iostream>
using namespace std;


class Address
{
	int house_number;
	MyString city;
	MyString society;

public:
	Address();
	Address(int _house_number, MyString _city, MyString _society);
	Address(const Address& obj);
	friend ostream& operator << (ostream& out, const Address& std);
	friend istream& operator >> (istream& in, Address& std);
	int getHouseNo() const;
	const MyString getCity() const;
	const MyString getSociety() const;
	void display()const;
	~Address();
};
#endif
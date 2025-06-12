#include "person.h"

Person::Person() 
{
	email = {};
	fullName = {};
	address = {};
	age = {};
}

Person::Person(const Person& other) 
{
	this->email = other.email;
	this->fullName = other.fullName;
	this->address = other.address;
	this->age = other.age;
}

Person::Person(const MyString& email,const MyString& name, const Address& addr,int age)
{
	this->email = email;
	this->fullName = name;
	this->address = addr;
	this->age = age;
}

Person& Person::operator=(const Person& other) 
{
	this->email = other.email;
	this->fullName = other.fullName;
	this->address = other.address;
	this->age = other.age;
	return *this;
}

void Person::display() const 
{
	cout << this->email << endl;
	cout << this->fullName << endl;
	this->address.display();
}
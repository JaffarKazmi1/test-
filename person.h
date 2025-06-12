#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "MyString.h"
#include "Address.h"
#include "string.h"
using namespace std;

class Person 
{
	MyString email;
	MyString fullName;
	Address address;
	int age;

public:
	Person();
	Person(const Person& other);
	Person(const MyString& email, const MyString& name, const Address& addr,int age);
	Person& operator=(const Person& other);

	void display() const;
};

#endif
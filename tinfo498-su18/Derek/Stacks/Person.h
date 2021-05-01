#pragma once
#include "stdafx.h"

using std::string;

class Person
{
private:
	string _last;
	string _first;
	int _age;
public:
	Person(string LastName, string FirstName, int age)
		:_last(LastName), _first(FirstName), _age(age) {};
	friend std::ostream& operator << (std::ostream& os, const Person& person) {
		return os << person._last << ", " << person._first << "; Age: " << person._age;
	}
	
};


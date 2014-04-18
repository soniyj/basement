/**
 * C++ Overloading Operators Example
 *
 * @author:      Marco "soniyj" Matascioli
 * @date:        18 April 2014
 * @file:        operator.cpp
 *
 * Copyright (C) 2014. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */

#include<iostream>

using namespace std;

/* Simple Class Definition */
class Test {
public:
	Test(int);
	int x;
	int y;
};


class TestOperator {
public:
	TestOperator(int);
	TestOperator& operator=(const TestOperator&);

	int x;
	int y;
};

/* End Definition */

/* Class Implementation */

Test::Test(int x) {
	this->x = x;
	this->y = x+2;
}

TestOperator::TestOperator(int x) {
	this->x = x;
	this->y = x+2;
}

TestOperator& TestOperator::operator=(const TestOperator &rhs) {
	// Check self-assignement
	if(this == &rhs)
		return *this;
	this->x = rhs.x;
	return *this;
}

/* End Implementation */

int main() {
	Test a(2), b(3);
	TestOperator c(2), d(3);	
	
	cout << "After\n";
	cout << "a: " << a.x << " | " << a.y << endl;
	cout << "b: " << b.x << " | " << b.y << endl;
	cout << "c: " << c.x << " | " << c.y << endl;
	cout << "d: " << d.x << " | " << d.y << endl;

	a=b;
	c=d;

	cout << "Before\n";
	cout << "a: " << a.x << " | " << a.y << endl;
	cout << "b: " << b.x << " | " << b.y << endl;
	cout << "c: " << c.x << " | " << c.y << endl;
	cout << "d: " << d.x << " | " << d.y << endl;

	cout << "End\n";
	return 0;
}

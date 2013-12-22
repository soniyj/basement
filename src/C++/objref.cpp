/**
 * C++ Passing Object by Reference
 *
 * @author:      Marco "soniyj" Matascioli
 * @date:        05 November 2013
 * @file:        objref.cpp
 *
 * Copyright (C) 2013. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */

#include <iostream>

using namespace std;

/* Simple Class */
class Test {
public:
    Test();
    int x;
};

Test::Test() {
    this->x = 0;
}
/* End Class */

void change1(Test& m) {
    m.x = 1;
}

void change2(Test& m) {
    m.x = 2;
}

void change3(Test* m) {
    m->x = 3;
}

void change4(Test* m) {
    m->x = 4;
}

Test* change5(Test* m) {
    m = new Test();
    m->x = 5;
    return m;
}

Test* change6(int x) {
    Test *m = new Test();
    m->x = x;
    return m;
}

int main() {
    Test m1;
    Test *m2;
    Test m3;
    Test *m4;
    Test *m5;
    Test *m6;
    
    m2 = new Test();
    m4 = new Test();

    cout << "Before 1: " << m1.x << endl;
    cout << "Before 2: " << m2->x << endl;
    cout << "Before 3: " << m3.x << endl;
    cout << "Before 4: " << m4->x << endl;
    cout << "\n";

    change1(m1);
    change2(*m2);
    change3(&m3);
    change4(m4);

    /* Object created here */
    m5 = change5(m5);
    m6 = change6(6);

    cout << "After 1: " << m1.x << endl;
    cout << "After 2: " << m2->x << endl;
    cout << "After 3: " << m3.x << endl;
    cout << "After 4: " << m4->x << endl;
    cout << "After 5: " << m5->x << endl;
    cout << "After 6: " << m6->x << endl;
    cout << "\n";
    
    return 0;
}

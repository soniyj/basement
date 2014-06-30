/**
 * Get how many prime numbers there are into the range [k...j]
 *  
 * @author:      Marco "soniyj" Matascioli
 * @date:        15 February 2014
 * @file:        prime.cpp
 * 
 * Copyright (C) 2013. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */
 
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstring>
#include <map>

unsigned static short r=1;

/* Define a general function to be used by a user's choice */
#define REC(X,Y) (recursive(X,Y))
#define ITR(X,Y) (iterative(X,Y))
#define FUNC(X,Y) (r==2 ? (ITR(X,Y)) : (REC(X,Y)))

using namespace std;

/* Recursive */
bool recursive(int n, int kn) {
    if(kn < 2)
        return true;
    else
        if(n % kn == 0)
            return false;
        else
            return recursive(n,kn-1);
}

/* Iterative */
bool iterative(int n, int kn) {
    bool p = true;
    for(int i=kn; i>=2; i--) {
        if((n % i)==0) p = false;
    }
    return p;
}

int main(int argc, char **argv) {
    unsigned int k,j,tot=0;
    int radi;
    
    cout << "Insert two numbers where the second is bigger than the first one\n";
    cout<<"1): ";
    cin >> j;
    cout<<"2): ";
    cin >> k;
    
    /* Checking input */
    j=abs(j);
    k=abs(k);
    if(j>=k) {
        cout << "Error: second number must be bigger than the first number\n";
        return 1;
    }
    
    cout << "Choose 1 for recursive (default) and 2 for iterative: ";
    cin >> r;
    
    /* Find prime numbers */
    for(int i=j; i<=k; i++) {
        radi=sqrt(i);

        if(FUNC(i,radi)) {
            cout << "\t" << i << " is prime" << endl;
            tot++;
        }
        else
            cout << " " << i << " is not prime" << endl; 
    }
    
    printf("\nThere are %d prime numbers into the range [%d..%d]\n", tot, j, k);
        
    cout << "Press <e> + <return> to end\n";
    cin >> r;
    
    return 0;
}

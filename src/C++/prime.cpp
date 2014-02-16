/**
 * Get how many prime numbers there are into a range [k...j].
 * 
 * 
 * @author:      Marco "soniyj" Matascioli
 * @date:        15 February 2014
 * @file:        prime.cpp
 * 
 * Copyright (C) 2013. Marco "soniyj" Matascioli
 * This code is released under the term of the GPL v2.
 */
 
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool recursive(int n, int kn) {
    if(kn < 2)
        return true;
    else
        if(n % kn == 0)
            return false;
        else
            return recursive(n,kn-1);
}

bool iterative(int n, int kn) {
    bool p = true;
    for(int i=kn; i>=2; i--) {
        if((n % i)==0) p = false;
    }
    return p;
}

int main(int argc, char **argv) {
    unsigned int k,j,r=1,tot=0;
    int radi;
    
    cout << "Insert two numbers where the second is bigger than the first one\n";
    cout<<"1): ";
    cin >> k;
    cout<<"2): ";
    cin >> j;
    
    /* Checking input */
    k=abs(k);
    j=abs(j);
    if(k>=j) {
        cout << "Error: second number must be bigger than the first number\n";
        return 1;
    }
    
    cout << "Choose 1 for recursive (default) and 2 for iterative: ";
    cin >> r;
    
    /* Find prime numbers */
    for(int i=k; i<=j; i++) {
        radi=sqrt(i);
        //if(primo(i,radi)) {
        if(second(i,radi)) {
            cout << "\t" << i << " is prime" << endl;
            tot++;
        }
        else
            cout << " " << i << " is not prime" << endl; 
    }
    
    cout << "\n";
    cout << "\nSono stati trovati " << tot << " numeri primi nell'intervallo assegnato " << k << " - " << j <<endl;
}
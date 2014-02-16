/**
 * Get how many prime numbers there are into a range [k...j]
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
    unsigned int k,j,r=1,tot=0;
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
    if(r==2)
#define R 2
        cout << "lullo\n";
    
#if r>=1
#define R 3
#endif
    
    cout << "aa " << R << endl;
    /* Find prime numbers */
    for(int i=j; i<=k; i++) {
        radi=sqrt(i);
#ifndef R
        if(recursive(i,radi)) {
            cout << "Recursive\n";
#else
        if(iterative(i,radi)) {
            cout << "Iterative\n";
#endif
            cout << "\t" << i << " is prime" << endl;
            tot++;
        }
        else
            cout << " " << i << " is not prime" << endl; 
    }
    
    printf("\nThere are %d into the range [%d..%d]\n", tot, j, k);
        
    cout << "Press Enter to end";
    cin >> r;
    
    return 0;
}
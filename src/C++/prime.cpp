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

int main12345(int argc, char **argv) {
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

class CTest {
public:
    CTest();
    //CTest(int);
    CTest(const CTest& orig);
    int x;
    string str;
    void operator() (int el) {
        cout << "> " << x;
    }
};

CTest::CTest() {
    x=0;
}

/*CTest::CTest(int x) {
    this->x = x;
}*/

CTest::CTest(const CTest& orig) {
    
}

void cazzo(int i) {
    if(i==0)
        cout << " " << i;
    else
        cout << "acuna matata\n";
}

bool f1(int i) {
    //return(i==i+1)==true;
    return ((i%2)==1);
}

bool f2(int i, int j) {
    return (i==j);
}

int mainqazxswedc() {
    vector<CTest*> v_test;
    vector<CTest*>::iterator it;
    for(int i=0;i<3;i++) {
        CTest *c = new CTest();
        //v_test.push_back(&c);
        //v_test.push_back(*c);
        v_test.push_back(c);
    }
    cout << "lula\n";
    for(int i=0;i<v_test.size();i++)
        cout << "->" << v_test[i]->x;
    cout << endl;
    /*for(int i=0;i<3;i++) {
        CTest *c = v_test[i];
        delete c;
    }*/
    cout << "lula\n";
    vector<int> i_v_test;
    vector<int>::iterator it2;
    for(int i=0; i<5; i++) {
        if(i>0 && i<=2)
            i_v_test.push_back(1);
        else
            i_v_test.push_back(i);
    }
    for(int i=0; i<5; i++)
        cout << " #> " << i_v_test[i];
    cout << endl;
    bool z = for_each(i_v_test.begin(),i_v_test.end(), f1);
    cout << "1.> " << z;
    cout << endl;
    it2 = find_if(i_v_test.begin(),i_v_test.end(), f1);
    if(it2 != i_v_test.end())
        cout << "2.> " << *it2 << endl;
    it2 = adjacent_find(i_v_test.begin(), i_v_test.end(), f2);
    if(it2 != i_v_test.end())
        cout << "3.> " << *it2 << " " << (it2 - i_v_test.begin()) << endl;
   
    return 0;
}

int comp(const void *t1, const void *t2) {
    char *m1 = (char*)t1;
    char *m2 = (char*)t2;
    return (strcmp(m1,m2));
}

std::vector<std::string> getBitStrings(unsigned int n)
{
    std::vector<std::string> result;

    if (n <= 1)
    {
        result.push_back("0");
        result.push_back("1");
    }
    else
    {   // recurse, then add extra bit chars
        std::vector<std::string> sub = getBitStrings(n-1);
        for (std::vector<std::string>::const_iterator it = sub.cbegin(); it != sub.cend(); ++it)
        {
            result.push_back(*it+'0');
            result.push_back(*it+'1');
        }
    }
    return result;
}

bool IsOdd (int i) {
    if (i==1) return true;
    return false;
}

void printOffsetOfRuns(const string& s) {
	bool first = true;
	int i = 0, j, n = s.size();

	for(; i < n; i = j) {
		for(j = i+1; j < n && s[j] == s[i]; ++j) ;
		//now j - i is the repeat times of s[i]
		if(j - i > 1){
			if(first) first = false;
			else printf(", ");
			printf("%d", i);
		}
	}
}


class  A
{
public:
 void name() const { std::cout << "A::name" << std::endl;}
 virtual ~A() {}
};
class B : public virtual A
{
public:
 void name() const { std::cout << "B::name" << std::endl;}
};

void test() {
    cout << "acuna matata" << endl;
}

int solution1(const vector<int> &A) {
    int len = 0;
    vector<int> B(A.begin(),A.end());
    sort(B.begin(),B.end());
    int max = 0;
    for(int j=0; j<B.size(); j++) {
        for(int i=0; i<B.size()-1;i++) {
            if(j==i) continue;
            cout << "L: " << B[i] << " " << B[j] << " | " << B[i]-B[j] << "\n";
            if(abs(B[i]-B[j])<=1)
                len += 1;
            else
                break;
        }
        if(len >= max) max=len;
        len=0;
    }
    return max;
}

int solution(const string &S){
    char test[S.length()];
    sprintf(test,"%s",S.c_str());
    int pos=0,num=0;
    for(int i=0; i<S.length(); i++) {
        std::rotate( test, test+pos, test+sizeof(test)-1 );
        if(!strcmp(S.c_str(),test))
            num+=1;
        pos=1;
    }

    return num;
}

char * string_rotate_right( char *s )
{
   size_t n = strlen( s );

   if ( n > 1 )
   {
      char c = s[n - 1];
      memmove( s + 1, s, n - 2 );
      *s = c;
   }
   cout << "SS " << s << "\n";
   return ( s );
}

int main(int argc, char *argv []) {
    cout << "Nonnt co cul a for\n";
    int myints[] = {6,10,6,9,7,8};
    vector<int> myvector (myints, myints+6);
    cout << solution("byebye");
    /*char test[] = "codility";
    string_rotate_right(test);*/
    cout << "\n";
    std::string s1="abcdef";
    int pos=0;
for (int i=0; i<s1.length(); i++){ 
s1.append(s1.substr(0, pos)); 
s1=s1.substr(pos, s1.length()); 
std::cout<< s1.c_str()<<"\n"; pos=1;}
    return 0;
}

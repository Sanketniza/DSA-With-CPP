
#include<iostream>
using namespace std;
 
int main() { 

    int n = 5;
    int *p = &n;
    int **p1 = &p;

    cout << "Printing all the value :"  << endl;
    cout << n << endl;
    cout << *p << endl;
    cout << **p1 << endl << endl;

    cout << "Printing all the address's of value 5:"<< endl << endl;
    cout << &n << endl;
    cout << p << endl;
    cout << *p1 << endl << endl;

    cout << "Printing all the address of address :" << endl;
    cout << &n << endl; // address of n
    cout << &p1 << endl; // address of *p
    cout << &*p1 << endl << endl; // address of **p

    return 0;
}
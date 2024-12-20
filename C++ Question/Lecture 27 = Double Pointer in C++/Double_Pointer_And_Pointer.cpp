#include<iostream>
using namespace std;
 
 void update(int **p2)
 {
    // kuchh change hoga : NO
   // p2 = p2 + 1;


    // kuchh change hoga : NO
    // *p2 = *p2 + 1;

    // kuchh change hoga : NO
    **p2 = **p2 + 1;

 }
int main() { 

    int n = 5;
    int *p = &n;
    int **p1 = &p;

    cout << "Before incrementing the value : " << endl;
    cout << n << endl;
    cout << *p << endl;
    cout << **p1 << endl << endl;

    (*p)++;  // value of n = 6
    (**p1)++; // value of n = 7

    cout << "After incrementing the value : " << endl;
    cout << n << endl;
    cout << *p << endl;
    cout << **p1 << endl << endl;

    update(p1);
    // update(p);

    cout << "After incrementing the value : " << endl;
    cout << n << endl;
    cout << *p << endl;
    cout << **p1 << endl << endl;

    return 0;
}
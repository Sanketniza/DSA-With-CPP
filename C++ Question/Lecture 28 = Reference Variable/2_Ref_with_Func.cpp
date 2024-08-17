#include<iostream>
using namespace std;
 
 void increment2(int &y) { // pass by reference
    y++;  // increment
 }

 void increment(int x) { // pass by value
    x++;  
 }

int main() { 

    int x = 10;
    cout << "Before calling function : " << x << endl;
    increment(x);
    cout << "After calling function : " << x << endl; // not incremented value of x , because this is pass by value

// -----------------------------------------------------------------------------------------------------------

    int y = 10;
    cout << "Before calling function : " << y << endl;
    increment2(y);
    cout << "After calling function : " << y << endl; // incremented value of y , because this is pass by reference

    return 0;
}
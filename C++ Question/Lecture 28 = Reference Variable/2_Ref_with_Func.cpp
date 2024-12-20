#include<iostream>
using namespace std;
 
 int increment3(int z) { // pass by value
    z++;  
    return z;
 }

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

    //--------------------------------------------------------------------------------

    int y = 10;
    cout << "Before calling function : " << y << endl;
    increment2(y);
    cout << "After calling function : " << y << endl; // incremented value of y , because this is pass by reference

    // -------------------------------------------------------------------------------

    int z = 100;
    cout << "Before calling function : " << z << endl;
    increment3(z);
    cout << "After calling function : " << z << endl;
    
    int val = increment3(z);
    cout << "Know value is become : " << val << endl;


    return 0;
}
#include<iostream>
using namespace std;
 // bad method 

 
 int score = 23;

 void a(int id) {

    cout << id << endl;
    cout << score << endl;
 }

int main() { 

    int i = 33;
    cout << "Testing the local variable "  << endl;

    a(i);
   cout << a;

    return 0;
}
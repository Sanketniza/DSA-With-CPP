#include<iostream>
using namespace std;
 // bad method 

 
 int score = 23;

 void a(int id) {

    cout << id << endl;
    cout << score << end;
 }

int main() { 

    int i = 33;
    cout << "Testing the local variable "  << endl;

   int ans = a(i);
   cout << ans;

    return 0;
}
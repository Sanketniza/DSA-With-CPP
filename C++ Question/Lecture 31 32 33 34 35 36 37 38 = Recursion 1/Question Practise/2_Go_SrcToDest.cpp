#include<iostream>
using namespace std;

void reachHome(int scr , int dest) {

    // base case

    cout << "scr " << scr << " dest " << dest << endl;

    if(scr == dest) {
        cout << "I reached home" << endl;
        return;
    }

    scr++;

    // recursive case
    reachHome(scr , dest);
}
 
int main() { 

    int scr , dest;

    cout << "Enter the number of elements : " ;
    cin >> scr >> dest;

    reachHome(scr, dest);


    return 0;
}
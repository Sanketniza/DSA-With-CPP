
#include<iostream>
using namespace std;

void reach(int s , int e) {

    cout << "source at : " << s << " and destination at : " << e << endl;

    // base case 
    if(s == e) {
        cout << "I reached to my destination which is : " << e << endl; 
        return;
    } 

    s++;
    reach( s, e);

}

int main() {

    int s = 2;
    int e = 6;

    reach(s , e);
 return 0;
}
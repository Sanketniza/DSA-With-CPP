#include<iostream>
using namespace std;
 
 //^ reached at  Nth Stairs by taking 1 step or 2 step

int print(int n) {

    if(n < 0) {
        return 0;
    }

    if(n == 0) {
        return 1;
    }

    int a = print (n - 1) + print(n - 2);
    return a;
}

int main() { 

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int ans = print(n);
    cout << ans << " ";

    return 0;
}
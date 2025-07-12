#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int dice ,int face , int target) {

    // base cases
    if(target < 0) return 0;

    if(dice == 0 && target == 0) return 1;

    if(dice == 0 && target != 0) return 0;

    if(dice != 0 && target == 0) return 0;

    // recursive case
    int ans = 0;
    for(int i = 1; i <= face; i++) {

        ans += solve(dice - 1, face , target - i);
    }

    return ans;
}

int main() {

    int m = 6; int n = 3; int x = 12;

    int ans = solve(n , m , x);
    cout << "ans is : " << ans << endl;

    
     
     

 return 0;
}
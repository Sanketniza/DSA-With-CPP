#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveM(int n ) {
    
    if(n <= 1 )
        return 1;

    int ans = 0;

    //* for each node as root
    //* left subtree * right subtree
    //* i -> root node  , n - i - 1 -> right subtree , n - i - 1 -> left subtree

    for(int i = 1; i <= n; i++) {
        ans += solveM(i - 1 ) * solveM(n - i);
    }

    return ans;
}
int main() {

    int n;
    cout << "Enter the number of nodes : ";
    cin  >> n;

    vector<int> dp(n + 1 ,  -1);
    cout << "ans is : " << solveM(n) << endl;

 return 0;
}
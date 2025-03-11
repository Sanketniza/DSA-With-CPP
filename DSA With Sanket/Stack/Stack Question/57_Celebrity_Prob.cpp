/* 
   ? lecture 57: The celebrity problem
   ? link : https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

   A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

    Note: Follow 0-based indexing.

    Examples:

    Input: mat[][] =[[0 1 0],
                    [0 0 0], 
                    [0 1 0]]
    Output: 1
    Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 

    Input: mat[][] = [[0 1],
                    [1 0]]
    Output: -1
    Explanation: The two people at the party both know each other. None of them is a celebrity.
    Expected Time Complexity: O(n2)
    Expected Auxiliary Space: O(1)
 */

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool know(vector<vector<int>>& mat, int a, int b) {
    if(mat[a][b] == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = mat.size();

    // Create a stack and push elements
    stack<int> s;
    for(int i = 0; i < n; i++) {
        s.push(i);
        cout << "stack size is " << s.size() << endl;
    }

    // Find potential celebrity
    while (s.size() > 1) {
        cout << "stack size is " << s.size() << endl;

        int a = s.top();
        cout << "a is " << a << endl;
        s.pop();

        int b = s.top();
        cout << "b is " << b << endl;
        s.pop();

        if(know(mat, a, b)) {
            cout << "b is pushed" << endl;
            s.push(b);
        }
        else {
            s.push(a);
            cout << "a is pushed" << endl;
        }
    }

    int ans = s.top();
    cout << "ans is " << ans << endl;

    // Verify if the potential celebrity is actually a celebrity
    int zeroCount = 0;
    int oneCount = 0;

    for(int i = 0; i < n; i++) {

        if(i != ans) {
            
            if(mat[ans][i] == 0) {
                zeroCount++;
            }

            if(mat[i][ans] == 1) {
                oneCount++;
            }

        }
    }

    if(zeroCount == n - 1 && oneCount == n - 1) {
        cout << "Celebrity found: " << ans << endl;
        return ans;
    }
    else {
        cout << "No celebrity found" << endl;
        return -1;
    }

    int ans = s.top();

    // Verify if the potential celebrity is actually a celebrity
    
    
    // check row 
    // bool rowCheck = false;
    // int zeroCount = 0;

    // for(int i = 0; i < n; i++) {
    //     if(mat[ans][i] == 0) {
    //         zeroCount++;
    //     }
    // }

    // if(zeroCount == n) {
    //     rowCheck = true;
    // }

    // // check column

    // bool colCheck = true;
    // int oneCount = 0;

    // for(int i = 0; i < n; i++) {
    //     if(mat[i][ans] == 1) {
    //         oneCount++;
    //     }
    // }

    // if(oneCount == n - 1) {
    //     colCheck = true;
    // }

    // if(rowCheck && colCheck) {
    //     cout << "The celebrity is " << ans << endl;
    // }
    // else {
    //     cout << "There is no celebrity" << endl;
    // }

    return 0;
}
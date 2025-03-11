#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());

    for(int i = arr.size() - 1; i >= 0; i--) {

        int curr = arr[i];

        while(s.top() >= curr) {
            s.pop();
        }


        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int main() {

    vector<int> arr = {2, 3 , 1 ,21, 4, 33};
    stack<int> s;

    for(int i = 0; i < arr.size(); i++) {

        for(int j = i + 1; j < arr.size(); j++) {

            if(arr[j] < arr[i]) {
                s.push(1);
                break;
            }

            else {
                s.push(-1);
            }
        }
    }


    // simple upproach
    stack<int> temp = s;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    // using stack

    vector<int> ann = solve(arr);

    cout << "The next smaller element for each of the array elements is: ";
    for(auto i : ann) {
        cout << i << " ";
    }


 return 0;
}
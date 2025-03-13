#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    string a = "aabaabbcbcc";

    unordered_map<char , int> count;
    queue<char> q;
    string ans = "";

    for(int i = 0; i < a.length(); i++) {

        char ch = a[i];
        count[ch]++;
        q.push(ch);

        while(!q.empty()) {

            if(count[q.front()] > 1) {
                q.pop();
            }

            else {
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()) {
            ans.push_back('#');
        }
    }

    cout << ans << endl;

 return 0;
}
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main() {

    string A = "aabb";
    int n = A.length();

    unordered_map<char , int> c;
    queue<char> q;
    string ans = "";

    for(int i = 0; i < n; i++) {

        char ch = A[i];
        c[ch]++;
        // unordered_map<char , int> c = {{'a' , 1} , {'b' , 2}};

        q.push(ch);

        while (!q.empty()) {

            if(c[q.front()] > 1) {
                // repeating character
                q.pop();
            }

            else {
                // non repeating character
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()) {
            ans.push_back('#');
        }

        cout << "ans is " << ans << endl;

    }

    cout << "ans is " << ans << endl;


 return 0;
}
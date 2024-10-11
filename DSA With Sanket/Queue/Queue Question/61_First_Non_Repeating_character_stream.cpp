/* 
    ? First Non-Repeating character in stream
    ? https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

    Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every i you need to consider the string from starting position till ith position.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.
 */

#include<iostream>
#include<unordered_map>
#include<queue>
#include<map>
using namespace std;

int main() {

    string A = "aabbbc";
    int n = A.length();

    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for(int i = 0; i < n; i++) {
        
        cout << "count map is " << endl;
        for(auto it = count.begin(); it != count.end(); it++) {
            cout << it->first << " : " << it->second << endl;
        }

        char ch = A[i];
        cout << "count of " << ch << " is " << count[ch] << endl;
        count[ch]++;
        q.push(ch);
        cout << "element in queue is " << q.front() << endl;

        while (!q.empty()) {

            if(count[q.front()] > 1) {
                cout << "before pop count of " << q.front() << " is " << count[q.front()] << endl;
                q.pop();
                cout << "after pop count of " << q.front() << " is " << count[q.front()] << endl;
            }

            else {
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()) {
            ans.push_back('#');
        }

        cout << "ans is " << ans << endl;
    }

    cout << ans << endl;

 return 0;
}

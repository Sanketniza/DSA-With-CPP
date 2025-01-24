
/* 
    ? lecture 80: Longest Common Prefix
    ? https://www.naukri.com/code360/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

    Problem statement
You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings. If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 3000
1 <= |ARR[i]| <=1000

Each string consists of only lowercase letters.

Time limit: 1 sec
Sample Input 1:
2
4
coding codezen codingninja coder
3
night ninja nil 
Sample Output 1:
cod
ni
Explanation of sample input 1:
For the first test case, 
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.

For the second test case,
The longest common prefix among all the given strings is “ni” as it is present as a prefix in all strings. Hence, the answer is “ni”.
Sample Input 2:
2
3
applejuice applepie apple
4
car cus cart carat
Sample Output 2:
apple
c
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// time complexity : O(n * m)
// space complexity : O(1)

string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";

    // Traverse all characters of the first string in arr
    for (int i = 0; i < arr[0].length(); i++) {
        char ch = arr[0][i];
        bool match = true;

        // Compare the ch with the rest of the strings' characters
        for (int j = 1; j < n; j++) {
            if (arr[j].size() <= i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }

        if (match == false) {
            break;
        } else {
            ans.push_back(ch);
        }
    }

    return ans;
}

int main() {
    vector<string> arr1 = {"coding", "codezen", "codingninja", "coder"};
    vector<string> arr2 = {"night", "ninja", "nil"};
    vector<string> arr3 = {"applejuice", "applepie", "apple"};
    vector<string> arr4 = {"car", "cus", "cart", "carat"};

    cout << longestCommonPrefix(arr1, arr1.size()) << endl; // Output: "cod"
    cout << longestCommonPrefix(arr2, arr2.size()) << endl; // Output: "ni"
    cout << longestCommonPrefix(arr3, arr3.size()) << endl; // Output: "apple"
    cout << longestCommonPrefix(arr4, arr4.size()) << endl; // Output: "c"

    return 0;
}
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;
    int n = s.length();

    while (right < n) {
        if (seen.find(s[right]) == seen.end()) {
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            seen.erase(s[left]);
            left++;
        }
    }
    return maxLen;
}

// Example usage and dry run
int main() {
    string s = "abcabcbb";
    cout << "Input: " << s << endl;
    int result = lengthOfLongestSubstring(s);
    cout << "Output: " << result << endl; // Should print 3
    return 0;
}
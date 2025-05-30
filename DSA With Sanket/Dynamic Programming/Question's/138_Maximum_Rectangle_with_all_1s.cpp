/* 
    ? 138: Maximum Rectangle with all 1's
    ? https://leetcode.com/problems/maximal-rectangle/

    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



    Example 1:


    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.
    Example 2:

    Input: matrix = [["0"]]
    Output: 0
    Example 3:

    Input: matrix = [["1"]]
    Output: 1
 


 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxi = INT_MIN;

        vector<int> histrogram (matrix[0].size() , 0);

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < histrogram.size(); j++) {

                if(matrix[i][j] == '1') {
                    histrogram[j]++;
                }

                else{
                    histrogram[j] = 0;
                }
            }

            maxi = max(maxi , largestRectangleArea(histrogram));
        }

        return maxi;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}
// Time Complexity: O(N*M)
// Space Complexity: 
// N = Number of rows
// M = Number of columns
// O(M) = Space Complexity
// O(N) = Space Complexity
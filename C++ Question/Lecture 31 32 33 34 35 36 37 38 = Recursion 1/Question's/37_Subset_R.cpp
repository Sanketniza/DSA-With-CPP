/* 
78. Subsets

^    Given an integer array nums of unique elements, return all possible 
^    subsets
^     (the power set).
^    
^    The solution set must not contain duplicate subsets. Return the solution in any order.
^    
^     
^    
^    Example 1:
^    
^    Input: nums = [1,2,3]
^    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
^    Example 2:
^    
^    Input: nums = [0]
^    Output: [[],[0]]
^    
 */

#include<iostream>
#include<vector>
using namespace std;

void solve (vector<int> nums , vector<vector<int>> &ans, vector<int> output, int index) {
    
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(nums , ans , output , index + 1);

    // include 

    int element = nums[index];
    output.push_back(element);
    solve(nums , ans , output , index + 1);
    
}
 
int main() { 

    vector<int> nums = {1,2,3};
    
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(nums, ans, output, index);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
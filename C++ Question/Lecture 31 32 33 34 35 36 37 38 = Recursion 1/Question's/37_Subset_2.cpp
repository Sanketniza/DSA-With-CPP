/* 
? https://www.geeksforgeeks.org/problems/subset-sum-ii/1
    Subset II
Difficulty: MediumAccuracy: 50.0%Submissions: 11K+Points: 4Average Time: 30m
You are given an integer array nums that may contain duplicates. Your task is to return all possible subsets. Return only unique subsets and they can be in any order.

Note: The individual subsets should be sorted.

Example:

Input: 
nums = [1,2,2] 
Output: 
[[],[1],[1,2],[1,2,2],[2],[2,2]]
Explanation: 
We can have subsets ranging from length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {

private:

    void solve(vector<int>& arr, int index, vector<int> output, set<vector<int>>& ans) {

        if (index >= arr.size()) {

            vector<int> sortedOutput = output;
            sort(sortedOutput.begin(), sortedOutput.end());
            ans.insert(sortedOutput);
            return;
        }

        solve(arr, index + 1, output, ans);

        int element = arr[index];
        output.push_back(element);
        solve(arr, index + 1, output, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& arr) {
        set<vector<int>> ansSet;
        vector<int> output;

        solve(arr, 0, output, ansSet);

        vector<vector<int>> ans(ansSet.begin(), ansSet.end());
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 2};
    std::vector<std::vector<int>> result = sol.subsets(nums);

    std::cout << "Subsets:" << std::endl;
    for (const auto& subset : result) {
        std::cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            std::cout << subset[i];
            if (i < subset.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
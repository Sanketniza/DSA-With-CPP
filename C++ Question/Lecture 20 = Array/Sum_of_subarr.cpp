#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    std::vector<int> maxSubarraySum(std::vector<int>& arr) {
        int ans = INT_MIN;
        int start = 0;
        int end = 0;
        int temp_start = 0;

        for (int i = 0; i < arr.size(); i++) {
            int sum = 0;
            temp_start = i; // Start of the current subarray

            for (int j = i; j < arr.size(); j++) {
                sum += arr[j];

                if (sum > ans) {
                    ans = sum;
                    start = temp_start;
                    end = j;
                }
            }
        }

        std::vector<int> result;
        for (int i = start; i <= end; i++) {
            result.push_back(arr[i]);
        }
        return result;

        // or

        // int max_so_far = arr[0];
        // int max_ending_here = arr[0];

        // for (int i = 1; i < arr.size(); i++) {
            
        //     max_ending_here = max(arr[i], max_ending_here + arr[i]);
        //     max_so_far = max(max_so_far, max_ending_here);
            
        // }

        // return max_so_far;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    vector<int> result1 = sol.maxSubarraySum(arr1);
    cout << "Max subarray: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    vector<int> arr2 = {-2, -4};
    vector<int> result2 = sol.maxSubarraySum(arr2);
    cout << "Max subarray: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    vector<int> arr3 = {5, 4, 1, 7, 8};
    vector<int> result3 = sol.maxSubarraySum(arr3);
    cout << "Max subarray: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
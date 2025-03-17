#include <iostream>
#include <vector>
#include <climits>

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
    }
};

int main() {
    Solution sol;
    std::vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    std::vector<int> result1 = sol.maxSubarraySum(arr1);
    std::cout << "Max subarray: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {-2, -4};
    std::vector<int> result2 = sol.maxSubarraySum(arr2);
    std::cout << "Max subarray: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr3 = {5, 4, 1, 7, 8};
    std::vector<int> result3 = sol.maxSubarraySum(arr3);
    std::cout << "Max subarray: ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
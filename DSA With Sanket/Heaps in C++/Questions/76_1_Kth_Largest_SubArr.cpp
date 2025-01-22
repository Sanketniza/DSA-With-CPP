/* 
	? lecture: 76 : kth largest subarray
	? link: https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

	Problem statement
Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
3 3
3 -2 5
2 2
4 1
Sample output 1 :
3
4
Explanation of Sample output 1 :
For the first test case, 
Sum of [0, 0] = 3
Sum of [0, 1] = 1
Sum of [0, 2] = 6
Sum of [1, 1] = -2
Sum of [1, 2] = 3
Sum of [2, 2] = 5
All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 
int main() { 
    
    // todo: first approach
    // & time complexity : O(n^2 log n) time complexity : O(n^2) 
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;

    int n = arr.size();

	vector<int> v;

	for(int i = 0; i < n ; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += arr[j];
			v.push_back(sum);	
		}
	}

	sort(v.begin() , v.end());

   

    cout << v[v.size() - k] << endl;

    // todo: second approach
	// & time complexity : O(n log k)
	// & space complexity : O(k)

	 vector<int> arrr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int kk = 3;
	priority_queue<int, vector<int> , greater<int> > mini;

	int n = arrr.size();

	for(int i = 0; i < n ; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += arr[j];

				if(mini.size() < kk) {
					mini.push(sum);	
				}

				else {
					if(sum > mini.top()){
						mini.pop();
						mini.push(sum);
					}
				}
		}
	}

	cout <<  mini.top();

    return 0;
}
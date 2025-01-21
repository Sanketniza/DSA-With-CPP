
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
/* 
   ? lecture 75 : merge two binary max heap
   ? link ; https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

   Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}

 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heap(vector<int> &v , int n , int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && v[left] > v[largest]) {
        largest = left;
    }

    if(right < n && v[right] > v[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(v[i], v[largest]);
        heap(v, n, largest);
    }
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> v2 = {1, 2, 3, 4};

    vector<int> ans;

    for(auto i:v) {
        ans.push_back(i);
    }

    for(auto i:v2) {
        ans.push_back(i);
    }

    int n = ans.size();

    for(int i = n / 2 - 1; i >= 0; i--) {
        heap(ans , n , i);
    }

    cout << "element in heap are " << endl; 
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
        cout << endl;

 return 0;

}
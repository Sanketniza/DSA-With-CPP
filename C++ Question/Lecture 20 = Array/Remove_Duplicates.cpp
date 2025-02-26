#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to remove duplicates using array approach
void removeDuplicatesArray(int arr[], int &n) {
    if (n <= 1) return;
    
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[j] != arr[i]) {
            j++;
            arr[j] = arr[i];
        }
    }
    n = j + 1;
}

// Function to remove duplicates using vector and set
vector<int> removeDuplicatesVector(vector<int>& arr) {
    
    set<int> s(arr.begin(), arr.end());
    
    vector<int> result(s.begin(), s.end());
    
    return result;
}

int main() {
    // Example 1 using array
    int arr1[] = {2, 2, 3, 3, 7, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Original array 1: ";
    for(int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    removeDuplicatesArray(arr1, n1);
    
    cout << "After removing duplicates (array): ";
    for(int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // Example 2 using vector
    vector<int> arr2 = {2, 2, 5, 5, 7, 7};
    cout << "\nOriginal array 2: ";
    for(int num : arr2) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> result = removeDuplicatesVector(arr2);
    
    cout << "After removing duplicates (vector): ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    // Example 3
    vector<int> arr3 = {8, 7};
    cout << "\nOriginal array 3: ";
    for(int num : arr3) {
        cout << num << " ";
    }
    cout << endl;
    
    result = removeDuplicatesVector(arr3);
    
    cout << "After removing duplicates (vector): ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

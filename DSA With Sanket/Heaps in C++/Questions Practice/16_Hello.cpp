

#include <bits/stdc++.h>
using namespace std;

// ? time comp = O(n log k)
// ? space comp = O(k)

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

int main() {

    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int arr3[] = {11, 13, 15, 17, 19};
    int arr4[] = {12, 14, 16, 18, 20};
    int arr5[] = {21, 23, 25, 27, 29};

    int* arrays[] = {arr1, arr2, arr3, arr4, arr5};
    int sizes[] = {sizeof(arr1) / sizeof(arr1[0]), 
                   sizeof(arr2) / sizeof(arr2[0]), 
                   sizeof(arr3) / sizeof(arr3[0]), 
                   sizeof(arr4) / sizeof(arr4[0]), 
                   sizeof(arr5) / sizeof(arr5[0])};

    cout << "size is : " << sizeof(sizes) / sizeof(arrays[0]) << endl;               

    int K = sizeof(arrays) / sizeof(arrays[0]);
    cout << "K is : " << K << endl;

    int totalSize = 0;
    for (int i = 0; i < K; ++i) {
        // cout << "size of array " << i << " is : " << sizes[i] << endl;
        totalSize += sizes[i];
    }

    cout << "total size is : " << totalSize << endl;

    int result[totalSize]; // The  array with size of the total number of elements [25]
    int index = 0;

    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Step 1: Insert the first element of each array into the min-heap
    for (int i = 0; i < K; ++i) {
        
        if (sizes[i] > 0) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        result[index++] = current.value;

        if (current.elementIndex + 1 < sizes[current.arrayIndex]) {
            minHeap.push({arrays[current.arrayIndex][current.elementIndex + 1], current.arrayIndex, current.elementIndex + 1});
        }
    }

    // Step 3: Print the sorted array
    for (int i = 0; i < totalSize; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
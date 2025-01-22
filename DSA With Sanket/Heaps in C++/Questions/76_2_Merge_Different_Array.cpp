
/* 
    You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

 */

/* #include <bits/stdc++.h>
using namespace std;

int main() {

    // todo: first approach 
   
        Time Complexity: ( O(N \log N) )
        Space Complexity: ( O(N) )
    

    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int arr3[] = {11, 13, 15, 17, 19};
    int arr4[] = {12, 14, 16, 18, 20};
    int arr5[] = {21, 23, 25, 27, 29};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    int n = n1 + n2 + n3 + n4 + n5;
    
    int arr[n];
    int index = 0;

    // Step 2: Insert all elements into the answer array
    for (int i = 0; i < n1; i++) {
        arr[index++] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        arr[index++] = arr2[i];
    }
    for (int i = 0; i < n3; i++) {
        arr[index++] = arr3[i];
    }
    for (int i = 0; i < n4; i++) {
        arr[index++] = arr4[i];
    }
    for (int i = 0; i < n5; i++) {
        arr[index++] = arr5[i];
    }

    // Step 3: Sort the answer array
    sort(arr, arr + n);

    // Step 4: Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

 


    return 0;
} */

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
    int K = sizeof(arrays) / sizeof(arrays[0]);

    int totalSize = 0;
    for (int i = 0; i < K; ++i) {
        totalSize += sizes[i];
    }

    int result[totalSize];
    int index = 0;

    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Step 1: Insert the first element of each array into the min-heap
    for (int i = 0; i < K; ++i) {
        if (sizes[i] > 0) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Step 2: Extract the minimum element and insert the next element from the same array
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
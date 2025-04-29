#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap {
    
     public:
        int arr[100];
        int size;

        Heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val) {

            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1) {

                int parent = index / 2;

                if(arr[parent] < arr[index]) {
                    swap( arr[parent] , arr[index]);
                    index = parent;
                }

                else {
                    return;
                }
            }
        }

        void deletion() {

            if(size == 0) {
                cout << "Nothing to delete" << endl;
                return;
            }

            // step 1 : put last element at root
            arr[1] = arr[size];

            // step 2 : remove last element
            size--;

            // step 3 : take root node to its correct position
            int i = 1;

            while(i < size) {

                int leftIndex = 2 * i; // left child of i
                int rightIndex = 2 * i + 1; // right child of i

                if(leftIndex < size && arr[i] < arr[leftIndex]) {
                    swap(arr[i] , arr[leftIndex]);
                    i = leftIndex;
                }

                else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                    swap(arr[i] , arr[rightIndex]);
                    i = rightIndex;
                }

                else {
                    return;
                }
            }
        }

        void print() {
            for(int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {

    Heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap array is : " << endl;
    h.print();

    h.deletion();
    cout << "Heap array after deletion is : " << endl;
    h.print();

    h.deletion();
    cout << "Heap array after deletion is : " << endl;
    h.print();


 return 0;
}
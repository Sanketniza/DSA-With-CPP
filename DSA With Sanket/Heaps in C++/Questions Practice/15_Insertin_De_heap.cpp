#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class heap {
    public:
        int arr[10];
        int size;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int data) {

            size = size + 1;

            int index = size;
            arr[index] = data; // insert value at last index in array

            while(index > 1) {

                int parent = index / 2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent] , arr[index]);
                    index = parent;
                }

                else {
                    return;
                }
            }

        }

        void deletion() {

            if(size == 0) {
                cout << "No element to delete" << endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;

            while (i < size) {

                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;

                if(leftIndex < size && arr[i] < arr[leftIndex]) {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }

                else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }

                else {
                    return;
                }
            }

        }

        void print() {

            cout << "The array is: " << endl;

            for(int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl << endl;
        }

};

int main() {

    cout << "Insertion in heap" << endl;

    heap h;

    h.insert(4);
    h.insert(2);
    h.insert(34);
    h.insert(5);
    h.insert(6);
    h.insert(76);
    h.insert(18);
    h.insert(9);
    h.insert(10);

    h.print();

    cout << "Deletion in heap" << endl;

    h.deletion();
    h.print();


 return 0;
}
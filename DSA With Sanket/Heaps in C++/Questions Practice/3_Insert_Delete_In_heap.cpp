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

        void insertion(int val) {

            size = size + 1;
            int index = size;
            arr[index ] = val;

            while (index > 1) {

                int parent = index / 2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
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


            arr[1] = arr[size]; //-> put last element at first index
            size--;

            int i = 1;

            while (i < size) {

                int left = 2 * i; // left child
                int right = 2 * i + 1; // right child

                if(left < size && arr[i] < arr[left]) {
                    swap(arr[i], arr[left]);
                    i = left;
                }

                else if(right < size && arr[i] < arr[right]) {
                    swap(arr[i], arr[right]);
                    i = right;
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

    h.insertion(50);
    h.insertion(30);
    h.insertion(20);
    h.insertion(10);
    h.insertion(5);
    h.insertion(1);

    cout << "Heap after insertion: ";
    h.print();

    h.deletion();
    cout << "Heap after deletion: ";
    h.print();


 return 0;
}
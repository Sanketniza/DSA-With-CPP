
#include<iostream>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val) {

            size = size + 1;
            int index = size;
            arr[index] = val;

            while (index > 1) {

                int parent = index /2;

                if(arr[parent] < arr[index] ) {
                    swap(arr[parent] , arr[index]);
                    index = parent;
                }

                else {
                    return ;
                }
            }
        }

        void deletion() {

            if( size == 0) {
                cout << "nothing is here to delete" << endl;
                return;
            }

            // step 1: 
            arr[1] = arr[size];

            // step 2
            size--;

            // step 3
            int i = 1;

            while ( i < size) {

                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;
                
                   if(leftIndex < size && arr[i] < arr[leftIndex]) {
                //(leftIndex < size) --> if leftIndex is less than size , means left child is present
                //(arr[i] < arr[leftIndex]) --> if parent is less than left child , then swap

                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;  //-> update i to leftIndex
                }

                else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                //(rightIndex < size) --> if rightIndex is less than size , means right child is present
                //(arr[i] < arr[rightIndex]) --> if parent is less than right child , then swap

                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;  //-> update i to rightIndex
                }

                else {
                    return;  //-> if parent is greater than both children , then return
                }
            }


        }

        void print() {

            for (int i = 1 ; i <= size ; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;

        }


};

int main() {

    heap h;
    h.insert(23);
    h.insert(33);
    h.insert(4);
    h.insert(50);

    h.print();

    h.deletion();
    h.print();


 return 0;
}
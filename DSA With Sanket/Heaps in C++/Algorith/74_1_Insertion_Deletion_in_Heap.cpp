
#include<iostream>
using namespace std;

/* 

    *   TIME COMPLEXITY : O(logN)
    *   SPACE COMPLEXITY : O(1)

*/

    //? 1. Create a class Heap
    //? 2. Create an array of size 100
    //? 3. Create a variable size to keep track of number of elements in heap
    //? 4. Create a constructor to initialize size to 0 and arr[0] to -1 & initialize size to 0
    //? 5. Create a function insert to insert an element in heap
    //? 6. Create a function deletion to delete the root element from heap
    //? 7. Create a function print to print the heap
    //? 8. Create a main function to test the heap
    //? 9. In main function, create an object of Heap class and call insert and deletion functions
    //? 10. Print the heap after each operation

class  Heap {

    public:
        int arr[100];
        int size;

        Heap() {
            arr[0] = -1;
            size = 0; // -> initialize size to 0 means index 0 is not used
        }

        void insert(int val) {

            size = size + 1;  //-> put inserted value at last index of array / insert at last position
            int index = size;  //-> index of inserted value in array
            arr[index] = val;  //-> insert value at last index in array

            while(index > 1) {  //-> while inserted value is not at root position , means it is not at 1st position

                int parent = index/2;  //-> parent of inserted value

                if(arr[parent] < arr[index]) {  //-> if parent is less than inserted value , then swap
                    swap(arr[parent], arr[index]);
                    index = parent;  //-> update index to parent index
                }

                else {
                    return;  //-> if parent is greater than inserted value , then return
                } 
            }
        }

        void deletion() {

            if(size == 0) {  //-> if size is 0 , means no element in heap
                cout << "Nothing to delete" << endl;
                return;
            }

            //? step 1 : put last element into first index
            arr[1] = arr[size]; //  -> put last element at first index

            //? step 2 : remove last element
            size--; //-> decrease size by 1 , due to it last element is deleted automatically

            //? step 3 : take root node to its correct position
            int i = 1; //-> starting from root node

            while(i < size) {  //-> while i is less than size

                int leftIndex = 2*i;  //-> left child of i
                int rightIndex = 2*i + 1;  //-> right child of i, here i is parent

                if(leftIndex < size && arr[i] < arr[leftIndex]) {
                    // (leftIndex < size) --> if leftIndex is less than size , means left child is present
                    // (arr[i] < arr[leftIndex]) --> if parent is less than left child , then swap

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
            for(int i = 1; i <= size; i++) { // i = 1 because 0th index is -1
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
    // output : 55 54 53 50 52  , draw the tree for better understanding

    /* 

               55
              /  \
             54   53
            /  \
           50   52
    
     */

    cout << "Insertion done" << endl;
    h.print();

    h.deletion();
    // output : 54 52 53 50  , draw the tree for better understanding
    cout << "Deletion done" << endl;
    h.print();

    /* 

               54
              /  \
             52   53
            /
           50   
    
     */

    return 0;
}
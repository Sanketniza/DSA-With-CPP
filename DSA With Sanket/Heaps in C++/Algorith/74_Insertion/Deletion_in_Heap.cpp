
#include<iostream>
using namespace std;

class  Heap{
    public:
        int arr[100];
        int size;

        Heap() {
            arr[0] = -1;
            size = 0;
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

    h.print();
 return 0;
}
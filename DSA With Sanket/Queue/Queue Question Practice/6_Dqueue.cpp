#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int PR;
    int PF;
    int PPR;
    int PPF;
    int size;
    public:
    Queue(int size) {
        this -> size = size;
        cout << "size : " << size << endl;
        arr = new int[size];
        PF = -1;
        PR = size;

        PPF = 0;
        PPR = size - 1;
    }

    void pushFront(int x) {

        if(PR - PF > 1) {
            PF++;
            arr[PF] = x;
            cout << "Pushed element in front: " << arr[PF] << endl;
        }

        else if(PF == -1) {
            cout << "Queue is empty" << endl;
        }

        else {
            cout << "Queue is full" << endl;
        }
    }

    void pushRear(int x) {
        if(PR - PF > 1) {
            PR--;
            arr[PR] = x;
            cout << "Pushed element in rear: " << arr[PR] << endl;
        }

        else {
            cout << "Queue is full" << endl;
        }
    }

    void popFront() {
        if(PF == -1) {
            cout << "Queue is empty" << endl;
        }

        else if()

        else {
            cout << "Popped element in front: " << arr[PF] << endl;
            PF++;
        }
    }

    void print() {
        cout << "Queue elements: ";
        for(int i = PPF; i <= PPR; i++) {

            if(PF == -1) {
                cout << "Queue is empty" << endl;
                break;
            }

            else if(PF == -1 && PR != size ) {
                for(int j = PR; j <= PPR; j++) {
                    cout << arr[j] << " ";
                }
                // cout << arr[i] << " ";
            }
            
            else {
                cout << arr[i] << " ";
            }
          
        }
        cout << endl;
    }


};

int main() {

    Queue *q = new Queue(5);

    q -> print();

    cout << "------------" << endl;

    q -> pushRear(10);
    q -> pushRear(20);
    q -> print();

    cout << "------------" << endl;

    q -> pushFront(10);
    q -> pushFront(20);

    cout << "------------" << endl;

    q -> pushRear(30);
    q -> pushRear(40);

    cout << "------------" << endl;

    q -> pushFront(50);
    q -> print();
    // q -> pushFront(60);
    q -> pushRear(60);

    cout << "------------" << endl;



    


 return 0;
}

#include<iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5,6,9};
    int size = 7;

    int target = 33;

    for(int i = 0; i < size ; i++) {

        if(arr[i] == target) {
            cout << "target is found " << arr[i] << endl;
        }
        
        
    }
 return 0;
}

/* 
   ? Reverse the array after the kth position
   ? lecture 20
   ? Link: https://www.codingninjas.com/studio/problems/reverse-the-array_1262298?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_6&leftPanelTab=0
 */

#include<iostream>
using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4, 5 ,6 ,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "size: " << size << endl;
    int k = 3;

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    int s = k + 1;
    int e = size - 1;

    while (s < e) {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    

 return 0;
}
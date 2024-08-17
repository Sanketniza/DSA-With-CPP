// Reverse Array

#include<iostream>
#include<vector>
using namespace std;

vector<int> ReverseArray (vector<int> a) {

     int s = 0 ;
     int e = a.size() - 1;

     while (s <= e ) {

         swap(a[s] , a[e]);
         s++;
         e--;
     }

     return a;
}
 
 void PrintArray (vector<int> a) {
     
     for(int i = 0 ; i < a.size() ; i++) {

         cout << a[i] << " ";
     }

     cout << endl;
 }
int main() { 

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> ans = ReverseArray(v);

    cout << "Original Array : " << endl;
    PrintArray (v);

    cout << "Reversed Array : " << endl;
    PrintArray (ans);

    // for (int i = 0 ; i < ans.size() ; i++) {
    //     cout << ans[i] << " ";
    // }
    

    return 0;
}
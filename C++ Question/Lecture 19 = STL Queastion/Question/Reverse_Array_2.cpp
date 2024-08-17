

/*
^   Problem statement
^  Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.
^  
^  Example:
^  
^  We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0
^  based indexing so the subarray {5, 6} will be reversed and our
^  output array will be {1, 2, 3, 4, 6, 5}.
^  
^   */

#include <iostream>
#include <vector>
using namespace std;

vector<int> ReverseArray(vector<int> a, int m)
{

    int s = m + 1;
    int e = a.size() - 1;

    while (s <= e)
    {
        swap(a[s], a[e]);
        s++;
        e--;
    }
    
    for(int i = 0 ; i < a.size() ; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return a;
}

int main()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    int m = 3;

    vector<int> ans = ReverseArray(v, m);

    return 0;
}
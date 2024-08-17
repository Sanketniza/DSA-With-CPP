#include<iostream>
#include<vector>
using namespace std;
 
void reverse(vector<int> v , int k) {

    int s = k;
    int e = v.size() - 1;

    while (s <= e) {
        
        v[0] = v[s];
        s++;
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; 
    }
}

int main() { 

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "size of v = " << v.size() << endl;

    int k = 3;

    reverse(v , k);

    return 0;
}
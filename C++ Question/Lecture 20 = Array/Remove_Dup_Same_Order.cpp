
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


int main() {

    vector<int> arr = {1 ,2 ,2 ,8,4,5,6,5,4,1,2,5,3,1};
    
    vector<int> res;
    unordered_set<int> s;

    for(auto val : arr) {
        if(s.find(val) == s.end()){
            s.insert(val);
            res.push_back(val);
        }
    }

    for(auto val : res) {
        cout << val << " ";
    }

    cout << endl;

 return 0;
}
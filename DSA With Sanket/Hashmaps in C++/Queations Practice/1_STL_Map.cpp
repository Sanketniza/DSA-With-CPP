#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    map<int, string> m;
    
    //* insertion methond 1
    m[1] = "sanket";
    cout << m[1] << endl;

    m.insert({2 , "sanket2"});
    cout << m[2] << endl;

    //* printing all key-value pairs
    cout << "\nAll key-value pairs in the map:" << endl;
    for(auto pair : m) {
        cout << pair.first << " : " << pair.second << endl;
    }

    pair<int , string > p = make_pair(3, "sanket3");
    m.insert(p);

    pair<int , string > p1(4, "sanket4");
    m.insert(p1);

    cout  << endl;
    for(auto i : m) {
        cout << i.first << " : " << i.second << endl;
    }

    cout << endl;

    //* searching in map
    int key = 2;  // Changed from string to int since our map has int keys

    if(m.count(key)) {
        cout << "Key " << key << " is present" << endl;
        cout << "Value for key " << key << " is: " << m[key] << endl;
    }
    else {
        cout << "Key " << key << " is not present" << endl;
    }

    return 0;
}
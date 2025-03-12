#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> petrol = {4 , 6 , 10 , 4};
    vector<int> distance = {6 , 7 , 3 , 5};

    int deficiency = 0;
    int balancePetrol = 0;
    int start = 0;

    for(int i = 0; i < petrol.size(); i++) {

        balancePetrol += petrol[i] - distance[i];

        if(balancePetrol < 0) {
            deficiency += balancePetrol;
            start = i + 1;
            balancePetrol = 0;
        }
    }

    if(deficiency + balancePetrol >= 0) {
        cout << "Truck can start from point :  " << start << endl;
    }

    else {
        cout << -1 << endl;
    }

 return 0;
}
#include<iostream>
#include<queue>
using namespace std;


int main() {


    // -------------------- Max Heap --------------------

    priority_queue<int> maxi;
    // syntax for max heap

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    cout << "Size of maxi: " << maxi.size() << endl;
    cout << "Top element of maxi: " << maxi.top() << endl;
    maxi.pop();
    cout << "Top element of maxi after pop: " << maxi.top() << endl;
    cout << "Size of maxi after pop: " << maxi.size() << endl;

    if(maxi.empty()) {
        cout << "Maxi is empty" << endl;
    }
    else {
        cout << "Maxi is not empty" << endl;
    }

    cout << "Elements of maxi: ";

    int n = maxi.size();

    for(int i = 0; i < n; i++) {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    // -------------------- Min Heap --------------------

    priority_queue<int, vector<int>, greater<int>> mini;
    // syntax for min heap

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    cout << "Size of mini: " << mini.size() << endl;
    cout << "Top element of mini: " << mini.top() << endl;

    mini.pop();

    cout << "Top element of mini after pop: " << mini.top() << endl;
    cout << "Size of mini after pop: " << mini.size() << endl;

    if(mini.empty()) {

        cout << "Mini is empty" << endl;
    }


    else {
        c
        out << "Mini is not empty" << endl;
    }

    cout << "Elements of mini: ";

    int m = mini.size();

    for(int i = 0; i < m; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }

    cout << endl;

 return 0;
 
}
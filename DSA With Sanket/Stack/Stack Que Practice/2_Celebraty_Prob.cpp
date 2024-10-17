#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool know(vector<vector<int>>& mat, int a, int b) {

    if(mat[a][b] == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = mat.size(); 

    stack<int> st;

    for(int i = 0; i < n; i++) {
        st.push(i);
    }

    // cout << st.size() << endl;

    // while(!st.empty()) {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    while (st.size() > 1) {

        cout << "st.size() : " << st.size() << endl;

        int a = st.top();
        cout << "a : " << a << endl;
        st.pop();

        int b = st.top();
        cout << "b : " << b << endl;
        st.pop();


        if(know(mat, a , b) ) {
            st.push(b);
            cout << "b is pushed: " << b << endl;
            cout << "st.size() : " << st.size() << endl;
            cout << "st.top() : " << st.top() << endl;
        }

        else {
            st.push(a);
            cout << "a is pushed: " << a << endl;
            cout << "st.size() : " << st.size() << endl;
            cout << "st.top() : " << st.top() << endl;
        }

    }
  
    int ans = st.top();
    cout << "ans : " << ans << endl;

    int rowCheck = 0;
    for(int i = 0; i < n; i++) {
        if(mat[ans][i] == 1) {
            rowCheck++;
        }
        cout << "rowCheck : " << rowCheck << endl;
    }

    if(rowCheck != n) {
        cout << "Row check is false" << endl;
    }

    int colCheck = 0;
    for(int i = 0; i < n; i++) {
        if(mat[i][ans] == 0) {
            colCheck++;
        }
        cout << "colCheck : " << colCheck << endl;
    }

    if(colCheck != n -1) {
        cout << "Col check is false" << endl;
    }

    cout << "rowCheck : " << rowCheck << endl;
    cout << "colCheck : " << colCheck << endl << endl;

    
   cout << "Celebrity is : " << ans << endl;

 return 0;
}
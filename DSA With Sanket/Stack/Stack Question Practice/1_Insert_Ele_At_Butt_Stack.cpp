#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int x) {

    // base case

    if(st.empty()) {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    solve(st, x);

    st.push(num);
}

int main() {

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"Stack before insertion: "<<endl;
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;
    cout << "top element: " << st.top() << endl;

    int x = 34;

    solve (st, x);

    cout<<"Stack after insertion: "<<endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

 return 0;
}
/* 
? Clone stack without using extra space
? https://www.geeksforgeeks.org/problems/clone-a-stack-without-usinig-extra-space/1
 */

#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int> &st, stack<int> &clonedStack) {

    // base case;

    if(st.empty()) {
        return;
    }

    int topEle = st.top();
    st.pop();

    // recursive call

    solve(st, clonedStack);

    // add top element in cloned stack

    clonedStack.push(topEle);

    // backtracking

    st.push(topEle);
}

int main() {

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    stack<int> clonedStack = st;

    solve(st, clonedStack);

 return 0;

}
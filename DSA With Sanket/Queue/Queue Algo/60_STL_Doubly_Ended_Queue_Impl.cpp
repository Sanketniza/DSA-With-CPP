
#include<iostream>
#include<queue>
using namespace std;

//TODO: Implement the following operations of a queue using C++ STL

int main() {

   deque<int> q;

   q.push_back(1);
   q.push_back(2);
   q.push_front(3);
   q.push_front(4);

   cout << "The front element is : " << q.front() << endl;
   cout << "The back element is : " << q.back() << endl;
   cout << q.size() << endl;

   q.pop_front();
   q.pop_back();

   cout << "The front element is : " << q.front() << endl;
   cout << "The back element is : " << q.back() << endl;

 return 0;
}
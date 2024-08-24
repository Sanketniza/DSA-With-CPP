
#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    cout << "Address of a is : " << &a << endl;
    cout << "Value of a is : " << a << endl;
    cout << endl;

    int *ptr = &a;
    cout << "Address of a is : " << ptr << endl;
    cout << "Value of a is : " << *ptr << endl;
    cout << "Address of a is : " << &ptr << endl;
    cout << endl;

    (*ptr)++;
    cout << "Value of a is : " << a << endl;
    cout << endl;

    cout << "Size of a is : " << sizeof(a) << endl;
    cout << "Size of ptr is : " << sizeof(*ptr) << endl;
    cout << "Size of ptr is : " << sizeof(ptr) << endl;
    cout << endl;

    int *ptr2 = &a;
    cout << "Value of ptr2 is : " << *ptr2 << endl;

// coping a pointer
    int *p = ptr;
    cout << "Value of ptr is : " << *ptr << endl;
    cout << "Value of ptr2 is : " << *p << endl;
    cout << endl;

// important concept
  int s = 24;
  int *k = &s;
  cout << "value of k is : " << *k << endl;
  *k +=1;
  cout << "value of k is : " << *k << endl;

  cout << "before only k value is : : "<< k << endl;
  k = k + 1;
  cout << "after only k value is : : "<< k << endl;
  cout << endl;

    return 0;
}
#include<iostream>
using namespace std;
 
int main() { 

/* 
    int first = 10;
    int second = 12;
    int *p = &second;

    *p = 23;
    cout << first << " " << second << endl;
 */

  /* 
   int first = 10;
   int *p = &first;
   int *q = p;
   (*q)++;
   cout << first << endl;
 */

/* 
   int first = 10;
   int *p = &first;
   cout << (*p)++ << endl;
   cout << first << endl;
 */

/* 
  int first = 10;
  int second = 12;
  int *third = &second;

  first = second;
  *third = *third + 1;
  cout << first << " " << second << endl;
 */

/* 
    float p = 4.3;
    float q = 5.6;
    float *c = &p;

    (*c)++;
    *c = q;
    cout << *c << " " << q << " " << p << endl;
 */
/* 
    int arr[5];
    int *ptr;

    cout << sizeof(arr) << " " << sizeof(ptr) << endl;
 */

/* 
  int arr[] = {1, 12, 3, 4, 5};
  cout << *(arr) << " " << *(arr + 1) << endl;
  cout << arr << " " << &arr << endl;
  cout << (arr + 1) << endl;
 */


 


    return 0;
}
#include<iostream>
using namespace std;
 
int main() { 

    //^ technical use of pointe

/*   float f = 10.5;
  float l = 2.5;
  float *m = &f;
  cout << "value of m is " << *m << endl;
  
  (*m)++;
  cout << "value of m is " << *m << endl;

  *m = l;
  cout << "value of m is " << *m << endl;
  cout << "value of f is " << f << endl;
  cout << "value of l is " << l << endl;
 */
//&   -----------------------------------------------

/*   int a = 7;
  int b = 17;
  int *c = &b;
  *c = 7;

  cout << "value of a is " << a << endl;
  cout << "value of b is " << b << endl;
  cout << "value of c is " << *c << endl; */

//&   -----------------------------------------------

/* int *ptr = 0;
int a = 10;
*ptr = a;
cout << *ptr << endl;
 cout << "value of a is " << a << endl; */

//&   -----------------------------------------------

/*  char ch = 'a';
 char *ptr = &ch;
 ch++;
 cout << *ptr << endl; */

//&   -----------------------------------------------

/*  int a = 7;
 int *c = &a;
 c = c + 1;  // ^Next, it adds 1 to the pointer c, which moves the pointer to the next memory location after a.
//   *c += 1;

 cout << "value of a is " << a << endl;
 cout << "value of c is " << *c << endl; */

//&   -----------------------------------------------

/* int a = 7;
cout << "memory of a is " << &a << endl;
int *c = &a;
c = c + 3;
cout<< c << endl; */

//&   -----------------------------------------------

/* int a[5];
int *c;
cout << sizeof(a) <<" " << sizeof(c) << endl; */

//&   -----------------------------------------------
/* 
int a[] = {1, 2, 3, 4};
cout << *(a) << " " << *(a+1) << " " << *(a+2) << " " << *(a+3) << endl;
 */
//&   -----------------------------------------------
/* 
int a[] = {1, 2, 3, 4};
int *p = a++;
cout << *p << endl; */

//&   -----------------------------------------------

  /* int arr[] = {4, 5, 6, 7};
  int *p = (arr + 1);
  cout << *p << endl;
  cout << *arr + 9; */

//&   -----------------------------------------------

/* char b[] = "xyz";
char *c = &b[0];
cout << c << endl; */

//&   -----------------------------------------------

/* char s[]= "hello";
char *p = s;
cout << s[0] << " " << p[0]; */

//&   -----------------------------------------------
//&   -----------------------------------------------

    return 0;
}

#include <iostream>
using namespace std;
//* --> minimap

void print(int *a)
{
    cout << "1 inside the function " << a << endl;  // address of int a = 10 
    cout << "2 inside the function " << *a << endl; // print value of int a = 10
    cout << "3 inside the function " << &a << endl << endl; // print address of *p = *a
}

void update(int *a)
{
    a = a + 1;
    cout << "5 inside the function of update " << a << endl;
    cout << "6 inside the function of update " << &a << endl;

    *a = *a + 1;
    cout << "7 inside the function of update " << a << endl;
    cout << "8 inside the function of update " << &*a << endl;
    cout << "9 inside the function of update " << *a << endl << endl;

}

int sum(int *arr , int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    /* 
        int arr[]= {8,2,3,4,5};

        cout<<arr<<endl;
        cout << "The address is first index is : " << arr << endl;
        cout << "The address is first index (8) is : " << &arr[0] << endl;

    // *(arr) --> value at zero th location.
        cout << "value of first element " << *arr << endl;
        cout << "value of first element " << *arr + 1 << endl;
        cout << "value of first element " << *(arr + 1) << endl;
        cout << "value of first element " << *(arr) + 1 << endl;

        cout << "1th " << arr[2] << endl;
        cout << "2th " << *(arr+2) << endl;

        int i = 3;
         cout << "3th " << i[arr] << endl;
    */


    /* 
       int temp[10] = {45,1,2,5,4};
       cout << "size of temp is : " << sizeof(temp) << endl;
       cout << "address of zero index in temp is : " << &temp << endl;
       cout << "address of zero index in temp is : " << temp << endl;
       cout <<"size of first index element is " << sizeof(temp[0]) << endl;
       cout <<"size of first index element is " << sizeof(*(temp)) << endl;

       int *p = &temp[0];
       cout << "size of *p is : " << sizeof(p) << endl;
       cout << "size of *p is : " << sizeof(*p) << endl;
       cout << "address of *p is (address of zeroth index): " << (&p) << endl;
       cout << "address of *p is (address of first index): " << (&p +1) << endl;
     */

/* 
       int a[12] = {1, 2, 0, 21, 26, 27, 30, 31, 32};
       int *b = &a[0];

       cout << "1th " << &a[0] << endl;
       cout << "2nd " << &a << endl;
       cout << "3nd --> " << a << endl;

       cout << "printing 1st --> " << *b << endl;
       cout << "address of 1st pointer --> " << &b << endl;
       cout << "3rd --> " << &*b << endl;
       cout << "3rd " << b << endl; 
 */

    /* 
        int a[10];

        // a  = a + 1;  //* give error
        // cout << a << endl;

    //* not gives error
        int *p = &a[10];
        cout << p << endl;
        p = p + 1;
        cout << p << endl;
     */ 

    
    //& character array ..
/* 
        int arr[5] = {1, 2, 3, 4, 5};
        cout << arr << endl; // printing address of zeroth index which is 1

        char ar[] = "abcasdf";
        cout << ar << endl; // printing the all string which is abcd

        char *p = &ar[0];
        cout << p << endl; // Printing entire string .

        char temp = 'e';
        cout << temp << endl;
        char *p1 = &temp;
        cout << p1 << endl; // check this very interesting thing
 */
     

    
    //* pointer and function */

    int a = 10;
    int *p = &a;
    cout << "outside the function " << p << endl;
    cout << "outside the function " << *p << endl << endl;
    print(p);

    cout << endl;

    update(p);
    cout << "outside the function " << p << endl;
    cout << "outside the function " << *p << endl;

    int arr [5] = {1, 2, 3, 4, 5};
    // cout << "addition of array is " << sum(arr , 5) << endl;
    cout << "addition of array is " << sum( arr + 2 , 3) << endl;



 for(int i = 0 ; i < 5 ; i++) {  
     cout << arr[i] << endl;
 }

   return 0;
}
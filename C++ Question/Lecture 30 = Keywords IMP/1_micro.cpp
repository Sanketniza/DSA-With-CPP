#include <iostream>
using namespace std;

// define the micro variable
//^ what is micro:-
//? --> micro is a piece of code in a program that is replaced by a value of micro
//^ in micro we have to define the variable in the same block
//  ^ in micro we can't define the variable in the different block

#define PI 3.14

#define LIMIT 5

#define AREA(l, b) (l * b)
//          (a , b ) (a * b)
//          (passing the argument) (what should we have to do here)

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main()
{

    int r = 3;

    int area = PI * r * r;
    cout << "Area of circle: " << area << endl;

    //&----------------------------------------------------------------------

    cout << "The value of LIMIT is : " << LIMIT << endl;

    //&----------------------------------------------------------------------

    int a = 10, b = 5, area1;

    // Find the area using macros
    area1 = AREA(a, b);
    cout << "The area is : " << area1 << endl;

    //&----------------------------------------------------------------------

    int a1 = 18;
    int b1 = 76;

    cout << "Minimum of " << a1 << " and " << b1 << " is " << min(a, b);
    return 0;
}

/* 
 */
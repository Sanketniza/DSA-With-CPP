#include<iostream>
using namespace std;

long long int binary(int n) {

    int start = 0;
    int end = n;
    long long int mid = start + (end - start) / 2;
    long long int ans = -1;

    while (start <= end) {  // while (start < end) --> run time error

        long long int square = mid * mid;

        if(square == n) {
            return mid;
        }

        if(square < n) {
            ans = mid;
            end = mid + 1;
        }

        else {
            start = mid - 1;
        }
        
        mid = start + (end - start) / 2;
    }

    return ans;
}


 
int main() { 

    int n;
    cout << "Enter the value of n : " ;
    cin >> n;

    int result = binary(n);

    cout << "Answer is " << result << endl;

    return 0;
}
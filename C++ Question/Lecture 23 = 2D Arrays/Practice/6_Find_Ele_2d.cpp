#include <iostream>
using namespace std;

void sumOfSubset(int arr[3][4]) {
    
    int sum = 0;
    int max = 0;
    int index = -1;

    for(int i = 0; i < 3; i++)  {
        for (int j = 0 ; j < 4; j++) {
            sum += arr[i][j];
        }

        cout << sum << " ";

        if(sum > max) {
            max = sum;
            index = i;
        }
    }
    cout << "max sum is = " << max << " and is = " << index << endl;
    
}

bool isPresent(int arr[3][4], int target)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (arr[j] == arr[j])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 1, 9, 11, 1, 1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int target = 453;

    if (isPresent(arr, target))
    {
        cout << "the element is present in array ";
    }

    else
    {
        cout << "THe element is not present in array ";
    }

    sumOfSubset(arr);

    return 0;
}
/* 

    ? Circular Tour
    ? https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

    Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
Your Task:
Your task is to complete the function tour() which takes the required data as inputs and returns an integer denoting a point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). If there exists multiple such starting points, then the function must return the first one out of those. (return -1 otherwise)
 */


#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> petrol = {4, 4, 7, 4};
    vector<int> distance = {6, 5, 3, 5};

    int deficiency = 0;
    int balancePetrol = 0;
    int start = 0;

    for(int i = 0; i < petrol.size(); i++) {

        balancePetrol += petrol[i] - distance[i];

        if(balancePetrol < 0) {

            deficiency += balancePetrol;
            start = i + 1;
            balancePetrol = 0;
        }
    }

    if(deficiency + balancePetrol >= 0) {
        cout << start << endl;
    }

    else {
        cout << -1 << endl;
    }    

 return 0;
}
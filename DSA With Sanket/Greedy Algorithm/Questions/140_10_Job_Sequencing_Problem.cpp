/*  
    ? Job Sequencing Problem
    ? You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

    Your task is to find:

    The maximum number of jobs that can be completed within their deadlines.
    The total maximum profit earned by completing those jobs.
    Examples :

    Input: 
        id = [1, 2, 3, 4], 
        deadline = [4, 1, 1, 1], 
        profit = [20, 1, 40, 30]
    Output: [2, 60]
    Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

    Input: 
        id = [1, 2, 3, 4, 5], 
        deadline = [2, 1, 2, 1, 1], 
        profit = [100, 19, 27, 25, 15]
    Output: [2, 127]
    Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

    Input: 
        id = [1, 2, 3, 4], 
        deadline = [3, 1, 2, 2], 
        profit = [50, 10, 20, 30]
    Output: [3, 100]
    Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Comparator function to sort jobs by profit in descending order
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<2>(a) > get<2>(b);
}

int main() {
    vector<int> id = {1, 2, 3, 4};
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 1, 40, 30};

    // Store jobs as tuples of (id, deadline, profit)
    vector<tuple<int, int, int>> jobs;
    for(int i = 0; i < id.size(); i++) {
        jobs.push_back(make_tuple(id[i], deadline[i], profit[i]));
    }

    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), cmp);

    // Print the sorted jobs for debugging
    cout << "Sorted jobs by profit:" << endl;
    for(const auto& job : jobs) {
        cout << "ID: " << get<0>(job) << ", Deadline: " << get<1>(job) << ", Profit: " << get<2>(job) << endl;
    }

    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, get<1>(job));
    }

    // Create a slot array to keep track of free time slots
    vector<int> slot(maxDeadline + 1, -1);

    int countJobs = 0;
    int totalProfit = 0;

    // Iterate through all jobs
    for (const auto& job : jobs) {
        int id = get<0>(job); // or job[0] or v[i][0] or v[i].profit
        int dl = get<1>(job); // or job[1] or v[i][1]
        int pr = get<2>(job); // or job[2] or v[i][2]

        // Find a free slot for this job (starting from its deadline)
        for (int j = dl; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = id;
                countJobs++;
                totalProfit += pr;
                break;
            }
        }
    }

    //stored into vector
    vector<int> ans;
    ans.push_back(countJobs);
    ans.push_back(totalProfit);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    // Print the result
    cout << "Maximum number of jobs: " << countJobs << endl;
    cout << "Total maximum profit: " << totalProfit << endl;

    return 0;
}
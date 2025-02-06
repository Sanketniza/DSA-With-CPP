/* 

 */

 #include<iostream>
 #include<vector>
 using namespace std;

/* 
    * Dynamic Programming:
    * 1. Overlapping Subproblems
    * 2. Optimal Substructure
    * 3. Optimal Solution
    * 4. Recursion + Memoization
    * 5. Tabulation
    * 6. Space Optimization
   
    Approach one : - Top - Down [Recursive + Memoization]
    Approach two : - Bottom - UP [ Tabulation  ]
    Approach three : - Space Optimization

 */

 int solve (vector<int> &cost , int n) {

    // base case
    if(n == 0) {
        return cost[0];
    }

    if(n == 1) {
        return cost[1];
    }

    int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
    return ans;
 }

 int solve1(vector<int> &cost , int n , vector<int> &dp ) {

    // base case
    if(n == 0) {
        return cost[0];
    }

    if(n == 1) {
        return cost[1];
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = cost[n] + min(solve1(cost, n - 1, dp), solve1(cost, n - 2, dp));
    return dp[n] = ans;
 }

 int solve2(vector<int>&cost , int n) {

    vector<int> dp(n + 1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
 }

 int solve3(vector<int> &cost , int n) {

    int first = cost[0];
    int second = cost[1];

    for(int i = 2; i < n; i++) {
        int curr = cost[i] + min(first, second);
        first = second;
        second = curr;
    }

    return min(first, second);
 }
 
 int main() {
 
    int m;
    cin >> m;

    vector<int> cost(m);
    for(int i = 0; i < m; i++) {
        cin >> cost[i];
    }

    int n = cost.size();

    // todo: Approach one : - Recursive only
    // Recursion way = 1
        /*  
            Time Complexity : O(2^n);
            Space Complexity : O(1);
        
         */

        //  int n = cost.size();
         int ans = min(solve(cost , n - 1 ) , solve(cost , n - 2) );
         cout << "ans is : " << ans << endl;


    // todo: Approach two : - Recursive + Memoization
    // Recursion + Memoization = 2
        /*  
            Time Complexity : O(n);
            Space Complexity : O(n);
        */

        vector<int> dp(m + 1);
        for(int i = 0; i <= m; i++) {
            dp[i] = -1;
        }

        // int n = cost.size();
        int ans1 = min(solve1(cost , n - 1 , dp) , solve1(cost , n - 2 ,dp) );
        cout << "ans1 is : " << ans1 << endl;

    // todo: Approach three : - Bottom - UP [ Tabulation  ]
      // Tabulation = 3
        /* 
            Time Complexity : O(n);
            Space Complexity : O(n);
        */

        // int n = cost.size();
        int ans2 = solve2(cost , n);
        cout << "ans2 is : " << ans2 << endl;

    // todo: Approach four : - Space Optimization
      // Space Optimization = 4
        /* 
            Time Complexity : O(n);
            Space Complexity : O(1);
        */

        // int n = cost.size();
        int ans3 = solve3(cost , n);

        cout << "ans3 is : " << ans3 << endl;   

  return 0;
}
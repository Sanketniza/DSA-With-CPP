#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row , int col , vector<vector<int> > &arr,int size , vector<vector<bool> > &vis) {

    if( (row >= 0 && row < size) && (col >= 0 && col < size) &&  (vis[row][col] == false) && (arr[row][col] != 0)) {
        return true;
    }    

    else {
        return false;
    }
}

void done(int row , int col , vector<vector<int> > &arr , int size , vector<string> &ans, vector<vector<bool> > &visited, string path) {

    if(row == size - 1 && col == size - 1) {
        ans.push_back(path);
        return;
    }

    // 4 movement D L R U
    int rowChange[] = {1, 0, 0, -1};
    int colChange[] = {0, -1, 1, 0};
    char direction[] = {'D', 'L', 'R', 'U'};

    visited[row][col] = true;

    for(int i = 0; i < 4; i++) {
        int newRow = row + rowChange[i];
        int newCol = col + colChange[i];
        if(isSafe(newRow, newCol , arr , size , visited)) {
            done(newRow, newCol, arr, size, ans, visited, path + direction[i]);
        }
    }

    visited[row][col] = false;
}

vector<string> solve(vector<vector<int> > &arr, int size) {
    
    vector<string> ans;
    vector<vector<bool> > visited(size, vector<bool>(size, false));
    string path = "";

    if(arr[0][0] == 0) {
        return ans;
    }

    done(0,0,arr,size,ans,visited,path);

    return ans;
}
 
int main() { 

    vector<vector<int> > arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    
    int size = arr.size();

   vector<string> result = solve(arr,size);

   for(int i = 0; i < result.size(); i++) {
       cout << result[i] << endl;
   }
  

    return 0;
}
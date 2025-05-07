#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void dfs(int node , unordered_map<int , bool> &visited , unordered_map<int , list<int>> &adj , vector<int> &temp) {

    temp.push_back(node);
    visited[node] = true;

    for(auto i : adj[node]) {
        if(!visited[i]) {
            dfs(i , visited , adj , temp);
        }
    }
}


vector<vector<int>> PrintBFS(int node , int edge , vector<vector<int>> ed) {

    unordered_map<int , list<int>> adj;
    for(int i = 0; i < ed.size(); i++) {
        int u = ed[i][0];
        int v = ed[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int , bool > visited;
    vector<vector<int>>ans;

    for(int i = 1; i <= node; i++) {
        if(!visited[i]) {
            vector<int> temp;
            dfs(i , visited , adj , temp);
            ans.push_back(temp);
        }
    }

    return ans;
}

int main() {

    int v = 5;
    int e = 4;

    vector<vector<int>> edge = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    vector<vector<int>> ans = PrintBFS(v, e, edge);

    cout << "Elements in the graph are : " << endl;
    for(auto i : ans) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }


 return 0;
}
/* 

    ? Cycle Detection in Undirected Graphs using BFS
    ? https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

Example :

In the below graph, there exists a cycle between vertex 1, 2 and 3. 

Note:

1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :

Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= M <= min(5000, (N * (N - 1)) / 2)
1 <= edges[i][0] <= N 
1 <= edges[i][1] <= N 

Time Limit: 1 sec 
Sample Input 1:
1
3 2
1 2
2 3
Sample output 1:
No
Explanation of Sample output 1:
 The above graph can be represented as 

There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
Sample Input 2:
2
4 0 
4 3
1 4
4 3
3 1
Sample output 2:
No
Yes

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int node , unordered_map<int , bool> &visited , unordered_map<int, list<int> > &adj) {

    unordered_map<int , int > parent;
    visited[node] = true;
    parent[node] = -1;

    queue<int> q;
    q.push(node);

    while (!q.empty()) {

        int front = q.front();
        q.pop();

        for(auto i:adj[front]) {

            if(visited[i] == true && i != parent[front]) {
                return true;
            }

            else if(visited[i] == false) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    return false;
}

string solve(int node , int m , vector<vector<int>> &edge) {

    unordered_map<int, list<int> > adj;

    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 

    unordered_map<int , bool> visited;

    for(int i = 0; i < node; i++) {

        if(!visited[i]) {

            bool ans = bfs(i , visited , adj);

            if(ans) {
                return "Yes";
            }
        }
    }

    return "No";
}
 
int main() { 

    /* 
        1 - - - 2
          \    /
            3
     */

    int n = 3;
    int m = 3;

    vector<vector<int> > edge = {
        {1, 2},
        {2, 3},
        {1, 3}
    };

    string reu = solve(n, m, edge);
    cout << "Is there cycle in the graph : " << reu << endl;
    

    return 0;
}
/* 

    ? Cycle Detection in Undirected Graphs using DFS
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

bool isCycleDFS(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited) {

    // if the node is already visited, then return true
    visited[node] = 1;
    // check for all the neighbours of the node

    // if the neighbour is not visited, then do a DFS on it
    for (auto neighbor : adj[node]) {

        if (!visited[neighbor]) {
            // if the neighbor is not visited, then do a DFS on it
            bool cycleDetected = isCycleDFS(neighbor, node, adj, visited);
            // if cycle is detected in the DFS, then return true
            if (cycleDetected) {
                return true;
            }
        } 

        // if the neighbour is visited and it is not the parent of the current node, then cycle is detected
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}


string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    // prepare adj list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int node = 0; node < n; node++) {
        if (!visited[node]) {
            // bool ans = isCycleBFS(node, adj, visited);
            bool ans = isCycleDFS(node, -1,adj , visited);
            if (ans) {
                return "Yes";
            }
        }
    }

    return "No";
}
 
int main() { 

    int v = 3;
    int e = 3;

    vector<vector<int> > edges = {
        {1, 2},
        {1, 3},
        {2, 3}
    };


  cycleDetection( edges , v , e);

    return 0;
}

/*
   ?  Lecture 100: Kosaraju's Algorithm for Strongly Connected Components |
?
   ?  https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0

     Count Strongly Connected Components (Kosaraju’s Algorithm)
Hard
0/120
Average time to solve is 40m
Contributed by
75 upvotes
Asked in companies
Problem statement
You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the number of strongly connected components (SCCs) present in the graph.

A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected components of a graph are the subgraphs which are themselves strongly connected.

Note :
Use zero-based indexing for the vertices.

The given graph doesn’t contain any self-loops.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= V <= 10^4
0 <= E <= 10^4
0 <= a, b < V

Time Limit: 1 sec
Sample Input 1 :
1
5 6
0 1
1 2
1 4
2 3
3 2
4 0
Sample Output 1 :
2
Explanation of sample input 1 :
For the first test case, the graph is shown below. There are two SCCs in the graph, which are enclosed in the boxes as shown in the image below.

Sample Input 2 :
2
1 0
4 4
0 1
1 2
2 3
3 1
Sample Output 2 :
1
2

 */

#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &st)
{
   vis[node] = true;

   for (auto nbr : adj[node])
   {
      if (!vis[nbr])
      {
         dfs(nbr, adj, vis, st);
      }
   }

   st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
   vis[node] = true;

   for (auto nbr : adj[node])
   {
      if (!vis[nbr])
      {
         revDfs(nbr, vis, adj);
      }
   }
}

int stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
   // Adj list
   unordered_map<int, list<int>> adj;

   for (int i = 0; i < edges.size(); i++)
   {
      int u = edges[i][0];
      int v = edges[i][1];

      adj[u].push_back(v);
   }

   unordered_map<int, bool> vis;
   stack<int> st;

   for (int i = 0; i < V; i++)
   {
      if (!vis[i])
      {
         dfs(i, adj, vis, st);
      }
   }

   // Create transpose graph
   unordered_map<int, list<int>> transpose;
   for (int i = 0; i < V; i++)
   {
      for (auto nbr : adj[i])
      {
         transpose[nbr].push_back(i);
      }
   }

   // Reset visited map
   for (int i = 0; i < V; i++)
   {
      vis[i] = false;
   }

   int count = 0;

   while (!st.empty())
   {
      int top = st.top();
      st.pop();

      if (!vis[top])
      {
         count++;
         revDfs(top, vis, transpose);
      }
   }

   return count;
}

int main()
{
   vector<vector<int>> edges1 = {
      {0, 1},
      {1, 2},
      {1, 4},
      {2, 3},
      {3, 2},
      {4, 0}
   };

   int V1 = 5;
   cout << "Strongly Connected Components: " << stronglyConnectedComponents(V1, edges1) << endl; // Expected output: 2

   vector<vector<int>> edges2 = {
      {0, 1},
      {1, 2},
      {2, 3},
      {3, 1}
   };
   int V2 = 4;
   cout << "Strongly Connected Components: " << stronglyConnectedComponents(V2, edges2) << endl; // Expected output: 1

   return 0;
}

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
/* 
   ? Lecture 99: Articulation Points in Graphs
   ? Link: https://www.youtube.com/watch?v=aZXi1unBdJA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=99

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, int &timer, vector<int> &dis, vector<int> &low, vector<bool> &visited, unordered_map<int, list<int> > &adj, vector<int> &ap) {

    visited[node] = true;
    dis[node] = low[node] = timer++;

    int child = 0;

    for(auto nbr:adj[node]) {

        if(nbr == parent) {
            continue;
        }

        if(!visited[nbr]) {

            dfs(nbr, node, timer, dis, low, visited, adj, ap);
            low[node] = min(low[node], low[nbr]);

            // check for articulation point

            if(low[nbr] >= dis[node] && parent != -1) {
                ap[node] = 1;
            }
            child++;
        }

        else {
            low[node] = min(low[node], dis[nbr]);
        }
    } 

    if(parent == -1 && child > 1) {
        ap[node] = 1;
    }
}
 
int main() { 

    int n = 5;
    int e = 5;

    vector<pair<int,int> > edge;

    edge.push_back({0 ,3});
    // edge.push_back(make_pair(0 ,3));
    edge.push_back(make_pair(3 ,4));
    edge.push_back(make_pair(3 ,4));
    edge.push_back(make_pair(0 ,4));
    edge.push_back(make_pair(0, 1));
    edge.push_back(make_pair(1 ,2));


    unordered_map<int , list<int> > adj;

    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i].first;
        int v = edge[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> low(n, -1);
    vector<int> dis(n, -1);
    int parent = -1;
    vector<bool> visited(n, false);
    vector<int> ap(n, 0);
    int timer = 0;

    // for(int i = 0; i < n; i++) {  // no need due to  low(n, -1) , dis(n, -1)
    //     low[i] = -1;
    //     dis[i] = -1;
    // }

    for(int i = 0; i < n; i++) {

        if(!visited[i]) {
            dfs(i,parent, timer, dis, low , visited, adj, ap);
        }
    }

    cout << "Articulation points in graph : " << endl;
    for(int i = 0; i < n; i++) {
        if(ap[i] == 1) {
            cout << i << " ";
        }
    }
     
    cout << endl; 
    

    return 0;
}

// ? Time Complexity: O(V + E)
// ? Space Complexity: O(V)


// ? Video Link: https://www.youtube.com/watch?v=aZXi1unBdJA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=99

// ? GFG Link: https://practice.geeksforgeeks.org/problems/articulation-point-1/1

// ? LeetCode Link: https://leetcode.com/problems/critical-connections-in-a-network/

// ? Code Studio Link: https://www.codingninjas.com/codestudio/problems/critical-connections-in-a-graph_1171173

// ? Code Studio Link: https://www.codingninjas.com/codestudio/problems/articulation-point_1171174

//! simple solution:

// C++ program to find articulation points using a naive DFS approach

/*
 #include <bits/stdc++.h>
using namespace std;

// Standard DFS to mark all reachable nodes
void dfs(int node, unordered_map<int , list<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}


// Finds articulation points using naive DFS approach
vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
    
    unordered_map<int , list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res;

    // Try removing each node one by one
    for (int i = 0; i < V; ++i) {
        vector<bool> visited(V, false);
        visited[i] = true;
        
        // count DFS calls from i's neighbors
        int comp = 0; 
        for (auto it : adj[i]) {
            
            // early stop if already more than 1 component
            if (comp > 1) break; 

            if (!visited[it]) {
                
                // explore connected part
                dfs(it, adj, visited); 
                comp++;
            }
        }

        // if more than one component forms, it's an articulation point
        if (comp > 1)
            res.push_back(i);
    }

    if (res.empty())
        return {-1};

    return res;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

    vector<int> ans = articulationPoints(V, edges);

    cout << "Articulation Points are: ";
    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
} */

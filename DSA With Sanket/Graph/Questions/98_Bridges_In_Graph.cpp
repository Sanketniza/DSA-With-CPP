
/* 
    98: Bridges in a Graph
    https://www.youtube.com/watch?v=CiDPT1xMKI0&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=107

    Problem statement
Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).

For Example :

If the given graph is :

Then the edge between 0 and 4 is the bridge because if the edge between 0 and 4 is removed, then there will be no path left to reach from 0 to 4.and makes the graph disconnected, and increases the number of connected components.
Note :

There are no self-loops(an edge connecting the vertex to itself) in the given graph.

There are no parallel edges i.e no two vertices are directly connected by more than 1 edge.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 50
1 <= V <= 10 ^ 3
V-1 <= E <= 3 * 10^3
0 <= a, b < V

Time Limit: 1 sec
Sample Input 1 :
2
5 4
0 1
3 1
1 2
3 4
3 3
0 1
1 2
2 0
Sample Output 1 :
4
0 1
1 2    
1 3
3 4
0
Explanation for Sample Input 1 :
For the first test case, the graph will be represented as 

There are four bridges((0-1),(1-2),(1-3),(3-4)) in the above-given graph denoted by red lines.
For the second test case, there is no bridge present in the given graph.
Sample Input 2 :
1
6 7
1 2
1 0
0 2
0 4
5 4
5 3
3 4
Sample Output 2 :
1
0 4
Explanation for Sample Input 2 :
For the first test case, the graph will be represented as 

There is only one bridge((0-4)) in the above-given graph denoted by red lines.

 */

    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;

void dfs(int node, int timer, vector<int>& low, vector<int>& dist, int parent, unordered_map<int, bool>& vis, vector<vector<int>>& result, unordered_map<int, list<int>>& adj) {
    
    vis[node] = true;

    dist[node] = low[node] = timer++;
    // dist[node] = timer;
    // low[node] = timer;
    // timer++; 

    for(auto nbr : adj[node]) {
        if(nbr == parent) {
            continue;
        }

        else if(!vis[nbr]) {
            
            dfs(nbr, timer, low, dist, node, vis, result, adj);

            low[node] = min(low[node], low[nbr]);

            // check edge is bridge  
            if(low[nbr] > dist[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }

        else {
            // back edge
            low[node] = min(low[node], dist[nbr]);
        }
    }    
}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {
    // prepare adj list

    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 

    int timer = 0;
    vector<int> low(v);
    vector<int> dist(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for(int i = 0; i < v; i++) {
        low[i] = -1;
        dist[i] = -1;
    }

    vector<vector<int>> result;

    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            dfs(i, timer, low, dist, parent, vis, result, adj);
        }
    }

    return result;
}
 
    int main() { 

         int v, e;
        cin >> v >> e;

        vector<vector<int>> edges(e, vector<int>(2));
        for (int i = 0; i < e; ++i) {
            cin >> edges[i][0] >> edges[i][1];
        }

        vector<vector<int>> bridges = findBridges(edges, v, e);

        cout << "Bridges:" << endl;
        for (const auto& bridge : bridges) {
            cout << bridge[0] << " " << bridge[1] << endl;
        }

        return 0;
     
    }
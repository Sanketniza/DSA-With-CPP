
/* 

    ? Prim's Algorithm for Minimum Spanning Tree
    ? https://www.youtube.com/watch?v=rnYBi9N_vw4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=105

    You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the mini

    Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5
Explanation of Input 1 :
The Minimum spanning tree for the given graph will contain the edges: (1,2) with weight 2, (1,4) with weight 6, (2,3) with weight 3 and (2,5) with weight 5.

 */

// Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.

// The algorithm operates by building this tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest possible connection from the tree to another vertex.

// The algorithm is as follows:


// 1. Initialize the minimum spanning tree with a vertex chosen at random.
// 2. Find all the edges that connect the tree to new vertices, find the minimum and add it to the tree.
// 3. Keep repeating step 2 until we get a minimum spanning tree.



#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // prepare adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // creating 3 data structure
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    // initial mark of above 3 ds
    for (int i = 0; i <= n; i++) {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // let's start the algorithm
    key[1] = 0;
    parent[1] = -1;

    for (int i = 0; i < n; i++) {
        int mini = INT_MAX;
        int u;

        // finding minimum wali node
        for (int v = 1; v <= n; v++) {
            if (mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // mst update
        mst[u] = true;

        // check it's adj (neighbor's)
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // stored parent array in ans and return it
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter the number of vertices" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    vector<pair<pair<int, int>, int>> g(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[i] = {{u, v}, w};
    }

    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m, g);

    cout << "Minimum Spanning Tree:" << endl;
    for (auto i : ans) {
        cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    }

    return 0;

}

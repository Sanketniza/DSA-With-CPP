/* 
    Dijkstra's Algorithm 

    ? https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&leftPanelTabValue=SUBMISSION

    Problem statement
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

Example:

Input:
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6

In the given input, the number of vertices is 4, and the number of edges is 5.

In the input, following the number of vertices and edges, three numbers are given. The first number denotes node ‘X’, the second number denotes node ‘Y’ and the third number denotes the distance between node ‘X’ and ‘Y’.

As per the input, there is an edge between node 0 and node 1 and the distance between them is 5.

The vertices 0 and 2 have an edge between them and the distance between them is 8.
The vertices 1 and 2 have an edge between them and the distance between them is 9.
The vertices 1 and 3 have an edge between them and the distance between them is 2.
The vertices 2 and 3 have an edge between them and the distance between them is 6.
Note:

1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.

2. There can be parallel edges i.e. two vertices can be directly connected by more than 1 edge.
Detailed explanation ( Input/output format, Notes, Images )
Sample input 1
2
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
Sample output 1
0 4 1 2 5
0 5 8 7
Explanation For Sample Output 1
Test case 1:

 */


#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int wt) {
        pair<int, int> p = make_pair(v, wt);
        adj[u].push_back(p);
        adj[v].push_back({u, wt}); 
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;

        set<pair<int, int>> st;
        st.insert({0, src});

        while (!st.empty()) {
            auto top = *(st.begin());
            st.erase(st.begin());

            int node = top.second;
            int dis = top.first;

            for (auto i : adj[node]) {
                if (dis + i.second < dist[i.first]) {
                    auto record = st.find({dist[i.first], i.first});
                    if (record != st.end()) {
                        st.erase(record);
                    }
                    dist[i.first] = dis + i.second;
                    st.insert({dist[i.first], i.first});
                }
            }
        }

        return dist;
    }
};

int main() {
    int v, e;
    cin >> v >> e;  // Read the number of vertices and edges

    Graph g;
    for (int i = 0; i < e; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        g.addEdge(x, y, wt);
    }

    vector<int> ans = g.dijkstra(0); // Source vertex is 0

    // Print the shortest path distances
    cout << "Shortest path distances from source 0: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0; // Terminate the program after processing one graph
}

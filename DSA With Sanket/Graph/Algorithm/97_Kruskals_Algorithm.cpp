/* 
     Lecture 97: Kruskal's Algorithm || Disjoint Set || Union by Rank & Path Compression

    Minimum Spanning Tree

    ? https://www.naukri.com/code360/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM


    Problem statement
You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.

Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 10^5
1 <= E <= 3 * 10^5
0 <= X < N
0 <= Y < N
1 <= W <= 10^4

where V and E represent the number of vertices and edges respectively.
X and Y represent the vertices between which there is an edge.
W is the weight of the edge.

Time limit: 1sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
Explanation for Sample Input 1:
The edge (2,3) having weight 8 will be excluded from the MST. The total weight of the MST then will be 1 + 3 + 5 = 9.
Sample Input 2:
4 4
1 2 6
2 3 2
1 3 2
1 0 2
Sample Output 2:
6

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a , vector<int> &b) {
  return a[2] < b[2];
}

void makeSet(vector<int> &rank , vector<int> &parent , int n) {
  for(int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

int findParent(vector<int> &parent , int node) {
  if(parent[node] == node) {
    return node;
  }
  return parent[node] = findParent(parent , parent[node]);
}

void unionSet(int u , int v , vector<int> &parent , vector<int> &rank) {
  u = findParent(parent , u);
  v = findParent(parent , v);

  if(rank[u] < rank[v]) {
    parent[u] = v;
  }
  else if(rank[v] < rank[u]) {
    parent[v] = u;
  }
  else {
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
  // sort the edge
  sort(edges.begin() , edges.end() , cmp);

  vector<int> rank(n);
  vector<int> parent(n);
  makeSet(rank , parent , n);

  int minWeigh = 0;

  for(int i = 0; i < edges.size(); i++) {
    int u = findParent(parent , edges[i][0]);
    int v = findParent(parent , edges[i][1]);
    int w = edges[i][2];

    if(u != v) {
      minWeigh += w;
      unionSet(u , v , parent , rank);
    }
  }

  return minWeigh;
}

int main() {
  // Example usage:
  vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};
  int n = 5; // Number of nodes

  int minSpanningTreeWeight = minimumSpanningTree(edges, n);
  cout << "The weight of the minimum spanning tree is: " << minSpanningTreeWeight << endl;

  return 0;
}

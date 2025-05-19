/* 
    Lecture 99: Articulation Points in Graphs
    Link: https://www.youtube.com/watch?v=aZXi1unBdJA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=99

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
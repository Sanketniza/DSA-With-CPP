#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<vector<int>> PrintBFS(int node , int e , vector<vector<int>> &edge) {

    // prepare the adj list

    for(int i = 0; i < edge.sise(); i++) {
        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

     // we need same more data structhure to keep track of visited nodes
    vector<int , bool> visited;

    // we need a queue to keep track of nodes to visit
    queue<int> q;

    // we need a vector to keep track of the result
    vector<vector<int>> result;

    for(int i = 0; i < node; i++) {

        if(!visited[i]) {
            vector<int> component;
            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                component.push_back(node);

                for(int neighbour : adj[node]) {
                    if(!visited[neighbour]) {
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }

            result.push_back(component);
        }
    }
}

int main() {

    int v = 5;
    int e = 4; 

    vector<vector<int>> edge = {
        {1,2},
        {2,3},
        {3,4},
        {3,5}
    };

    vector<vector<int>> result = PrintBFS(v, e, edge);

    cout << "element in the graph are : " << endl;

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

 return 0;
}
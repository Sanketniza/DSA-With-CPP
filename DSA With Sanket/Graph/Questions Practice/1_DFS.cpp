
    #include<iostream>
    #include<bits/stdc++.h>
    #include<vector>
    #include<list>
    using namespace std;

    void dfs(int node , vector<int , list<int> > &adj, vector<int ,bool> &visited , vector<int> &component) {
        
        component.push_back(node);
        visited[node] = true;

        for(int neighbour : adj[node]) {
            if(visited[neighbour] == false) {
                dfs(neighbour , adj , visited , component);
            }
        }

        // for(int i = 0; i < adj.size(); i++) {
        //     if(visited[i] == false) {
        //         dfs(i , adj , visited , component);
        //     }
        // }
    }
    
    vector<vector<int> > depthFirstSearch(int v , int e , vector<vector<int> > &edge) {
        
        vector<int , list<int> > adj;
    
        for(int i = 0; i < edge.size(); i++) {
            int u = edge[i][0];
            int v = edge[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
            
        vector<int ,bool> visited;
        vector<vector<int> > result;

        for(int node = 1; node < v; node++) {
            
            if(!visited[node]) {
                vector<int> component;
                dfs(node, adj , visited , component);
                result.push_back(component);
            }
        }

        return result;
    
    }
    
    int main() { 
    
        int v = 10;
        int e = 9;
    
        vector<vector<int>> edge = {
            {1, 0},
            {2, 0},
            {3, 0},
            {4, 0},
            {5, 0},
            {6, 0},
            {7, 0},
            {8, 0},
            {9, 0}
        };
    
        vector<vector<int> > ans = depthFirstSearch(v , e ,edge);
    
        for(const auto& component : ans) {
            for(int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
    
        return 0;
    }
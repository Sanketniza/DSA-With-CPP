
/* 
    ? Topological Sort Using Kahn's Algorithm
    ? https://www.geeksforgeeks.org/topological-sorting/
    ? https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

     
Problem statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

For example, Consider the DAG shown in the picture.


In this graph, there are directed edges from 0 to 1 and 0 to 3, so 0 should come before 1 and 3. Also, there are directed edges from 1 to 2 and 3 to 2 so 1 and 3 should come before 2.

So, The topological sorting of this DAG is {0 1 3 2}.

Note that there are multiple topological sortings possible for a DAG. For the graph given above one another topological sorting is: {0, 3, 1, 2}

Note:
1. It is guaranteed that the given graph is DAG.
2. There will be no multiple edges and self-loops in the given DAG.
3. There can be multiple correct solutions, you can find any one of them. 
4. Don’t print anything, just return an array representing the topological sort of the vertices of the given DAG.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1 <= V <= 10^4
0 <= E <= 10^4
0 <= u, v < V 

Where ‘T’ is the total number of test cases, ‘V’ is the number of vertices, ‘E’ is the number of edges, and ‘u’ and ‘v’ both represent the vertex of a given graph.

Time limit: 2 sec
Sample Input 1:
2
2 1
1 0
3 2
0 1
0 2
Sample Output 1:
1 0
0 2 1
Explanation of Sample Input 1:
Test case 1:
The number of vertices ‘V’ = 2 and number of edges ‘E’ = 1.
The graph is shown in the picture: 

The topological sorting of this graph should be {1, 0}  as there is a directed edge from vertex 1 to vertex 0, thus 1 should come before 0 according to the given definition of topological sorting.

Test case 2:
The number of vertices ‘V’ = 3 and number of edges ‘E’ = 2.
The graph is shown in the picture:

As there are two directed edges starting from 0, so 0 should come before 1 and 2 in topological sorting. 
Thus the topological sorting of this graph should be {0, 2, 1} or {0, 1, 2}
Sample Input 2:
2
1 0
4 4
0 1
0 3
1 2
3 2
Sample Output 2:
0
0 1 3 2
Explanation of Sample Input 2:
Test case 1:   
There is only a single vertex in the graph that is 0, so its topological sort will be {0}.

Test case 2:
See problem statement for its explanation

 */

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int> > &edges, int v , int e) {

    // prepare the adjacency list

    unordered_map<int,list<int> > adj;

    for (int i = 0; i < e; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find all indegree

    vector<int> indegree(v);

    for(auto i:adj) {
        for(auto j: i.second) {
            indegree[j]++;
        }
    }

    // push 0 indegree into queue

    queue<int> q;

    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs

    vector<int> ans;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        // updata the indegree of neighbors 

        for(auto neigneighbors : adj[front]) {
            indegree[neigneighbors]--;
                if(indegree[neigneighbors] == 0) {
                    q.push(neigneighbors);
                }
        }
    } 

    return ans;
}


int main() {

    int v = 4;
    int e = 4;

    vector<vector<int> > edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {3, 2}

    };

    vector<int> ans = topologicalSort(edges, v , e);

    cout << "Topological Sort : " << endl;
    for(auto i:ans) {
        cout << i << " ";
    }
    cout << endl;
    


    return 0;
}

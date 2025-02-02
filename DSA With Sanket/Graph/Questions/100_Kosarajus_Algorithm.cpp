
/* 
   ?  Lecture 100: Kosaraju's Algorithm for Strongly Connected Components |
? 
   ?  https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0

     Count Strongly Connected Components (Kosaraju’s Algorithm)
Hard
0/120
Average time to solve is 40m
Contributed by
75 upvotes
Asked in companies
Problem statement
You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the number of strongly connected components (SCCs) present in the graph.

A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected components of a graph are the subgraphs which are themselves strongly connected.

Note :
Use zero-based indexing for the vertices.

The given graph doesn’t contain any self-loops.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= V <= 10^4
0 <= E <= 10^4
0 <= a, b < V

Time Limit: 1 sec
Sample Input 1 :
1
5 6
0 1
1 2
1 4
2 3
3 2
4 0
Sample Output 1 :
2
Explanation of sample input 1 :
For the first test case, the graph is shown below. There are two SCCs in the graph, which are enclosed in the boxes as shown in the image below.

Sample Input 2 :
2
1 0
4 4
0 1
1 2
2 3
3 1
Sample Output 2 :
1
2

 */
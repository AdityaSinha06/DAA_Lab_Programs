//shortest path algorithms :: single source : from a node to any other node in the graph :
// ----> 2 ways : 1. dijstra algo (not suitable for graphs with -ve wts and graph with -ve cycles)
//                2. bellman's ford algo (suitable for -ve wts and detects with -ve cycles)

//multisource :: shortest path bw every pair of nodes present in the graph.
//---> floyd warshall algo :: shortest path :: via all the nodes find the minimum path length
//::::> -ve cycle detects when dist[i][i] < 0 

//algo :: floyd warshall : shortest distance bw every pair of nodes :: nodes from 1 - n

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(int V , vector<vector<int>> &edgeList) {
    vector<vector<int>> dist(V+1 , vector<int>(V+1 , INT_MAX));

    for(int i=1; i<=V; i++) {
        dist[i][i] = 0;
    }

    //find shortest dist bw every pair of nodes
    for(int via=1; via<=V; via++) {
        for(int i=1; i<=V; i++) {
            for(int j=1; j<=V; j++) {
                if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j] , (dist[i][via] + dist[via][j]));
            }
        }
    }

    //check for -ve cycles::
    for(int i=1; i<=V; i++) {
        if(dist[i][i] < 0) {
            cout << "Negative cycle exists.\n";
            break;
        }
    }


    return dist;
}
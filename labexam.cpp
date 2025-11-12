#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> floydWarshall(int V , vector<vector<int>> &edgeList){
        vector<vector<int>> dist(V+1 , vector<int>(V+1 , INT_MAX));
            for(int i=1; i<=V; i++) {
                dist[i][i] = 0;
            }

    
    for(int via=1; via<=V; via++) {
        for(int i=1; i<=V; i++) {
            for(int j=1; j<=V; j++) {
                if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j] , (dist[i][via] + dist[via][j]));
            }
        }
    }

    
    for(int i=1; i<=V; i++) {
        if(dist[i][i] < 0) {
            cout << "Negative cycle exists.\n";
            break;
        }
    }


    return dist;
}
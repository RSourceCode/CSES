#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

void DFS(int start, vector<vector<long long>>& adj, vector<int>& visited){
    visited[start] = 1;
    for(auto c : adj[start]){
        if(!visited[c]) DFS(c, adj, visited);
    }
}

long long Bellman_Ford(int start,int n, vector<vector<long long>>& edges, vector<int>& vis1, vector<int>& visn){
    vector<long long> d(n, LLONG_MAX);
    d[start] = 0;
    for(int i = 0; i < n; i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            long long w = edge[2];
            if(d[u] != LLONG_MAX){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    
                    if(i >= n - 1 && vis1[v] && visn[v]){
                        // cout << u << ":" << d[u] << " " << v << ":" << d[v] << " " << w << endl;
                        return -1;
                    }
                }
            }
        }
    }
    return -d[n - 1];
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> edges;
    vector<vector<long long>> adj1(n);
    vector<vector<long long>> adjn(n);
    for(int i = 0; i < m; i++){
        long long a, b, x;
        cin >> a >> b >> x;
        edges.push_back({a - 1, b - 1, -x}); // Pushing -ve weights to allow us to use bellman ford to find the longest path.
        adj1[a - 1].push_back(b - 1);
        adjn[b - 1].push_back(a - 1);
    }
    vector<int> vis1(n, 0);
    vector<int> visn(n, 0);
    DFS(0, adj1, vis1);
    DFS(n - 1, adjn, visn);
    // for(int i = 0; i < m; i++){
    //     // cout << visn[i] << " ";
    //     cout << edges[i][0] << " " << edges[i][1] << " "  << edges[i][2] << endl; 
    // }
    // cout << endl;
    long long ans = Bellman_Ford(0, n, edges, vis1, visn);
    cout << ans;

    
    return 0;
}
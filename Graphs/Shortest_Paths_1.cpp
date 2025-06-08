#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#define INF LLONG_MAX

using namespace std;

vector<long long> Dijisktra(int start, vector<vector<pair<int, long long>>>& adj){
    vector<long long> d(adj.size(), INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    d[start] = 0;
    pq.push({d[start], start});

    while(!pq.empty()){
        pair<long long, int> vert = pq.top();
        pq.pop();
        int u = vert.second;
        long long d_u = vert.first;
        if(d[u] < d_u){
            continue;
        }
        for(auto child : adj[u]){
            int c = child.first;
            long long w_uc = child.second;
            if(d[c] > d_u + w_uc){
                d[c] = d_u + w_uc;
                pq.push({d[c], c});
            }
        } 
    }
    for(int i = 0; i < adj.size(); i++){
        cout << d[i] << " ";
    }
    
    return d;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, long long>>> adj(n, vector<pair<int, long long>>(0, {0, 0}));
    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    vector<long long> shortest_dist = Dijisktra(0, adj);
    
    // for(int i = 0; i < adj.size(); i++){
    //     cout << shortest_dist[i] << " ";
    // }
    return 0;
}
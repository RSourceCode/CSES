#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<limits.h>
#define int long long
#define INF (LLONG_MAX / 4)

using namespace std;

void dijisktra(int start,vector<long long>& d, vector<vector<pair<int, int>>>& adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[start] = 0;
    pq.push({d[start], start});

    while(!pq.empty()){
        pair<int, int> vert = pq.top(); 
        pq.pop();
        int u = vert.second; int d_u = vert.first;
        if(d[u] < d_u) continue;
        for(auto child : adj[vert.second]){
            int v = child.first; int w_uv = child.second;
            if(d[v] > d_u + w_uv){
                d[v] = d[u] + w_uv;
                pq.push({d[v], v});
            }
        }
    }
}


signed main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    
    int n, m;
    cin >> n >> m;  

    vector<tuple<int, int, int>> edges;
    vector<vector<pair<int, int>>> adj1(n, vector<pair<int, int>>(0));
    vector<vector<pair<int, int>>> adjn(n, vector<pair<int, int>>(0));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj1[a - 1].push_back({b - 1, c});
        adjn[b - 1].push_back({a - 1, c});
        edges.push_back({a - 1, b - 1, c});
    }
    
    vector<long long> d1(n, INF);
    vector<long long> dn(n, INF);

    dijisktra(0, d1, adj1);
    dijisktra(n - 1, dn, adjn);
    
    int _min = LLONG_MAX;
    // [u, v, w] throwing error. WHY?

    for(auto edge : edges){
        if(_min > d1[get<0>(edge)] + dn[get<1>(edge)] + get<2>(edge)/2) _min = d1[get<0>(edge)] + dn[get<1>(edge)] + get<2>(edge)/2;
    }

    cout << _min << endl;

    return 0;
}







// Approach 1 : TLE

// #include<iostream>
// #include<vector>
// #include<queue>
// #include<math.h>
// #include<limits.h>
// #define INF LLONG_MAX

// using namespace std;

// long long Dijisktra(int start, vector<vector<pair<int, long long>>>& adj){
//     vector<long long> d(adj.size(), INF);
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//     d[start] = 0;
//     pq.push({d[start], start});

//     while(!pq.empty()){
//         pair<long long, int> vert = pq.top();
//         pq.pop();
//         int u = vert.second;
//         long long d_u = vert.first;
//         if(d[u] < d_u){
//             continue;
//         }
//         for(auto child : adj[u]){
//             int c = child.first;
//             long long w_uc = child.second;
//             if(d[c] > d_u + w_uc){
//                 d[c] = d_u + w_uc;
//                 pq.push({d[c], c});
//             }
//         } 
//     }
//     // for(int i = 0; i < adj.size(); i++){
//     //     cout << d[i] << " ";
//     // }
    
//     return d[adj.size() - 1];
// }

// int main(){
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif

//     int n, m;
//     cin >> n >> m;
    
//     vector<vector<pair<int, long long>>> adj(n, vector<pair<int, long long>>(0, {0, 0}));
//     for(int i = 0; i < m; i++){
//         int a, b;
//         long long c;
//         cin >> a >> b >> c;
//         adj[a - 1].push_back({b - 1, c});
//     }
//     long long _min = LLONG_MAX;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < adj[i].size(); j++){
//             int temp = adj[i][j].second;
//             adj[i][j].second = floor(adj[i][j].second / 2);
//             long long shortest_dist = Dijisktra(0, adj);
//             if(shortest_dist < _min){
//                 _min = shortest_dist;
//             }
//             adj[i][j].second = temp;
//         }
//     }

//     cout << _min;
    
//     return 0;
// }
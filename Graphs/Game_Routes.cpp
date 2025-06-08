#include<iostream>
#include<vector>
#include<algorithm>
#define MOD (1000000000 + 7)

using namespace std;

void DFS(int source, int& clock,vector<int>& start, vector<int>& finish,vector<int>& visited, vector<vector<int>>& adj){
    visited[source] = 1;
    clock ++;
    start[source] = clock;
    for(auto child : adj[source]){
        if(!visited[child]){
            DFS(child, clock, start, finish, visited, adj);
        }
    }
    clock++;
    finish[source] = clock;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(0));
    vector<vector<int>> rev_adj(n, vector<int>(0));
    for(int i = 0; i < m; i++){
        int a , b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        rev_adj[b - 1].push_back(a - 1);
    }

    int clock = 0;
    vector<int> start(n, 0);
    vector<int> finish(n, 0);
    vector<int> visited(n, 0);

    DFS(0, clock, start, finish, visited, adj);
    vector<pair<int, int>> topo(n);
    for(int i = 0; i < n; i++){
        topo[i].first =  finish[i];
        topo[i].second = i;
    }
    sort(topo.rbegin(), topo.rend());
    // for(int i = 0; i < n; i++){
    //     cout << topo[i].second << " ";
    // }
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(auto i : topo){
        for(auto child : rev_adj[i.second]){
            dp[i.second] += dp[child];
            dp[i.second] = dp[i.second] % MOD;
        }
    }
    
    cout << dp[n - 1] << endl;

}
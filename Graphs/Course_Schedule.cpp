#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void DFS(int source, int& clock, bool& has_cycle, vector<int>& start, vector<int>& finish, vector<int>& visited, vector<vector<int>>& adj){
    visited[source] = 1;
    clock += 1;
    start[source] = clock;
    for(auto child : adj[source]){
        if(has_cycle){
            return;
        }
        if(!visited[child]){
            DFS(child ,clock ,has_cycle, start, finish, visited, adj);
        }
        else{
            if(start[source] > start[child] && finish[child] == 0){
                has_cycle = 1;
            }
        }
    }
    clock += 1;
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
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back( b - 1);
        if(a == b){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    int clock = 0;
    bool has_cycle = 0;
    vector<int> start(n, 0);
    vector<int> finish(n, 0);
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i, clock, has_cycle, start, finish, visited, adj);
        }
    }
    if(!has_cycle){
        vector<pair<int, int>> topo(n);
        for(int i = 0; i < n; i++){
            topo[i] = {finish[i], i};
        }
        sort(topo.begin(), topo.end());
        for(int i = n - 1; i >= 0; i--){
            cout << topo[i].second + 1 << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
}
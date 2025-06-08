#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

void DFS(int source, int& clock, vector<int>& start, vector<int>& finish, vector<int>& visited, vector<vector<pair<int ,int>>> adj){
    visited[source] = 1;
    clock++;
    start[source] = clock;
    for(auto child : adj[source]){
        if(!visited[child.first]){
            DFS(child.first, clock, start, finish, visited, adj);
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
    vector<vector<pair<int ,int>>> adj(n, vector<pair<int ,int>>(0));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >>c;
        adj[a - 1].push_back({b - 1, c});
    }   
    
    

    return 0;
}
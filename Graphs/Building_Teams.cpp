#include<iostream>
#include<vector>

using namespace std;

void DFS(int start,bool& impossible, vector<vector<int>>& adj, vector<int>& visited){

    for(int i = 0; i < adj[start].size(); i++){
        
        if(!visited[adj[start][i]]){
            visited[adj[start][i]] = visited[start] == 1 ? 2 : 1;
            DFS(adj[start][i],impossible, adj,  visited);
            if(impossible){
                return;
            }
        }
       
        if(visited[adj[start][i]] == visited[start]){
            impossible = 1;
            cout << "IMPOSSIBLE";
            return;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(0, 0));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1); 
        adj[b - 1].push_back(a - 1); 
    } 
    
    vector<int> visited(n, 0);
    bool impossible = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            
            DFS(i, impossible, adj, visited);
            if(impossible){
                return 0;
            }
        }
    }
    if(!impossible){
        for(int i = 0; i < n; i++){
            cout << visited[i] << " ";
        }
    }

    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

vector<int> BFS(int start, vector<vector<int>> adj){
    queue<int> q, n;
    vector<int> visited(adj.size(), 0);
    vector<int> parent(adj.size(), 0);

    q.push(start);
    n.push(0);
    visited[0]  = 1;

    bool found = 0;
    int con_len = 0;

    while(!q.empty() && !found){
        int vert = q.front();
        int num = n.front();
        q.pop();
        n.pop();
        for(int i = 0; i < adj[vert].size(); i++){
            if(adj[vert][i] == adj.size() - 1){
                parent[adj[vert][i]] = vert;
                visited[adj[vert][i]] = 1;
                found = 1;
                con_len = num + 1;
                break;
            }
            else{
                if(!visited[adj[vert][i]]){
                    parent[adj[vert][i]] = vert;
                    visited[adj[vert][i]] = 1;
                    q.push(adj[vert][i]);
                    n.push(num + 1);
                }
            }
        }
    }
    
    vector<int> path;
    path.push_back(adj.size());
    if(found){
        int temp = adj.size() - 1;
        for(int i = 0; i  < con_len; i++){
            path.push_back(parent[temp] + 1);
            temp = parent[temp];
        }
        
    }

    return path;
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

    vector<int> connection = BFS(0, adj);
    if(connection.size() == 1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << connection.size() << endl;
        for(int i = connection.size() - 1; i >= 0 ; i--){
            cout << connection[i] << " ";
        }
    }
    return 0;
}
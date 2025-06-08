#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int BFS(int start, vector<int>& parent, vector<vector<int>>& adj){
    int n = parent.size();
    vector<int> distance(n, -1);
    queue<int> vertices;
    vertices.push(start);
    while(!vertices.empty()){
        int v = vertices.front();
        vertices.pop();
        for(auto child : adj[v]){
            if(distance[child] == -1){
                distance[child] = distance[v] + 1;
                parent[child] = v;
                vertices.push(child);
            }
            else{
                if(distance[child] < distance[v] + 1){
                    distance[child] = distance[v] + 1;
                    parent[child] = v;
                    vertices.push(child);
                }
            }
        }
    }
    return distance[n - 1];
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
        adj[a - 1].push_back(b - 1);
    }
    vector<int> parent(n, -1);
    int ans = BFS(0, parent, adj);
    if(ans == -1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << ans + 2 << endl;
        vector<int> path;
        int temp = n - 1;
        while(parent[temp] != -1){
            path.push_back(temp + 1);
            // cout << temp + 1 << " ";
            temp = parent[temp];
        }
        path.push_back(1);
        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
    }

    return 0;
}
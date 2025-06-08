#include<iostream>
#include<vector>


using namespace std;

void DFS(int start, vector<vector<int>>& adj, vector<int>& visited){
    for(int i = 0; i < adj[start].size(); i++){
        if(!visited[adj[start][i]]){
            visited[adj[start][i]] = 1;
            DFS(adj[start][i], adj, visited);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(0,0));

    for(int i = 0; i < m; i++){
        int temp_a, temp_b;
        cin >> temp_a >> temp_b;
        adj[temp_a - 1].push_back(temp_b - 1); 
        adj[temp_b - 1].push_back(temp_a - 1); 
    }

    vector<int> visited(n, 0);
    vector<pair<int, int>> roads;
    int prev_node = 0;
    int num_roads = 0;

    for(int i = 0;  i < n; i++){
        if(visited[i] == 0){
            if(i != 0){
                roads.push_back({prev_node, i});
                num_roads++;
            }
            DFS(i, adj, visited);
        }
    }
    cout << num_roads << endl;
    for(auto p : roads){
        cout << p.first + 1 << " " << p.second + 1<< endl;
    }

    return 0;
}
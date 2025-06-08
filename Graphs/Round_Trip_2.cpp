#include<iostream>
#include<vector>


using namespace std;

void previsit(int node, int& clock,  vector<int>& start){
    clock += 1;
    start[node] = clock;
}

void postvisit(int node, int& clock,  vector<int>& finish){
    clock += 1;
    finish[node] = clock;
 }

void Print_Path(int source, int goal, vector<int>& parent, vector<vector<int>>& adj){
    int temp = parent[source];
    vector<int> path;
    path.push_back(source + 1);
    // for(auto p : parent){
    //     cout << p << " ";
    // }
    while(temp != goal){
        path.push_back(temp + 1);
        temp = parent[temp];
    }
    path.push_back(goal + 1);
    path.push_back(source + 1);
    cout << path.size() << endl;
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " "; 
    }
}

void DFS(int source, int& clock, bool& has_cycle, vector<int>& start, vector<int>& finish, vector<int>& visited, vector<int>& parent, vector<vector<int>>& adj){
    visited[source] = 1;
    previsit(source, clock, start);
    for(auto child : adj[source]){
        if(has_cycle){
            return;
        }
        if(!visited[child]){
            parent[child] = source;
            DFS(child, clock, has_cycle, start, finish, visited, parent, adj);
        }
        else{
            if(start[child] < start[source] && finish[child] == 0){
                // Back Edge Detected !
                has_cycle = 1;
                Print_Path(source, child, parent, adj);
                return;
            }
        }
    }
    postvisit(source, clock, finish);
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
    int clock = 0;
    bool has_cycle = 0;
    vector<int> start(n, 0);
    vector<int> finish(n, 0);
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i, clock, has_cycle, start, finish, visited, parent, adj);
            if(has_cycle){
                break;
            }
        }
    }

    if(!has_cycle){
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}
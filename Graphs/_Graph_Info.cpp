// Graph Algos :
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Standard DFS
void DFS(int start, vector<vector<long long>>& adj, vector<int>& visited){
    visited[start] = 1;
    for(auto c : adj[start]){
        if(!visited[c]) DFS(c, adj, visited);
    }
}

// Standard BFS
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

// DFS with start and finish, useful for topoplogical sorting
void DFS(int start, int& clock, vector<int>& finish, vector<int>& visited, vector<vector<int>>& adj){
    visited[start] = 1;
    for(auto child : adj[start]){
        if(!visited[child]){
            visited[child] = 1;
            DFS(child ,clock, finish, visited, adj);
        } 
    }
    finish[start] = ++clock;
}
// DFS for tagging all strongly connected components
void DFS_with_tag(int start, int tag, vector<int>& visited, vector<vector<int>>& adj){
    visited[start] = tag;
    for(auto child : adj[start]){
        if(!visited[child]){
            visited[child] = tag;
            // cout << visited[child] << " " ;
            DFS_with_tag(child , tag, visited, adj);
        } 
    }
}

// Dijisktra
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


long long Bellman_Ford(int start,int n, vector<vector<long long>>& edges, vector<int>& vis1, vector<int>& visn){
    vector<long long> d(n, LLONG_MAX);
    d[start] = 0;
    for(int i = 0; i < n; i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            long long w = edge[2];
            if(d[u] != LLONG_MAX){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    // return -1 if cycle exists
                    // if(i >= n - 1 && vis1[v] && visn[v]){
                    //     return -1;
                    // }
                }
            }
        }
    }
    return d[n - 1];
}

void All_Pair_Shortest_Path(vector<vector<long long>>& adj, vector<vector<long long>>& dp){
    int n = adj.size();
    // initializing dp matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = adj[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(dp[i][k] != -1 && dp[k][j] != -1){
                    if(dp[i][j] != -1){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                        dp[j][i] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                    else{
                        dp[i][j] = dp[i][k] + dp[k][j];
                        dp[j][i] = dp[i][k] + dp[k][j];
                    }
                }
                else{
                    dp[i][j] = dp[i][j];
                    dp[j][i] = dp[i][j];
                }
            }
        }
    }
}


// Find and Merge
int Find(int u, vector<int>& parent){
    int temp = u;
    while(parent[temp] != temp) temp = parent[temp];
    return temp;
}

void Merge(int u, int v, vector<int>& height, vector<int>& parent){
    u = Find(u, parent); v = Find(v, parent);
    if(height[u] < height[v]) parent[u] = v;
    else if(height[u] > height[v]) parent[v] = u;
    else{
        parent[u] = v;
        height[v]++;
    }
}
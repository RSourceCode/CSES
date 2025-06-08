#include<iostream>
#include<chrono>
#include<vector> 
#include<algorithm>

using namespace std;

void DFS(int source, int& clock, vector<int>& visited, vector<int>& finish, vector<vector<int>>& adj){
    visited[source] = 1;
    clock++;
    for(auto child : adj[source]){
        if(!visited[child]){
            DFS(child, clock, visited, finish, adj);
        }
    } 
    clock++;
    finish[source] = clock;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev_adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    int _clock = 0;
    vector<int> finish(n + 1, 0);
    vector<int> visited(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i, _clock, visited, finish, rev_adj);
        }
    }
    int max_fin_time = 0;
    int vert = 0;
    for(int i = 1; i <= n; i++){
        if(finish[i] > max_fin_time){
            max_fin_time = finish[i];
            vert = i;
        }
        visited[i] = 0;
    }   
    DFS(vert, _clock, visited, finish, adj);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cout << "NO\n" << vert << " " << i;
            return 0;
        }
    }

    cout << "YES";

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
    
    return 0;
}
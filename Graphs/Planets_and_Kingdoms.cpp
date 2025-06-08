#include<iostream>
#include<chrono>
#include<vector> 
#include<algorithm>

using namespace std;

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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    int _clock = 0;
    vector<int> visited(n + 1, 0);
    vector<int> finish(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i, _clock, finish, visited, rev_adj);
    }

    vector<vector<int>> finish_with_idx(n + 1, vector<int>(2, 0));
    for(int i = 1; i <= n; i++){
        finish_with_idx[i][0] = finish[i];
        finish_with_idx[i][1] = i;
        visited[i] = 0;
    }
    sort(finish_with_idx.rbegin(), finish_with_idx.rend());
    int tag = 1;
    for(auto f : finish_with_idx){
        if(!visited[f[1]]){
            // cout << f[1] << " ";
            DFS_with_tag(f[1], tag, visited, adj);
            tag++;
        } 
    }
    cout << tag - 2 << endl;
    for(int i = 1; i <= n; i++){
        cout << visited[i] << " ";
    }
    // cout << endl << tag;

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
    
    return 0;
}
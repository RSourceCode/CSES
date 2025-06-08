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
    vector<vector<int>> adj(2*(m + 1));
    vector<vector<int>> rev_adj(2*(m + 1));


    for(int i = 0; i < n; i++){
        int b, d; char a, c;
        cin >> a >> b >> c >> d;
        if((a == '+' && c == '+') || (a == '-' && c == '-')){
            adj[b + m].push_back(d);
            adj[d + m].push_back(b);
            rev_adj[d + m].push_back(b);
            rev_adj[b + m].push_back(d);
        } 
        else if((a == '+' && c == '-')){
            adj[b + m].push_back(d + m); 
            adj[d].push_back(b);
            rev_adj[d + m].push_back(b + m); 
            rev_adj[b].push_back(d);
        } 
        else if((a == '-' && c == '+')){ 
            adj[b].push_back(d);
            adj[d + m].push_back(b + m); 
            rev_adj[d].push_back(b);
            rev_adj[b + m].push_back(d + m); 
        } 
        else {
            adj[b].push_back(d + m); 
            adj[d].push_back(b + m); 
            rev_adj[d].push_back(b + m); 
            rev_adj[b].push_back(d + m); 
        } 
    }
    // for(int i = 1; i <= 2*m; i++){
    //     for(auto child : adj[i]){
    //         cout << child << " ";
    //     }
    //     cout << endl;
    // }
    int _clock = 0;
    vector<int> visited(2*(m + 1), 0);
    vector<int> finish(2*(m + 1), 0);
    for(int i = 1; i <= 2*(m); i++){
        if(!visited[i]) {
            // cout << i << " " ;
            DFS(i, _clock, finish, visited, rev_adj);
        }
    }

    vector<vector<int>> finish_with_idx(2*(m + 1), vector<int>(2, 0));
    for(int i = 1; i <= 2*m; i++){
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
    // for(int i = 1; i <= 2*m; i++){
    //     cout << visited[i] << " ";
    // }
     // OUTPUT FORMAT PRINTING
     for(int i = 1; i <= m; i++){
        if(visited[i] == visited[m + i]){
        }
        else if(visited[m + i] > visited[i]){
            cout << "- ";
        }
        else{
            cout << "+ ";
        }
    }

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
    
    return 0;
}
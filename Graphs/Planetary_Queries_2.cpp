#include<iostream>
#include<vector> 
#include<algorithm>
#include<queue>
#include<chrono>

using namespace std;

int dp1[200005][32];
vector<int> len(200005, 0);

void DFS(int start, vector<int>& visited){
    visited[start] = 1;
    if(!visited[dp1[start][0]]){
        DFS(dp1[start][0], visited);
    }
    len[start] = len[dp1[start][0]] + 1;
}

int k_moves(int start, int k){
    if(k <= 0){
        return start;
    }
    int y = 0;
    while(k){
        if(k & 1) start = dp1[start][y];
        y++;
        k >>= 1;
    }
    return start;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();  
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++){
        cin >> dp1[i][0];
    }

    for(int i = 1; i < 32; i++){
        for(int j = 1; j < n + 1; j++){
            dp1[j][i] = dp1[dp1[j][i - 1]][i - 1];
        }
    }

    vector<int> visited(n, 0);

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i, visited);
        }
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        int c = k_moves(a, len[a] + 1);
        if(k_moves(a, len[a] - len[b]) == b)
            cout << len[a] - len[b] << endl;
        else if(k_moves(c, len[c] - len[b]) == b)
            cout << len[a] + len[c] - len[b] + 1 << endl;
        else
            cout << -1 << endl;
    }

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
    
    return 0;
}
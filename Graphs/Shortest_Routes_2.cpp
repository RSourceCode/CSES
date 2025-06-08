#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j][n] << " ";
    //     }
    //     cout << endl;
    // }
}

int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> adj(n, vector<long long>(n, -1));

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(adj[a - 1][b - 1] != -1 && adj[a - 1][b - 1] > c){
            adj[a - 1][b - 1] = c;
            adj[b - 1][a - 1] = c;
        }
        else if (adj[a - 1][b - 1] == -1){
            adj[a - 1][b - 1] = c;
            adj[b - 1][a - 1] = c;
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    All_Pair_Shortest_Path(adj, dp);

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << dp[a - 1][b - 1] << endl;
    }
}
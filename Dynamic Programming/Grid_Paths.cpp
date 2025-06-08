#include<iostream>
#include<vector> 
#include<algorithm>
#define MOD 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(grid[0][0] == '.') dp[0][0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + 1 < n && grid[i + 1][j] == '.') dp[i + 1][j] = (dp[i + 1][j]  + dp[i][j]) % MOD;
            if(j + 1 < n && grid[i][j + 1] == '.') dp[i][j + 1] = (dp[i][j  + 1]  + dp[i][j]) % MOD;
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n - 1][n - 1];

    return 0;
}
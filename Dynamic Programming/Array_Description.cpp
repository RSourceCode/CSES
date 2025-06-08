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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));
    for(int i = 1; i <= m; i++){
        if(arr[0] == 0) dp[0][i] = 1;
        else dp[0][arr[0]] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i] == 0){
                if(j == 1) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
                else if(j == m) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
            }
            else{
                if(arr[i] == 1) dp[i][arr[i]] = (dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD;
                else if(arr[i] == m) dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]]) % MOD;
                else dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD;
            }
        }
    }
    long long ans = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n - 1][i]) % MOD;
    }
    cout << ans;
    return 0;
}
#include<iostream>
#include<vector> 
#include<algorithm>
#define MOD 1000000007

using namespace std;

long long dp[1000002][3];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    
    //                                      _  _
    // dp[i][1] = last blocks are separate | || |
    //                                   _ _
    // dp[i][2] = last blocks are fused |   |
    
    // transition:
    //              _  _    _  _    _  _    _  _     _ _
    //  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
    // | || | =>   | || |, | || |, | || |, | || |,  |   |
    //              _ _    _ _    _ _ 
    //  _ _        |   |  |_ _|  |_ _|
    // |   |  =>   |   |, |   |, | | |
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        // vector<vector<long long>> dp(n + 1, vector<long long>(3 , 0));
        dp[1][1] = 1;
        dp[1][2] = 1;
        for(int i = 2; i <= n; i++){
            dp[i][1] = (dp[i - 1][1] * 4 + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][2] * 2) % MOD;
        }
        cout << (dp[n][1] + dp[n][2]) % MOD << endl;
    }

    return 0;
}
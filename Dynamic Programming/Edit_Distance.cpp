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
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }

    for(int i = 1; i <= m; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if(a[i - 1] == b[j - 1]) dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
            else dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m];
    return 0;
}
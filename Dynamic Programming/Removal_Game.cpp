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
    int n; cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    for(int i = 0; i < n; i++){
        dp[i][i] = arr[i];
        if(i != n - 1) dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for(int i = 2; i < n; i++){
        for(int j = 0; j < n - i; j++){
            // dp[j][j + i] = max(arr[j + i] + dp[j][j + i - 2],arr[j] + dp[j + 2][j + i]);
            // dp[j][j + i] = max(dp[j][j + i], max(arr[j + i], arr[j]) + dp[j + 1][j + i - 1]);
            //Case 1:  take left one
            long long l = arr[j] + min(dp[j + 2][j + i], dp[j + 1][j + i - 1]);
            //Case 2: take right one
            long long r = arr[j + i] + min(dp[j + 1][j + i - 1], dp[j][j + i - 2]);
            dp[j][j + i] = max(l, r);
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][n - 1] << endl;
    return 0;
}
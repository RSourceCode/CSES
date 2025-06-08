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
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    int _min = min(n, 6);;
    for(int i = 1; i <= _min; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j];
        }
    }
    for(int i = 7; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) % MOD;
    }
    cout << dp[n];
    return 0;
}
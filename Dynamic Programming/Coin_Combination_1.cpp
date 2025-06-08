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
    int n, x;
    cin >> n >> x;
    vector<long long> denom(n + 1, 0);
    vector<long long> dp(x + 1, 0);

    for(int i = 0; i < n; i++){
        cin >> denom[i];
        if(denom[i] <= x) dp[denom[i]] = 1;
    }

    for(int i = 0; i < x; i++){
        if(dp[i]){
            for(int j = 0; j < n; j++){
                if(i + denom[j] <= x)
                    dp[i + denom[j]] = (dp[i + denom[j]] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[x];

    return 0;
}
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
    int sum = (n * (n + 1)) / 4;
    vector<int> dp(sum  + 1, 0);
    if(n % 4 == 2 || n % 4 == 1) {
        cout << -1 << endl;
        return 0;
    }
    else{
        for(int i = 1; i <= n; i++){
            for(int j = sum; j >= 0; j--){
                if(j == 0) dp[i] += 1;
                if(j - i > 0 && dp[j - i]) 
                    dp[j] += (dp[j] + dp[j - i]) % MOD;
            }
        }
        for(int j = 1; j <= sum; j++){
            cout << dp[j] << " ";
        }
    }
    
    return 0;
}
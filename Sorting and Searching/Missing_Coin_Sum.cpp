#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 1);
    vector<long long> a(n + 1, 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // dp[i - 1] is the largest integer we aren't able to make using smallest i - 1 numbers.
    for(int i = 1; i <= n; i++){
        // Idea is ki if I cannot reach a[i] I will miss a[i] - 1; [and maybe more numbers below among which the smallest is dp[i -1]]
        // But if I can make all numbers upto a number bigger than or equal to a[i], I can make all num upto a[i] + dp[i - 1]
        if(dp[i - 1] < a[i]) return cout << dp[i - 1], 0;
        dp[i] = dp[i - 1] + a[i]; 
    }
    cout << dp[n];

    return 0;
}
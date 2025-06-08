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
    int n, max_sum = 0;
    cin >> n;
    vector<int> denom(n);
    for(int i = 0; i < n; i++){
        cin >> denom[i];
        max_sum += denom[i];
    } 
    max_sum++;
    vector<int> dp(max_sum, 0);
    int num_sums = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = max_sum - 1; j >= 0 ; j--){
            if(j + denom[i] < max_sum && dp[j]){
                if(!dp[j + denom[i]]) num_sums++;
                dp[j + denom[i]] = 1;
            } 
        }
    }
    cout << num_sums << endl;
    for(int i = 1; i < max_sum; i++){
        if(dp[i]) cout << i << " ";
    }
    return 0;
}
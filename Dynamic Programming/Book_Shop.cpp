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
    vector<int> num_pages(n);
    vector<int> cost(n);
    vector<int> dp(x + 1, 0);

    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    for(int i = 0; i < n; i++){
        cin >> num_pages[i];
    }


    for(int i = 0; i < n; i++){
        bool assigned = 0;
        if(cost[i] <= x){
            if(dp[cost[i]] < num_pages[i]){
                dp[cost[i]] = num_pages[i];
                // cout << i << " " << cost[i] << " "<< num_pages[i] << endl;
                assigned = 1;

            } 
        }
        for(int j = x; j >= 1; j--){
            if(!(j == cost[i] && assigned) && dp[j] && j + cost[i] <= x){
                // cout << cost[i] << " " << j << endl;
                if(dp[j + cost[i]] < dp[j] + num_pages[i])
                    dp[j + cost[i]]  = dp[j] + num_pages[i];
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
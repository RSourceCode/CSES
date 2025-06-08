#include<iostream>
#include<vector> 
#include<algorithm>
#include<math.h>
#define MOD 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n, q; cin >> n >> q;
    vector<int> arr(n + 1);
    vector<vector<int>> dp(int(log2(n)) + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[0].push_back(arr[i]);
    } 

    for(int i = 1; i <= int(log2(n)) + 1; i++){
        int pow_2 = 1 << i;
        for(int j = 0; j < n / pow_2; j++){
            dp[i].push_back(dp[i - 1][j * 2] + dp[i - 1][j * 2 + 1]);
        }
    }

    for(int i = 0; i <= int(log2(n)); i++){
        for(auto c : dp[i]){
            cout << c << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < q; i++){
        int c, a, b; cin >> c >> a >> b;

        if(c == 1){
            int prev_val = dp[0][a - 1];
            int temp = a - 1;
            for(int i = 0; i <= int(log2(n)) + 1; i++){
                dp[i][temp] = dp[i][temp] - prev_val + b;
                temp << 1;
            }
        }
        else{

        }
    }

    return 0;
}
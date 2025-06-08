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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2, 0), b(m + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    vector<vector<pair<int, int>>> parent(n + 2, vector<pair<int, int>>(m + 2, {0, 0}));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                parent[i][j] = {i - 1, j - 1};
            } 
            else {
                if(dp[i - 1][j] > dp[i][j - 1]){
                    dp[i][j] = dp[i - 1][j];            
                    parent[i][j] = {i - 1, j};
                }
                else{
                    dp[i][j] = dp[i][j - 1];            
                    parent[i][j] = {i, j - 1};
                }
            }  
        }
    }
        // for(int i = 0; i < n + 2; i++){
        //     for(int j = 0; j < m + 2; j++){
        //         cout << parent[i][j].first << "," << parent[i][j].second << " ";
        //         // cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[n][m] << endl;
        pair<int, int> temp = {n, m}, goal = {0, 0};
        vector<int> path;
        while(temp != goal){
            if(a[temp.first] == b[temp.second]){
                path.push_back(a[temp.first]);
            } 
            temp = parent[temp.first][temp.second];
        }
        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
    return 0;
}
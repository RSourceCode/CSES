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
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<vector<int>>> parent(n, vector<vector<int>>(n, vector<int>(2, 0)));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = grid[0][0] - 65;
    vector<int> z = {0 , 0};
    for(int i = 0; i < n ; i ++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j != 0) {
                dp[i][j] = dp[i][j - 1] + (grid[i][j] - 65);
                parent[i][j] = {i, j - 1};
            }
            else if(j == 0 && i != 0) {
                dp[i][j] = dp[i - 1][j] + (grid[i][j] - 65);
                parent[i][j] = {i - 1, j};
            }
            else if((i == 1 && j == 1)){
                if(dp[i - 1][j] <= dp[i][j - 1]){
                    dp[i][j] = dp[i - 1][j] + (grid[i][j] - 65);
                    parent[i][j] = {i - 1, j};
                }
                else if(dp[i - 1][j] >= dp[i][j - 1]){
                    dp[i][j] = dp[i][j - 1] + (grid[i][j] - 65);
                    parent[i][j] = {i, j - 1};
                }
            }
            else if(i != 0 && j != 0){
                if(dp[i - 1][j] <= dp[i][j - 1] && parent[i - 1][j] != z){
                    dp[i][j] = dp[i - 1][j] + (grid[i][j] - 65);
                    parent[i][j] = {i - 1, j};
                }
                else if(dp[i - 1][j] >= dp[i][j - 1] && parent[i][j - 1] != z){
                    dp[i][j] = dp[i][j - 1] + (grid[i][j] - 65);
                    parent[i][j] = {i, j - 1};
                }
            }
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            cout << parent[i][j][0] << "," << parent[i][j][1] << " "; 
        }
        cout << endl;
    }
    vector<int> temp = {0, 0};
    vector<int> goal = {n - 1, n - 1};
    // while(temp != goal){
    //     cout << grid[temp[0]][temp[1]];
    //     if(temp[0] != n - 1 && temp[1] != n - 1 && grid[temp[0] + 1][temp[1]] < grid[temp[0]][temp[1] + 1]){
    //         cout << grid[temp[0] + 1][temp[1]];
    //         temp = {temp[0] + 1, temp[1]};
    //     }
    //     else if(temp[0] != n - 1 && temp[1] != n - 1 && grid[temp[0] + 1][temp[1]] > grid[temp[0]][temp[1] + 1]){
    //         cout << grid[temp[0]][temp[1] + 1];
    //         temp = {temp[0], temp[1] + 1};
    //     }
    //     else{
    //         if(temp[0] != n - 1 && temp[1] != n - 1 && dp[temp[0] + 1][temp[1]] < dp[temp[0]][temp[1] + 1]){
    //             cout << grid[temp[0] + 1][temp[1]];
    //             temp = {temp[0] + 1, temp[1]};
    //         }
    //         else if(temp[1] != n - 1){
    //             cout << grid[temp[0]][temp[1] + 1];
    //             temp = {temp[0], temp[1] + 1};
    //         }
    //         else{
    //             cout << grid[temp[0] + 1][temp[1]];
    //             temp = {temp[0] + 1, temp[1]};
    //         }
    //     }
    //     // temp = parent[temp[0]][temp[1]];
    // }

    return 0;
}
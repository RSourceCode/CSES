#include<iostream>
#include<vector> 
#include<math.h>
#include<limits.h>
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
    int n, q; cin >> n >> q;
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> min_matrix(round(log2(n))  + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        min_matrix[0][i] = arr[i];
    }

    for(int i = 2; i <= n; i *= 2){
        for(int k = 1; k <= n - i + 1; k++){
            if(i == 2) min_matrix[round(log2(i))][k] = min(min_matrix[round(log2(i)) - 1][k], min_matrix[round(log2(i)) - 1][(k + 1)]);
            else min_matrix[round(log2(i))][k] = min(min_matrix[round(log2(i)) - 1][k], min_matrix[round(log2(i)) - 1][(k + i/2)]);
        }
    }
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        int k = log2(b - a + 1);
        int pow_2 = (1 << k) - 1;
        if(a == b) cout << arr[a] << endl;
        else cout << min(min_matrix[floor(k)][a], min_matrix[floor(k)][b - pow_2]) << endl;
    }
    return 0;
}
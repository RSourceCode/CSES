#include<iostream>
#include<vector> 
#include<algorithm>
#include<numeric>
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
    vector<int> coins(n + 1);
    vector<pair<int, int>> indx; 
    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
        indx.push_back({coins[i], i});
    }
    sort(indx.begin(), indx.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(indx[i + 1].second < indx[i].second) ans++;
    }
    cout << ans;
    return 0;
}
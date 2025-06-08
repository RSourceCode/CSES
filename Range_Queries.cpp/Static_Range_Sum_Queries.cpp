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
    int n, q;
    cin >> n >> q;
    vector<long long> cum_arr(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(i == 1) cin >> cum_arr[i];
        else{
            long long a; cin >> a;
            cum_arr[i] = cum_arr[i - 1] + a;
        }
    }
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        cout << cum_arr[b] - cum_arr[a - 1] << endl;
    }
    return 0;
}
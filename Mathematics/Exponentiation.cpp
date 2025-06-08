#include<iostream>
#include<vector> 
#include<algorithm>
#define MOD 1000000007

using namespace std;

int binary_exp(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long a, b; cin >> a >> b;
        cout << binary_exp(a, b) << endl;
    }

    return 0;
}
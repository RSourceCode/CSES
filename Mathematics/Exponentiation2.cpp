#include<iostream>
#include<vector> 
#include<algorithm>
#define MOD 1000000007
#define MOD2 1000000006

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
int binary_exp2(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD2;
        a = (a * a) % MOD2;
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
    // a^(p - 1) = 1 % p (where p is prime)
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long a, b, c; cin >> a >> b >> c ;
        long long d = binary_exp2(b, c);
        cout << binary_exp(a, d)<<'\n';
    }

    return 0;
}
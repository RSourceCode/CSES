#include<iostream> // basic input output
 
//Some commonly used libraries
#include<algorithm>
#include<math.h>
#include<limits.h>
 
// STL containers
#include<vector> 
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
 
using namespace std;
// Few short hand notations for data types
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
 
// Other short hand notations
#define f first
#define s second
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
 
// Used for faster input/output
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
// Constants
#define MOD 1000000007
#define INF 1e9;
#define LINF 1e18;
 
// Helper functions
template <typename T>
void print_vector(vector<T>& vec){
    for(auto ele : vec) cout << ele << " ";
    cout << '\n';
}
 
template <typename T>
T bin_exp(T a, T b){
    T res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return res % MOD;
}
 
template <typename T>
T gcd(T a, T b){
    if(a > b) swap(a, b);
    if(!a) return b;
    return gcd(b % a, a) % MOD; 
}
 
// template <typename T>
// T inv_mod(T a, T b){
//     if(a > b) swap(a, b);
//     static T x = 0, y = 0;
//     if(a == 0) {x = 1, y = 0; return x;}
//     inv_mod(a % b, a);
//     T temp_y = x;
//     x = (y - ((x * (b/a)) % MOD)) % MOD, y = temp_y % MOD;
//     return x;
// }
 
template <typename T>
T inv_mod(T a, T b){
    return bin_exp(a, b - 2);
}
 
ll factorial[1000001];
 
void Compute_Factorial(){
    factorial[0] = 1;
    factorial[1] = 1;
    for(ll i = 2; i < 1000001; i++) factorial[i] = (factorial[i - 1] * i) % MOD;
}
 
// template<typename T>
// T nCr(T n, T r){
//     if(r == 1){
//         return n % MOD;
//     }
//     r = r < n - r ? r : n - r;
//     return (((n * nCr(n - 1 , r - 1)) % MOD) / r) % MOD;
// }
 
int main(){
    FAST_IO;
 
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
 
    //Write your code Here.
    string s; cin >> s;
    int n = s.size();
    Compute_Factorial();
    ll ans = factorial[n];
    
    vll map(27, 0);
    rep(i, 0, n) map[s[i] - 'a']++;
    rep(i, 0, 26) ans = (ans * inv_mod(factorial[map[i]], ll(MOD)) % MOD);
    cout << ans;
    
    return 0;
}
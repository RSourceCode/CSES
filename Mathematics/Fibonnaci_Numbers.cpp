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

template<typename T>
T nCr(T n, T r){
    if(factorial[0] == 0) Compute_Factorial();
    return ((factorial[n] * inv_mod(factorial[r], ll(MOD))) % MOD * inv_mod(factorial[n - r], ll(MOD))) % MOD;
}

vector<vll> mat_mul(vector<vll> a, vector<vll> b){
    vector<vll> res;
    rep(i, 0, a.size()){
        vll temp;
        rep(j, 0, b[0].size()){
            ll val = 0;
            rep(k, 0, a[0].size()){
                val += (a[i][k] * b[k][j]) % MOD;
            }
            temp.pb(val);
        }
        res.pb(temp);
    }
    return res;
}

vector<vll> mat_bin_exp(vector<vll> a, ll b){
    vector<vll> res;
    rep(i, 0, a.size()){
        vll temp;
        rep(j, 0, a[0].size()){
            if(i == j)temp.pb(1);
            else temp.pb(0);
        }
        res.pb(temp);
    }
    while(b){
        if(b & 1) res = mat_mul(res, a);
        b = b >> 1;
        a = mat_mul(a, a);
    }
    return res;
}

int main(){
    FAST_IO;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    ll n; cin >> n;
    vector<vll> fib_mat = {{0, 1}, {1, 1}};
    vector<vll> res_fib_mat = mat_bin_exp(fib_mat, n);
    vector<vll> init_mat = {{0}, {1}};
    vector<vll> ans_mat = mat_mul(res_fib_mat, init_mat);
    cout << ans_mat[0][0];
    return 0;
}
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

// Helper function
template <typename T>
void print_vector(vector<T>& vec){
    for(auto ele : vec) cout << ele << " ";
    cout << '\n';
}

ll bin_exp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return res % MOD;
}

ll gcd(ll a, ll b){
    if(a > b) swap(a, b);
    if(!a) return b;
    return gcd(b % a, a); 
}


template <typename T>
T inv_mod(T a, T b){
    if(a > b) swap(a, b);
    static T x = 0, y = 0;
    if(a == 0) {x = 1, y = 0; return x;}
    inv_mod(a % b, a);
    T temp_y = x;
    x = (y - ((x * (b/a)) % MOD)) % MOD, y = temp_y % MOD;
    return x;
}

template<typename T>
T nCr(T n, T r){
    if(r == 1){
        return n % MOD;
    }
    r = r < n - r ? r : n - r;
    return (((n * nCr(n - 1 , r - 1)) % MOD) / r) % MOD;
}

int main(){
    

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n; cin >> n;
    vll a(n, 0), b(n, 0);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
    }

    ll num_div = 1, sum_div = 1, prod_div = 1;

    // Counting number of divisors
    rep(i, 0, n) num_div = (num_div * (1 + b[i])) % MOD; 

    // Finding product of all divisors
    ll temp_num_div = 1;
    rep(i, 0, n) temp_num_div = (temp_num_div * (1 + b[i])) % (MOD - 1); 

    ll temp_num = 1;
    rep(i, 0, n) temp_num = (temp_num * bin_exp(a[i], b[i])) % MOD;
    prod_div = bin_exp(temp_num, (temp_num_div/2) % (MOD - 1)) % MOD;
    
    
    // Finding sum of all divisors
    rep(i, 0, n) sum_div = (sum_div  * ((bin_exp(a[i], b[i] + 1) - 1) % MOD) * inv_mod((a[i] - 1), ll(MOD)) % MOD) % MOD;

    cout << num_div << " " << sum_div % MOD << " " << prod_div % MOD;
    return 0;
}
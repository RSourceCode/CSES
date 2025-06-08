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
}

ll gcd(ll a, ll b){
    if(a > b) swap(a, b);
    if(!a) return b;
    return gcd(b % a, a); 
}



int main(){
    

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    ll n; cin >> n;
    ll ans = 0;
    ll count = 0;
    for(ll i = 1; i * i <= n; i++){
        ll temp = ((n/i % MOD)*((n/i % MOD) + 1)/2  % MOD - (n/(i + 1) % MOD)*((n/(i + 1) % MOD) + 1)/2  % MOD) % MOD;
        ans = (ans + (temp *i) % MOD) % MOD;
        count = count + n/i - n/(i + 1);
    }

    for(ll i = 1; i <= n - count; i++){
        ans = (ans + (i*(n/i) % MOD)) % MOD;

    }
    // ans = (ans + (n*(n + 1)/2 - (n/2)*(n/2 + 1)/2) % MOD) % MOD;
    cout << ans;
    return 0;
}
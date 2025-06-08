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
    int n; cin >> n;
    rep(i, 0, n){
        int x; cin >> x;
        ll ans = 2;
        rep(j, 2, int(sqrt(x)) + 1) if(x % j == 0) ans+=2;
        if(sqrt(x) == double(int(sqrt(x)))) ans--;
        cout << ans << endl;
    }

    return 0;
}
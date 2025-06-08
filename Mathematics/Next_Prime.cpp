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
#include<chrono>

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
    return res % MOD;
}

ll gcd(ll a, ll b){
    if(a > b) swap(a, b);
    if(!a) return b;
    return gcd(b % a, a); 
}

bool Is_Prime(ll n){
    for(ll i = 2; i * i <= n; i++) if(n % i == 0) return false;
    return true;
}

int main(){
    FAST_IO;

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        while(!Is_Prime(++n)) if((n & 1)) n++;
        cout << n << endl;
    }

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}
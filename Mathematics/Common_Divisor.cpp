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
#include<array>

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


// int divisors[1000001];

int main(){
    

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n; cin >> n;
    int gcd = 1;
    // rep(i, 2, 1000001){
    //     divisors[i] = 0;
    // }
    vi divisors(1000001, 0);
    rep(i, 0, n){
        int x; cin >> x;
        for(int j = 2; j*j <= x; j++){
            if(x % j == 0){
                int a = x / j;
                if(divisors[j]){
                    if(gcd < j) gcd = j;
                }
                if(divisors[a]){
                    if(gcd < a) gcd = a;
                }
                divisors[j] = 1;
                divisors[a] = 1;
            }
        }
        if(divisors[x]){    
            if(gcd < x) gcd = x;
        }
        else{
            divisors[x] = 1;
        }
    }
    cout << gcd;
    return 0;
}
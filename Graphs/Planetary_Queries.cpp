#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
using namespace chrono;
int dp[200005][31];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> dp[i][0];
    }
    for(int j = 1; j < 31; j++){
        for(int i = 1; i <= n; i++){
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    for(int i = 0; i < q; i++){
        int x, k, y = 0;
        cin >> x >> k;
        while(k){
            if(k & 1)
                x = dp[x][y];
            k >>= 1;
            y++;
        }
        cout << x << endl;
    }

    #ifndef ONLINE_JUDGE
        cerr<<fixed<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif

    return 0;    
}

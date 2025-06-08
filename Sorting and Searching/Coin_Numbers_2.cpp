#include<iostream>
#include<vector> 
#include<algorithm>
#include<numeric>
#define MOD 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    vector<pair<int, int>> indx; 
    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
        indx.push_back({coins[i], i});
    }
    sort(indx.begin(), indx.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(indx[i + 1].second < indx[i].second) ans++;
        // cout << indx[i].second << " ";
    }
    // cout << endl;
    for(int i = 0; i < m; i++){

        int a, b; cin >> a >> b;
        int c = coins[a] - 1;
        int d = coins[b] - 1;
        // cout << c << " " << d << " ";

        if(c + 1 != d && d + 1 != c){
            if(c != 0 && indx[c - 1].second < indx[c].second && indx[c - 1].second > indx[d].second){ ans++; }
            else if(c != 0 && indx[c - 1].second > indx[c].second && indx[c - 1].second < indx[d].second){ ans--; }
            
            if(c != n - 1 && indx[c + 1].second < indx[c].second && indx[c + 1].second > indx[d].second){ ans--; }
            else if(c != n - 1 && indx[c + 1].second > indx[c].second && indx[c + 1].second < indx[d].second){ ans++; }
            
            
            if(d != 0 &&  indx[d - 1].second < indx[d].second && indx[d - 1].second > indx[c].second){ ans++; }
            else if(d != 0 &&  indx[d - 1].second > indx[d].second && indx[d - 1].second < indx[c].second){ ans--; }
            
            if(d != n - 1 &&  indx[d + 1].second < indx[d].second && indx[d + 1].second > indx[c].second){ ans--; }
            else if(d != n - 1 &&  indx[d + 1].second > indx[d].second && indx[d + 1].second < indx[c].second){ ans++; }
        }
        else{
            if(c + 1 != d) swap(c, d);
            // for(int i = 0; i < n; i++){
            //     cout << indx[i].second << " ";
            // }
            // // cout << c << " " << d;
            // cout << endl;
            if(c != 0 && indx[c - 1].second < indx[c].second && indx[c - 1].second > indx[d].second){ ans++; }
            else if(c != 0 && indx[c - 1].second > indx[c].second && indx[c - 1].second < indx[d].second){ ans--; }
           
            if(d != n - 1 && indx[d + 1].second < indx[d].second && indx[d + 1].second > indx[c].second){ ans--; }
            else if(d != n - 1 && indx[d + 1].second > indx[d].second && indx[d + 1].second < indx[c].second){ ans++; }

            if(indx[c].second < indx[d].second) ans++;
            else ans--;
        }
        pair<int, int> temp = indx[c];
        indx[c] = indx[d];
        indx[d] = temp;
        int temp1= coins[a];
        coins[a] = coins[b];
        coins[b] = temp1;
        cout << ans << endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    set<pair<int, int>> h;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        h.insert({-a, i});
    }
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        auto ans = h.lower_bound({-t, -1});
        if(ans == h.end()) cout << -1 << endl;
        else{
            cout << -(ans->first) << endl;
            h.erase(ans);
        } 
    }

    return 0;
}
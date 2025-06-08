#include<iostream>
#include<vector> 
#include<algorithm>
#include<set>
#define MOD 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n; cin >> n;
    set<pair<int, int>> arr;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        auto it = arr.lower_bound({a + 1, -1});
        if(it != arr.end()) arr.erase(it);
        arr.insert({a, i});
    }
    cout << arr.size();
    return 0;
}
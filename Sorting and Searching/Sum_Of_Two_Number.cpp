#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, x;
    cin >> n >> x;
    vector<pair<int ,int>> a;
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        a.push_back({b, i + 1});
    }
    sort(a.begin(), a.end());
    int p1 = 0, p2 = n - 1;
    while(p1 < p2){
        if(a[p1].first + a[p2].first == x){
            cout << a[p1].second << " " << a[p2].second;
            return 0;
        }
        else if(a[p1].first + a[p2].first < x){
            p1++;
        }
        else{
            p2 --;
        }
    }

    cout << "IMPOSSIBLE";
    
    return 0;
}
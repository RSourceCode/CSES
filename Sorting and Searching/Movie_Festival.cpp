#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(){
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        time[i] = {b, a};
    }
    sort(time.begin(), time.end());
    for(int i = 0; i < n; i++){
        // cout << time[i].second << ' ' << time[i].first << endl;
    }
    int s = 0, prev = 0, max_movies = 1;
    while(s < n && prev < n){
        if(time[prev].first > time[s].second){
            s++;
        }
        else{
            // cout << time[s].second << ' ' << time[f].first << endl;
            prev= s;
            max_movies++;
            // f++;
        }
    }
    cout << max_movies;
    return 0;
}
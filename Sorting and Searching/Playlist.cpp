#include<iostream>
#include<vector> 
#include<map>
#include<algorithm>
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
    map<int, int> list;
    int ans = 0, temp_ans = 0, start_idx = -1;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        // cout << start_idx << " ";
        if(list[a] > start_idx){
            start_idx = list[a];
            temp_ans = (i - list[a]);
            list[a] = i;
        }
        else{
            temp_ans++; 
            list[a] = i;
        }
        if(temp_ans > ans) ans = temp_ans;
    }
    cout << ans << endl;

    return 0;
}
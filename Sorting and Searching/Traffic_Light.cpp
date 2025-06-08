#include<iostream>
#include<vector> 
#include<algorithm>
#include<math.h>
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
    int x, n; cin >> x >> n;
    set<int> traffic_light;
    set<int> diff;
    diff.insert(x + 1);
    traffic_light.insert(-1);
    traffic_light.insert(x + 1);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        int temp_length;
        traffic_light.insert(a);
        auto b = traffic_light.find(a);
        advance(b, -1);
        temp_length = *b;
        diff.insert(a - *b - 1);
        cout << temp_length << " ";

        advance(b, 2);
        temp_length = *b - temp_length - 1;
        cout << temp_length << " ";
        diff.insert(*b - a - 1);

        diff.erase(temp_length);
        auto ans = diff.end();
        advance(ans, -1);
        // cout << *ans << " ";
        // for(auto ele : diff){
        //     cout << ele << " ";
        // }
        cout << endl;
    }

    return 0;
}
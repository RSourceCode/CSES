#include<iostream>
#include<vector> 
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
    int n;
    cin >> n;
    int curr_max_height = 0, curr_route_length = 1, longest_route_length = 1;
    for(int i = 0; i < n; i++){
        int h; cin >> h;
        if(i == 0){
            curr_max_height = h;
            continue;
        } 
        if(h < curr_max_height){
            curr_route_length++;
            if(longest_route_length < curr_route_length) longest_route_length = curr_route_length;
        }
        else{
            curr_max_height = h;
            curr_route_length = 1;
        }
    }
    cout << longest_route_length;
    return 0;
}
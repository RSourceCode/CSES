#include<iostream>
#include<vector> 
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long cost = 0;
    for(int i = 0; i < n; i++){
        cost += abs(arr[i] - arr[n / 2]);
    }
    cout << cost;
    return 0;
}
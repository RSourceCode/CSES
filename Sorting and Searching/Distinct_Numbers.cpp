#include<iostream>
#include<set>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    set<int> arr;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.emplace(a);
    }
    // for(auto i : arr){
    //     cout << i << " ";
    // }
    cout << arr.size();
    
    return 0;
}
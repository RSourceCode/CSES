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
    vector<int> start;
    vector<int> finish;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        start.push_back(a);
        finish.push_back(b);
    }
    ///sort the 2 arrays
    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());
    int s = 0, f = 0, num_cus = 0, max_num = 0;
    while(s < n && f < n){
        if(start[s] < finish[f]){
            num_cus++;
            // cout << start[s];
            if(max_num < num_cus){
                max_num = num_cus;
            }
            s++;
        }
        else{
            if(num_cus > 0)
                num_cus--;
            f++;
        }
    }
    cout << max_num;

    return 0;
}
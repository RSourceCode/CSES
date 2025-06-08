#include<iostream>
#include<vector>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int64_t> x;
    for(int i = 0; i < n; i++){
        int64_t a;
        cin >> a;
        x.push_back(a);
    }
    int64_t sum = 0, max_sum = 0, non_neg = INT_LEAST64_MIN;
    for(int i = 0; i < n;i++){
        sum += x[i];
        if(sum < 0){
            sum = 0;
        }
        if(sum > max_sum){
            max_sum = sum;
        }
        
        if(x[i] <= 0 && x[i] > non_neg){
            non_neg = x[i];   
        }
    }
    if(max_sum > 0){
        cout << max_sum;
    }
    else{
        cout << non_neg;
    }
    return 0;
}
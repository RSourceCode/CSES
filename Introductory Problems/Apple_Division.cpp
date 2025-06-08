#include<iostream>
#include<vector> 
#include<algorithm>
#include<math.h>
#include<limits.h>
#define MOD 1000000007

using namespace std;

long long min_diff = LLONG_MAX;

void Recur(long long& W1, long long& W2, int n, int i,  vector<int>& weights){
    if(i == n){
        if(min_diff > abs(W1 - W2)){
            min_diff = abs(W1 - W2);
        }
        // cout << W1 << " " << W2 << endl;
         return;
    }
    W1 += weights[i];
    Recur(W1, W2, n, i + 1, weights);
    W1 -= weights[i];
    W2 += weights[i];
    Recur(W1, W2, n, i + 1, weights);
    W2 -= weights[i];
    return;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    long long W1 = 0, W2 = 0;
    int i = 0;
    Recur(W1, W2, n, i, weights);
    
    cout << min_diff << endl;

    return 0;
}
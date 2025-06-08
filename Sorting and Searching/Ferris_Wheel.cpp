#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, x;
    cin >> n >> x;
    vector<int> w;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        w.push_back(a);
    }

    sort(w.begin(), w.end(), comp);

    int min_num = 0;

    int a = 1; 
    int i = 0;
    while(i <= n - a){
        if(i != n - a && w[i] + w[n - a] <= x){
            a++;
        }
        min_num++;
        i++;
    }
    cout << min_num;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a;
    vector<int> b;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        a.push_back(c);
    }
    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        b.push_back(c);
    }
    int num_app = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto a_itr = a.begin();
    auto b_itr = b.begin();

    while(a_itr != a.end() && b_itr != b.end()){
        // cout << *a_itr << " " << *b_itr << endl;

        if(*b_itr <= (*a_itr + k) && *b_itr >= (*a_itr - k)){
            num_app++;
            b_itr++;
            a_itr++;
        }
        else if(*b_itr > *a_itr + k){
            a_itr++;
        }
        else if(*b_itr < *a_itr - k){
            b_itr++;
        }
        // cout << *a_itr << " " << *b_itr << endl;
    }
    cout << num_app;
    return 0;
}
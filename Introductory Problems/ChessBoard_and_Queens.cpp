#include<iostream>
#include<vector> 
#include<algorithm>
#define MOD 1000000007

using namespace std;

long long num_ways = 0;

void Recur(int l, int n, vector<string> grid){
    if(l == n){
        num_ways++;
        return;
    }
    
    vector<string> _grid = grid;
    for(int j = 0; j < n; j++){
        if(grid[l][j] == '.'){
            _grid[l][j] = '*';
            for(int k = 0; k < n; k++){
                _grid[k][j] = '*';
                _grid[l][k] = '*';
                if(l + k < n && j + k < n) _grid[l + k][j + k] = '*';
                if(l - k >= 0 && j - k >= 0) _grid[l - k][j - k] = '*';
                if(l + k < n && j - k >= 0) _grid[l + k][j - k] = '*';
                if(l - k >= 0 && j + k < n) _grid[l - k][j + k] = '*';
            }
            Recur(l + 1, n, _grid);
            _grid = grid;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int n = 8;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    Recur(0, n, grid);
    cout << num_ways;

    return 0;
}
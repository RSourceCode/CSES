#include<iostream>
#include<vector> 
#include<algorithm>

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
    int num_moves = 0;
    while(n > 0){
        int max_dig = 0;
        int temp = n;                               
        while(temp > 0){
            int dig = temp % 10;
            if(dig > max_dig){
                max_dig = dig;
            }
            temp /= 10;
        }
        n -= max_dig;
        num_moves++;
    }
    cout << num_moves;
    return 0;
}
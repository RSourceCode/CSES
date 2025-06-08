#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long num_moves = 0;
    long long prev_num;
    cin >> prev_num;
    for(int i = 1; i < n; i++){
        long long temp;
        cin >> temp;
        if(temp < prev_num){
            num_moves += prev_num - temp;
        }
        else{
            prev_num = temp;
        }
    }
    cout << num_moves;
    return 0;
}
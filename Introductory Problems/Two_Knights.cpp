#include<iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        if(i == 1){
            cout << 0 << endl;
        }
        else if(i == 2){
            cout << 6 << endl;
        }
        else{
            cout << (i * i * ((i * i) - 1)) / 2 - (8 + 3 * 4 * 2 + 4 * 4 *(i - 4) + 4 * 4 + 6 * 4 * (i - 4) + 8 * (i - 4) * (i - 4)) / 2  << endl;
        }
    }
}
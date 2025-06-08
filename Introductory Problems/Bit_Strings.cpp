#include<iostream>
#define MOD (1000000000 + 7)
using namespace std;

int main(){
    int n;
    cin >> n;
    long long factor = 2;
    long long result = 1;

    while(n != 1){
        if(n % 2 != 0){
            result =(result * factor) % MOD;
            factor = (factor * factor) % MOD;
        }
        else{
            factor = (factor * factor) % MOD;
        }
        n = n/2;
    }
    result = (result * factor) % MOD;
    cout << result;
}
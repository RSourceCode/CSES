#include<iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    int num_zeros  = 0;
    while(n != 0){
        num_zeros += n / 5;
        n = n / 5;
    }
    cout << num_zeros;
    return 0;
}
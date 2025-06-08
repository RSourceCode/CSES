#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    unsigned long long missing_number = n;
    for(int i = 1; i < n; i++){
        long long temp;
        cin >> temp;
        missing_number = missing_number - temp + i;
    }
    cout << missing_number;

}
#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
    }
    else if(n == 2 || n == 3){
        cout << "NO SOLUTION";
    }
    else{
        int temp_n = n - 1;
        while(temp_n > 0){
            cout << temp_n << " ";
            temp_n -= 2;
        }
        temp_n = n;
        while(temp_n > 0){
            cout << temp_n << " ";
            temp_n -= 2;
        }
    }
}
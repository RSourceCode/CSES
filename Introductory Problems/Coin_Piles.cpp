#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long a, b;
        cin >> a >> b;
        if((a <= 1 && b <= 1) || a > 2 * b || b > 2 * a || (a + b) % 3 != 0){
            if(a == 0 && b == 0){
                cout << "YES"<< endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "YES"<< endl;
        }
    }
}
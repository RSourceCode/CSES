#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 4 == 1 || n % 4 == 2){
        cout <<"NO";
        return 0;
    }
    else{
        cout << "YES" << endl;
        if(n % 4 == 3){
            cout << n / 2 << endl;   
            for(int i = 1; i <= n / 4; i++){
                cout << i << " ";
            }
            for(int i = n - n/4; i <= n; i++){
                cout << i << " ";
            }
            cout << endl << n - n / 2 << endl;
            for(int i = n / 4 + 1; i < n - n / 4; i++){
                cout << i << " ";
            }
        }
        else{
            cout << n / 2 << endl;
            for(int i = 2; i <= n/2; i += 2){
                cout << i << " ";
            }   
            for(int i = n / 2 + 1; i < n; i += 2){
                cout << i << " ";
            }  

            cout << endl << n / 2 << endl;
            for(int i = 1; i < n/2; i += 2){
                cout << i << " ";
            }   
            for(int i = n / 2 + 2; i <= n; i += 2){
                cout << i << " ";
            }  
        }
    }
}
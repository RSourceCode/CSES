#include<iostream>
#include<vector> 
#include<algorithm>
#define MOD 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //Write your code Here.
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        if(a + b == 1 || a + b > n || a == n || b == n || (a == 0 && b != 0) || (b == 0 && a != 0)){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            if(a == 0 || b >= a){
                for(int i = a + b; i > 0; i--){
                    cout << i << " ";
                }
                for(int i = n; i > a + b; i--){
                    cout << i << " ";
                }
                cout << endl;
                for(int i = 1; i <= a; i++){
                    cout << i << " ";
                }
                for(int i = a + b; i > a; i--){
                    cout << i << " ";
                }
                for(int i = n; i > a + b; i--){
                    cout << i << " ";
                }
                cout << endl;
            }   
            else{
                for(int i = a + b; i > 0; i--){
                    cout << i << " ";
                }
                for(int i = n; i > a + b; i--){
                    cout << i << " ";
                }
                cout << endl;
                for(int i = 1; i < a; i++){
                    cout << i << " ";
                }
                for(int i = a + b; i >= a; i--){
                    cout << i << " ";
                }
                for(int i = n; i > a + b; i--){
                    cout << i << " ";
                }
                cout << endl;
            }   
        }
    }

    return 0;
}
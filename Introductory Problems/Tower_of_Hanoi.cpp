#include<iostream>
#include<math.h>

using namespace std;

void solver(int n, int l, int m, int r){
    if(n == 1){
        cout << l << " " << r << endl;
        return;
    }
    if(n == 2){
        cout << l << " " << m << endl;
        cout << l << " " << r << endl;
        cout << m << " " << r << endl;
    }
    else{
        solver(n - 1, l, r, m);
        cout << l << " " << r << endl;
        solver(n - 1, m, l, r);

    }
}

int main(){
    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1<< endl;
    solver(n, 1, 2, 3);
    return 0;
}
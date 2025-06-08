#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string arr[132000];
    arr[0] = "0";
    arr[1] = "1";
    int temp_pwr = 2;
    int arr_index = 2;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < temp_pwr; j++){
            arr[arr_index + j] = "0" + arr[arr_index - temp_pwr + j];
        }
        int tempo = 0;
        for(int j = temp_pwr - 1; j >= 0; j--){
            arr[arr_index + temp_pwr + tempo] = "1" + arr[arr_index - temp_pwr + j];
            tempo++;
        }
        temp_pwr*= 2;
        arr_index+= temp_pwr;
    }
    for(int i = arr_index - temp_pwr; i < arr_index; i++){
        cout<< arr[i] << endl;
    }
}
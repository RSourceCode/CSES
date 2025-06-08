#include<iostream>
#include<map>

using namespace std;

int main(){
    map<char, int> char_map;
    char char_array[26];
    int arr_len = 0;
    char temp;
    while(cin >> temp){
        if(char_map[temp] == 0){
            char_array[arr_len] = temp;
            arr_len++;
            char_map[temp] = 1;
        } 
        else{
            char_map[temp]++;
        }
    }
    // for(int i = 0; i < arr_len; i++){
    //     cout << char_map[char_array[i]] << " ";
    // }
    int odd_index_available = -1, odd_index = -1;

    for(int i = 0; i < arr_len; i++){
        if(char_map[char_array[i]] % 2 != 0){
            if(odd_index_available == -1){
                odd_index_available = 1;
                odd_index = i;
            }
            else{
                cout << "NO SOLUTION";
                return 0;
            }
        }
    }

    for(int i = 0; i < arr_len; i++){
        if(i != odd_index){
            for(int j = 0; j < char_map[char_array[i]] / 2; j++){
                cout << char_array[i];
            }
        }
    }
    if(odd_index_available){
        for(int j = 0; j < char_map[char_array[odd_index]]; j++){
            cout << char_array[odd_index];
        }
    }
    for(int i = arr_len - 1; i >= 0; i--){
       if(i != odd_index){
            for(int j = 0; j < char_map[char_array[i]] / 2; j++){
                cout << char_array[i];
            }
        }
    }
    return 0;
}
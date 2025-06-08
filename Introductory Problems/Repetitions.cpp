#include<iostream>

using namespace std;

int main(){
    int longest_len = 1;
    int temp_len = 1;
    char temp_char = 'Z';
    char temp;
    while(cin >> temp){
        if(temp != temp_char){
            temp_char = temp;
            temp_len = 1;
        }
        else{
            temp_len++;
            if(temp_len > longest_len){
                longest_len = temp_len;
            }
        }
    }
    cout << longest_len;
    return 0;   
}
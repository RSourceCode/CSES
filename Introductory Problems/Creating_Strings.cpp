#include<iostream>
#include<map>

using namespace std;

char word[9];
int word_len = 0;

void string_maker(char uniq_letters[26], int len_arr, map<char, int> letters_map, int len_word){
    for(int i = 0; i < len_arr; i++){
        if(letters_map[uniq_letters[i]] != 0){
            word[word_len] =  uniq_letters[i];
            word_len++;
            letters_map[uniq_letters[i]]--;
            if(word_len == len_word){
                for(int i = 0; i < len_word; i++){
                    cout<< word[i];;
                }
                cout << endl;
                word_len--;
                letters_map[uniq_letters[i]]++;
                return;
            }
            string_maker(uniq_letters, len_arr, letters_map, len_word);
    
            word_len--;
            letters_map[uniq_letters[i]]++;
        }
    }
}

int main(){
    char uniq_letters[26];
    int len_arr = 0;
    int len_word = 0;
    map <char, int> letters_map;
    char temp;
    
    while(cin >> temp){
        len_word++;
        if(letters_map[temp] == 0){
            uniq_letters[len_arr] = temp; 
            letters_map[temp]++;
            len_arr++;
        }
        else{
            letters_map[temp]++;
        }
        // cin >> temp;
    }
    int factorial_arr[10];
    factorial_arr[0] = 1;
    factorial_arr[1] = 1;
    for(int i = 2; i <= len_word; i++){
        factorial_arr[i] = factorial_arr[i - 1] * i;
    }
    int num_words = factorial_arr[len_word];

    for(int i = 0; i < len_arr; i++){
        num_words /= factorial_arr[letters_map[uniq_letters[i]]];
    }
    cout << num_words << endl;
    for(int i = 0; i < len_arr; i++){
        for(int j = i + 1; j < len_arr; j++){
            if(uniq_letters[i] > uniq_letters[j]){
                char temp = uniq_letters[i];
                uniq_letters[i] = uniq_letters[j];
                uniq_letters[j] = temp;
            }
        }
    }
    string_maker(uniq_letters, len_arr, letters_map, len_word);
    // for(int i = 0; i < len_arr; i++){
    //     cout << uniq_letters[i];
    // }

}
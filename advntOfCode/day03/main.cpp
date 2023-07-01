#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

const string file_name = "info.txt";

int priority(const string& line){

    unordered_map<char, int> alphabets_values;

    for(char c = 'a'; c <= 'z';c++){

        alphabets_values[c] = c - 'a' + 1;

    }

    for(char c = 'A'; c <= 'Z';c++){

        alphabets_values[c] = c - 'A' + 27;
    
    }

    int string_size = line.size();
    int half_string_size = string_size / 2;

    string first_half = line.substr(0, half_string_size);
    string second_half = line.substr(half_string_size, half_string_size);

    char key;

    for(char c : first_half){

        if(second_half.find(c) != string::npos){
            key = c;
        }

    }

    return alphabets_values[key];

}

char find_common_groups(const string rucksack1, const string rucksack2, const string rucksack3){

    char key;

    for(char c : rucksack1){
        if(rucksack2.find(c) != string::npos && rucksack3.find(c) != string::npos){
            key = c;
        }
    }

    return key;

}

int priority_groups(const vector<string>& rucksacks){

    int sum = 0;

    unordered_map<char, int> alphabets_values;

    for(char c = 'a'; c <= 'z';c++){

        alphabets_values[c] = c - 'a' + 1;

    }

    for(char c = 'A'; c <= 'Z';c++){

        alphabets_values[c] = c - 'A' + 27;
    
    }

    for(int i = 0; i < rucksacks.size(); i+=3){

        sum += alphabets_values[find_common_groups(rucksacks[i], rucksacks[i + 1], rucksacks[i + 2])]; 

    }

    return sum;

}


int main(){

    string line;
    ifstream file;
    int sum = 0;
    vector<string> rucksacks;

    file.open(file_name);

    if(file.is_open()){

        while(getline(file, line)){
        
            //cout << line << endl;
            rucksacks.push_back(line);
            sum += priority(line);

        }

        file.close();
    }


    //cout << sum << endl;

    cout << priority_groups(rucksacks) << endl;

    return 0;


}

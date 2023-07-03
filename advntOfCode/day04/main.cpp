#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Tenho que criar um vector de vector int para poder armazenar os intervalos de cada elfo, e depois percorrer esse vector inteiro comprarando todos os elementos para questao
using namespace std;

const string file_name = "info.txt";

vector<string> sections(const string& line){

    vector<string> result;

    size_t pos = line.find(",");

    string first_section = line.substr(0, pos);
    string second_section = line.substr(pos + 1);

    result.push_back(first_section);
    result.push_back(second_section);

    return result;

}

vector<int> intervals(const string& element){







}

int main(){

    ifstream file;
    string line;
    vector<string> data;
    vector<vector<int>> new_data;


    file.open(file_name);

    if(file.is_open()){

        while(getline(file, line)){

            size_t pos = line.find(",");

            string first_section = line.substr(0, pos);
            string second_section = line.substr(pos + 1);

            data.push_back(first_section);
            data.push_back(second_section);

        }

        file.close();

    }

    for(string element : data){
        cout << element << endl;
    }

    
    return 0;
}

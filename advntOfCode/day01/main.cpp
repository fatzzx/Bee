#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {


	ifstream file;
	string line;
	int number;
	int sum = 0;
	vector<int> aux;

	file.open("info.txt");
    
	if(file.is_open()){
		
		while(getline(file, line)){
			try{
				number = stoi(line);
				sum += number;
			} catch(const invalid_argument& e){
				aux.push_back(sum);
				sum = 0;
			}
		}
		aux.push_back(sum);
	}

	file.close();


	sort(aux.rbegin(), aux.rend());

	cout << aux[0] << endl;
	cout << aux[1] << endl;
	cout << aux[2] << endl;
	cout << (aux[2] + aux[1] + aux[0]) << endl;



	return 0;
}

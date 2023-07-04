#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases;
	cin >> cases;
	cin.ignore();
	string inpt;
	vector<string> strs;

	for(int i = 0; i < cases; i++){

		getline(cin, inpt);

		for(char& c : inpt){
			if((c > 96 && c < 123) || (c > 64 && c < 91)){
				c = c + 3;
			}
		}


		reverse(inpt.begin(), inpt.end());


		for(int j = inpt.length()/2; j < inpt.length(); j++){
			inpt[j] -= 1;
		}


		strs.push_back(inpt);

	}


	for(string s : strs){
		cout << s << endl;
	}

	return 0;
}

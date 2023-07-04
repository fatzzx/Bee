#include <bits/stdc++.h>

using namespace std;

int main(){

	string eq;

	while(cin >> eq){
		string a = eq.substr(0, eq.find('+'));
		string b = eq.substr(eq.find('+') + 1, eq.find('=') - (a.length() + 1));
		string c = eq.substr(eq.find('=') + 1, eq.length() - ((a.length() + b.length()) + 2));
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		reverse(c.begin(), c.end());
		if(stoi(a) + stoi(b) == stoi(c)) cout << "True" << endl;
		else cout << "False" << endl;
		if(eq == "0+0=0") break;

	}


	return 0;
}
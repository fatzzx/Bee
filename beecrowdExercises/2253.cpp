#include <bits/stdc++.h>

using namespace std;

int main(){

	string passwd;

	while(getline(cin, passwd)){

		bool is_valid = true;
		bool aux = false;
		bool rqmnts[3] = {false, false, false}; 

		if(passwd.length() < 6 || passwd.length() > 32){
			is_valid = false;
			cout << "Senha invalida." << endl;
			continue;
		}

        for (char c : passwd) {
            if (c >= '0' && c <= '9') rqmnts[0] = true;
            if (c >= 'a' && c <= 'z') rqmnts[1] = true;
            if (c >= 'A' && c <= 'Z') rqmnts[2] = true;
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
                is_valid = false;
                aux = true;
                cout << "Senha invalida." << endl;
                break;
            }
        }

        if(aux) continue;

		if(!(rqmnts[0] && rqmnts[1] && rqmnts[2])){
			is_valid = false;
			cout << "Senha invalida." << endl;
			continue;
		}

		if(is_valid) cout << "Senha valida." << endl;

	}

	return 0;

}
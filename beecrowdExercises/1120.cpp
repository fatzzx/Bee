#include <bits/stdc++.h>

using namespace std;

int main() {
    string ri;
    string itm;

    while (cin >> ri && cin >> itm) {

        if(ri == "0" && itm == "0") continue;

        size_t pos = itm.find(ri);

        while (pos != string::npos) {
            itm.erase(pos, 1);
            pos = itm.find(ri, pos);
        }

        for(int i = 0; i < itm.length();i++){
            if(itm[i] == '0'){
                itm.erase(i, 1);
                i--;
            } 
            else break;   
        }

        if(itm.empty()) cout << "0" << endl;
        else cout << itm << endl;
    }

    return 0;
}

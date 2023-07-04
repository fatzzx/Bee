#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    string one;
    string two;
    while(getline(cin, one) && getline(cin, two)){
        if(one.length() < two.length()){
            cout << "nao encaixa" << endl;
            continue;
        }
        int oneLength = one.length();
        int twoLength = two.length();
        int index = oneLength - twoLength;
        string piece = one.substr(index);
        if(piece == two)
            cout << "encaixa" << endl;
        else
            cout << "nao encaixa" << endl;
    }

    return 0;
}

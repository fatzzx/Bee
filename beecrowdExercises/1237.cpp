#include <iostream>
#include <string>

using namespace std;

int main() {
    string one;
    string two;

    while (getline(cin, one) && getline(cin, two)) {
        int cont = 0;

        for (int i = 0; i < one.length(); i++) {
            for (int j = 0; j < two.length(); j++) {
                int len = 0;
                int k = i;
                int l = j;

                while (k < one.length() && l < two.length() && one[k] == two[l]) {
                    len++;
                    k++;
                    l++;
                }

                cont = max(cont, len);
            }
        }

        cout << cont << endl;
    }

    return 0;
}

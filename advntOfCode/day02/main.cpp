#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ifstream file("info.txt");
    string line;
    int sum = 0;

    unordered_map<string, int> scoreMap = {
        {"A X", 4}, {"A Y", 8}, {"A Z", 3},
        {"B X", 1}, {"B Y", 5}, {"B Z", 9},
        {"C X", 7}, {"C Y", 2}, {"C Z", 6}
    };

    unordered_map<string, int> scoreMapQ2 = {
        {"A X", 3}, {"A Y", 4}, {"A Z", 8},
        {"B X", 1}, {"B Y", 5}, {"B Z", 9},
        {"C X", 2}, {"C Y", 6}, {"C Z", 7}
    };

    if (file.is_open()) {
        while (getline(file, line)) {
            if (scoreMapQ2.count(line)) {
                sum += scoreMapQ2[line];
            }
        }
        file.close();
        cout <<  sum << endl;
    } 

    return 0;
}

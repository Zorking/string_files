#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;


void create_file(string data) {
    ofstream newfile;
    newfile.open("qwerty.txt");
    newfile << data;
    newfile.close();
}

void read_file() {
    string all_strings;
    string line;
    ifstream file("qwerty.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            line = line;
            string word;
            istringstream iss(line, ios_base::in);
            vector<string> wordsVector;
            while (iss >> word) {
                wordsVector.push_back(word);
                if (word.find_last_of(word[0]) > 0) {
                    all_strings.append(word + " ");
                }
            }
            reverse(begin(wordsVector), end(wordsVector));
        }
        file.close();
    } else cout << "Unable to open file";
}

int main() {
    int is_correct;
    string answer, data;
    cout << "File is ready: Yes or No?\n";
    is_correct = 0;
    while (is_correct == 0) {
        cin >> answer;
        if (answer == "No") {
            cout << "Enter some data to file\n";
            cin >> data;
            create_file(data);
        } else if (answer != "Yes") {
            cout << "Yes or No?\n";
            continue;
        }
        is_correct = 1;
    };
    read_file();
    return 0;
}


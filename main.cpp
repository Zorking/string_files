#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


void create_file() {
    int is_correct;
    string answer;
    ofstream newfile;
    cout << "File is ready: Yes or No?\n";
    is_correct = 0;
    while (is_correct == 0) {
        cin >> answer;
        if (answer == "No") {
            newfile.open("qwerty.txt");
            newfile << answer;
        } else if (answer != "Yes") {
            cout << "Yes or No?\n";
            continue;
        }
        is_correct = 1;
    }
    newfile.close();
}

void read_file() {
    string all_strings;
    string line;
    ifstream file("qwerty.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            line = line;
            all_strings.append(line);
            string word;
            istringstream iss(line, ios_base::in);
            vector<string> wordsVector;
            while (iss >> word) {
                wordsVector.push_back(word);
                if (word.find_last_of(word[0]) > 0) {
                    cout << word + "\n";
                }
            }
            reverse(begin(wordsVector), end(wordsVector));
        }
        cout << all_strings;
        file.close();
    } else cout << "Unable to open file";
}

int main() {
    create_file();
    read_file();
    return 0;
}


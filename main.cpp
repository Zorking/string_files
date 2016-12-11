#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
string SOURCE_FILE_NAME = "source.txt", EDITED_FILE_NAME = "edited.txt";

void write_file(string data, string file_name) {
    ofstream new_file;
    new_file.open(file_name);
    new_file << data;
    new_file.close();
}

void read_file() {
    string all_strings, line;
    ifstream file("source.txt");
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
        write_file(all_strings, EDITED_FILE_NAME);
        cout << "Output: " + all_strings;
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
            while (data == "") {
                getline(cin, data);
            }
            write_file(data, SOURCE_FILE_NAME);
        } else if (answer != "Yes") {
            cout << "Yes or No?\n";
            continue;
        }
        is_correct = 1;
    };
    read_file();
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
    //create
    int is_correct;
    string answer;
    //read
    string all_strings;
    string line;
    //read
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
    //create
    ifstream file("qwerty.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            line = line;
            all_strings.append(line);
            std::string word;
            std::istringstream iss(line, std::istringstream::in);
            std::vector<std::string> wordsVector;
            while (iss >> word) {
                wordsVector.push_back(word);
                size_t qwerty = word.find_last_of(word[0]);
                if (word.find_last_of(word[0]) > 0) {
                    cout << word + "\n";
                }
            }
            std::reverse(begin(wordsVector), end(wordsVector));
        }
        cout << all_strings;
        file.close();
    } else cout << "Unable to open file";

    return 0;
}


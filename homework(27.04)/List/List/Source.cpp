#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cout << "Enter a text consisting of words separated by spaces and ending with a period: "<<endl;
    getline(cin, input); 

    list<string> words; 
    list<string> digits; 

    size_t start = 0;
    size_t end = input.find(' ');
    while (end != string::npos) {
        string word = input.substr(start, end - start);
        words.push_back(word); 
        start = end + 1;
        end = input.find(' ', start);
    }
    string lastWord = input.substr(start); 
    words.push_back(lastWord); 

    for (auto it = words.begin(); it != words.end();) {
        bool isDigit = true;
        for (char c : *it) {
            if (!isdigit(c)) {
                isDigit = false;
                break;
            }
        }
        if (isDigit) {
            digits.push_back(*it); 
            it = words.erase(it); 
        }
        else {
            ++it;
        }
    }

    digits.sort();

    digits.unique();

    cout << "Words with digits: ";
    for (const auto& digit : digits) {
        cout << digit << " ";
    }
    cout << endl;

    cout << "Words: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}


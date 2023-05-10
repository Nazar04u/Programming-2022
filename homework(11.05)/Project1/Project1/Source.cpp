#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getLargestPositionOverall(const map<char, vector<int>>& lettersMap) {
    int largestPosition = -1;

    for (const auto& entry : lettersMap) {
        const vector<int>& positions = entry.second;
        if (!positions.empty()) {
            int maxPosition = *max_element(positions.begin(), positions.end());
            largestPosition = max(largestPosition, maxPosition);
        }
    }

    return largestPosition;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile1("output1.txt");
    ofstream outputFile2("output2.txt");

    if (!inputFile.is_open()) {
        cout << "Error!" << endl;
        return 1;
    }

    map<char, vector<int>> lettersMap;

    char letter;
    int position;
    while (inputFile >> letter >> position) {
        lettersMap[letter].push_back(position);
    }

    inputFile.close();

    vector<pair<char, int>> lettersArray;

    for (const auto& entry : lettersMap) {
        for (int i = 0; i < entry.second.size(); i++) {
            lettersArray.push_back(make_pair(entry.first, entry.second[i]));
        }
        
    }
    
    for (const auto& entry : lettersMap) {
        outputFile1 << entry.first << ": " << entry.second.size() << endl;
    }

    for (const auto& entry : lettersArray) {
        outputFile2.seekp(entry.second);
        outputFile2.put(entry.first);
    }
    outputFile1.close();
    outputFile2.close();

    return 0;
}
